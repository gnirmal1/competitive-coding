#include "bits/stdc++.h"
using namespace std;

int dp[41][1001];
void solve(){
    int m;
    cin >> m;
    vector<int> d(m);
    int sum = 0;
    for(int i = 0; i < m; ++i){
        cin >> d[i];
        sum += d[i];
    }
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for(int i = 1; i <= m; ++i){
        for(int h = 0; h <= sum; ++h){
            if(h >= d[i - 1] && dp[i - 1][h - d[i - 1]] != -1){
                dp[i][h] = max(h, dp[i - 1][h - d[i - 1]]);
            }
            if(dp[i - 1][h + d[i - 1]] != -1){
                if(dp[i][h] == -1) dp[i][h] = 1e9;
                dp[i][h] = min(dp[i][h], max(h, dp[i - 1][h + d[i - 1]]));
            }
        }
    }
    if(dp[m][0] == -1){
        cout << "IMPOSSIBLE\n";
        return;
    }
    string res = "";
    int curr = 0;
    for(int i = m; i >= 1; --i){
        if(curr >= d[i - 1] && 
        dp[i][curr] == max(curr, dp[i - 1][curr - d[i - 1]])){
            res += 'U';
            curr -= d[i - 1];
        }
        else{
            res += 'D';
            curr += d[i - 1];
        }
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
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