#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vll = vector<ll>;
constexpr ll INF = 1e9;
constexpr int MOD = 1e9 + 7;

ll solve(){
    int n;
    cin >> n;
    int sum = n*(n + 1)/2;
    if(sum % 2 == 1) return 0;
    int W = sum/2;
    vll dp(W + 1);
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        for(int j = W; j >= i; --j){
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }   
    return dp[W];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    cout << solve() << '\n';
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 