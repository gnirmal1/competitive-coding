#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll dp[1000001], p, r;

ll recurse(int i){
    ll &ans = dp[i];
    if(ans != -1) return ans;
    ans = 1e18;
    for(int j = 2; j*j <= i; ++j){ // there are O(root(n)) distinct values of ceil(n/i) for i = 1 to n
        ll x = p*(j - 1), y = (i + j - 1) / j;
        if(x < ans) ans = min(recurse(y) + x, ans);
        x = p*(y - 1);
        if(x < ans) ans = min(recurse((i + y - 1) / y) + x, ans);
    }
    ans = min(ans, p*(i - 1));
    return ans += r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    ll n;
    cin >> n >> r >> p;
    memset(dp, -1, sizeof dp);
    dp[0] = dp[1] = 0;
    cout << recurse(n) << '\n';
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 