#include "bits/stdc++.h"
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int ans = (k)^(k >> 1);
        cout << ans << '\n';
    }
}