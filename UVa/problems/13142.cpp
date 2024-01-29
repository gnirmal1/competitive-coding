#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve(){
    ll t, s, d;
    cin >> t >> s >> d;
    ll ans = (d*1000000)/(t*86400);
    if(abs(d) == d && ans != 0) printf("Remove %lld tons\n", ans);
    else printf("Add %lld tons\n", abs(ans));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 