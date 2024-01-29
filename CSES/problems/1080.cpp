#include "bits/stdc++.h"
using namespace std;

using ll = long long;

constexpr ll INF = 1e9;
constexpr int MOD = 1e9 + 7;

void solve(){
    string str;
    cin >> str;
    int n = str.length();
    ll dp[n][n], C[n][n];
    memset(dp, 0, sizeof dp);
    memset(C, 0, sizeof C);
    C[0][0] = 1;
    for(int i = 1; i < n; ++i){
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
    for(int i = 0; i < n - 1; ++i) dp[i + 1][i] = 1;
    for(int l = 2; l <= n; l += 2){
        for(int i = 0; i + l <= n; ++i){
            int j = i + l - 1;
            dp[i][j] = dp[i + 1][j - 1] * (str[i] == str[j]);
            for(int k = i + 1; k < j; k += 2){
                if(str[i] == str[k]){
                    ll temp = (dp[i + 1][k - 1]*dp[k + 1][j]) % MOD;
                    temp = (temp*C[l/2][(k - i + 1)/2]) % MOD;
                    dp[i][j] += temp;
                    dp[i][j] %= MOD;
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    solve();
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 