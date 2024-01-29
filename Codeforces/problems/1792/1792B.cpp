#include "bits/stdc++.h"
using namespace std;

int solve(){
    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;
    if(!a1 && (a2 || a3 || a4)) return 1;
    else if(!a1) return 0;
    int ans = a1;
    if(a1 + a3 >= a2 && a1 + a2 >= a3){
        int x = min(a1 - a2 + a3, a1 + a2 - a3);
        ans += a2 + a3 + min(a4, x);
        if(a4 > x) ans++;
    }
    else{
        ans += 2*min(a2, a3) + a1 + 1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int t;
    cin >> t;
    while(t--){
        cout << solve() << '\n';
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 