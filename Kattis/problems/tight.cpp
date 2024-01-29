#include "bits/stdc++.h"
using namespace std;

void solve(int k){
    int n;
    cin >> n;
    vector<vector<double>> dp(101, vector<double> (10, 1.0));
    for(int i = 2; i <= n; ++i){
        for(int j = 0; j <= k; ++j){
            dp[i][j] = dp[i - 1][j];
            if(j > 0) dp[i][j] += dp[i - 1][j - 1];
            if(j < k) dp[i][j] += dp[i - 1][j + 1];
        }
    }
    double percentage = 0;
    for(int i = 0; i <= k; ++i) percentage += dp[n][i];
    cout << percentage << '\n';
    for(int i = 0; i < n; ++i) percentage /= (k + 1.0);
    cout << percentage*100.0 << '\n';
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(7) << fixed;
    // IO(""); 

    int k;
    while(cin >> k){
        solve(k);
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 