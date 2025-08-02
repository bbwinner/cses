# include <bits/stdc++.h>
# define ll long long 
# define fi first
# define se second
# define mp make_pair
# define pii pair<int, int>
# define fastio ios_base::sync_with_stdio(0); cin.tie(0)

using namespace std;

struct sparse_table{
    ll sz;
    vector<vector<ll>> sp;

    sparse_table(vector<ll> vec): sz(vec.size()){
        sp.resize(18, vector<ll>(sz));
        for(int i=0; i<sz; ++i) sp[0][i] = vec[i];

        for(int i=1; i<18; ++i){
            for(int j=0; j+(1LL<<i)-1 < sz; ++j){
                sp[i][j] = min(sp[i-1][j], sp[i-1][j + (1LL<<i-1)]);
            }
        }
    }

    ll ask(ll l, ll r){ // [l, r)
        return min(sp[__lg(r-l)][l], sp[__lg(r-l)][r-(1<<(__lg(r-l)))]);
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    fastio;

    vector<ll> x(n);
    for(int i=0; i<n; ++i){
        cin >> x[i];
    }
    sparse_table sp(x);

    while(m--){
        int a, b;
        cin >> a >> b;
        cout << sp.ask(a-1, b) << endl;
    }
}
