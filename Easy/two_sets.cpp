# include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    if(n % 4 == 1 || n % 4 == 2){
        cout << "NO\n";
    }else if(n % 4 == 3){
        cout << "YES\n";
        cout << (n+1) / 2 << '\n';
        cout << "1 2 ";
        for(int i=0; i<(n-3)/4; i++){
            cout << (n-i) << ' ' << (i+4) << ' ';
        }
        cout << '\n';

        cout << (n-1) / 2 << '\n';
        cout << "3 ";
        for(int i=(n-3)/4; i<(n-3)/2; ++i){
            cout << (n-i) << ' ' << (i+4) << ' ';
        }
        cout << '\n';
    }else{
        cout << "YES\n";
        cout << n / 2 << '\n';
        for(int i=0; i<n/4; i++){
            cout << (n-i) << ' ' << (i+1) << ' ';
        }
        cout << '\n';
        
        cout << n / 2 << '\n';
        for(int i=n/4; i<n/2; i++){
            cout << (n-i) << ' ' << (i+1) << ' ';
        }
        cout << '\n';
    }
}
