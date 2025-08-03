# include <bits/stdc++.h>
# define ll long long 
# define fi first
# define se second
# define mp make_pair
# define pii pair<int, int>
# define vi vector<int>
# define endl '\n';
# define fastio ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

struct seg_tree{
    int sz;
    vector<ll> data;
    vector<ll> st;

    seg_tree(vector<ll> vec): sz(vec.size()){
        data.resize(sz);
        data = vec;
        st.resize((sz+1) << 2);
        build(1, 1, sz);
    }

    void build(int idx, int l, int r){ // [l, r], 1-based
        if(l > r) return;
        if(l == r){
            st[idx] = data[l-1];
            return;
        }else{
            int mid = (l+r) >> 1;
            build(idx<<1, l, mid);
            build((idx<<1)+1, mid+1, r);
            st[idx] = min(st[idx<<1], st[(idx<<1)+1]);
        }
    }

    void fix(int now, int l, int r, const int node, const ll val){
        if(l > r) return;
        if(l == r){
            st[now] = val;
        }else{
            int mid = (l+r) >> 1;
            if(node <= mid){
                fix(now<<1, l, mid, node, val);
            }else{
                fix((now<<1)+1, mid+1, r, node ,val);
            }
            st[now] = min(st[now<<1], st[(now<<1)+1]);
        }
    }

    ll ask(int now, int start, int end, int l, int r){
        if(l > end || start > r || l > r || start > end) return (ll) (1e9+1);
        if(l <= start && end <= r){
            // cout << start << end << endl
            return st[now];
        } 
        else{
            int mid = (start + end) >> 1;
            return min(ask(now<<1, start, mid, l, r), ask((now<<1) + 1, mid+1, end, l, r));
        }
        return (ll) (1e9+1);
    }
};

int main(){
    fastio;
    int n, q; cin >> n >> q;
    vector<ll> v(n);
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }

    seg_tree st(v);

    // for(auto i: st.st) cout << i << endl;

    while(q--){
        int mode;
        ll a, b;
        cin >> mode >> a >> b;
        if(mode == 1) st.fix(1, 1, st.sz, a, b);
        else cout << st.ask(1, 1, st.sz, a, b) << endl;
    }
}
