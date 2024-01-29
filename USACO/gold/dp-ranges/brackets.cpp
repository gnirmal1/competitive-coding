#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    vector<vector<int>> dp(n, vector<int> (n));
    for(int l = 2; l <= n; ++l){
        for(int i = 0; i + l <= n; ++i){
            int j = i + l - 1;
            if(b[i] + x == b[j]) dp[i][j] = max(dp[i][j], v[i] + v[j] + dp[i + 1][j - 1]);
            for(int k = i; k < j; ++k){
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
	return 0;
}
