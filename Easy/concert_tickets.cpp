# include <bits/stdc++.h>
# define ll long long
# define endl '\n'
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    multiset<ll> mst;

    for(int i=0; i<n; ++i){
        ll price; cin >> price;
        mst.insert(price);
    }

    while(m--){
        ll pay; cin >> pay;
        auto itr = mst.upper_bound(pay);
        if(itr == mst.begin()) cout << -1 << endl;
        else{
            itr--;
            cout << *itr << endl;
            mst.erase(itr);
        }
    }
}
