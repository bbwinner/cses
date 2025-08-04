# include <bits/stdc++.h>
# define fastio ios_base::sync_with_stdio(0); cin.tie(0)
# define ll long long
using namespace std;

struct segment_tree{
    int sz;
    vector<ll> data; // 0-based
    vector<ll> tree; //1-based

    segment_tree(vector<ll> v): sz(v.size()){
        data.resize(sz);
        data = v;
        tree.resize(sz << 2);
        build(1, 1, sz);
    }

    void build(int idx, int l, int r){
        if(l > r) return;
        if(l == r) tree[idx] = data[l-1];
        else{
            int mid = (l+r) >> 1;
            build(idx<<1, l, mid);
            build((idx<<1)+1, mid+1, r);
            tree[idx] = tree[idx<<1] + tree[(idx<<1)+1];
        }
    }

    ll fix(int idx, int l, int r, const int node, const int val){
        if(l > r) return 0;
        if(l == r){
            ll f = val - tree[idx];
            tree[idx] = val;
            return f;
        }else{
            int mid = (l+r) >> 1;
            ll f = 0;
            if(node <= mid){
                f = fix(idx << 1, l, mid, node, val);
            }else{
                f = fix((idx<<1) + 1, mid+1, r, node, val);
            }
            tree[idx] += f;
            return f;
        }
    }

    ll ask(int idx, int start, int end, int l, int r){
        if(r < start || end < l || l > r || start > end) return 0;
        if(l == start && r == end) return tree[idx];
        else{
            int mid = (start+end) >> 1;
            ll left=0, right=0;
            if(r <= mid){
                left = ask(idx<<1, start, mid, l, r);
            }else if (l > mid){
                right = ask((idx<<1) + 1, mid+1, end, l, r);
            }else{
                left = ask(idx<<1, start, mid, l, mid);
                right = ask((idx<<1) + 1, mid+1, end, mid+1, r);
            }
            return left + right;
        }
    }
};

int main(){
    fastio;
    int n, q;
    cin >> n >> q;

    vector<ll> vec(n);
    for(int i=0; i<n; ++i) cin >> vec[i];

    segment_tree st(vec);

    // for(auto i: st.tree) cout << i << endl;

    while(q--){
        int mode;
        ll a, b;
        cin >> mode >> a >> b;
        if(mode == 1){
            st.fix(1, 1, st.sz, a, b);
        }else{
            cout << st.ask(1, 1, st.sz, a, b) << endl;
        }
    }
}
