#include "bits/stdc++.h"
using namespace std;


int solve(){
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int> (n));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                char c;
                cin >> c;
                grid[i][j] = c - '0';
            }
        }
        int ans = 0;
        for(int i = 0; i < n/2; ++i){
            for(int j = 0; j < n/2; ++j){
                int cnt = grid[i][j] + grid[j][n - 1 - i] + grid[n - 1 - j][i] + grid[n - 1 - i][n - 1 - j];
                ans += min(cnt, 4 - cnt);
            }
        }
        if(n&1){
            int j = n/2;
            for(int i = 0; i <= n/2; ++i){
                int cnt = grid[i][j] + grid[j][n - 1 - i] + grid[n - 1 - j][i] + grid[n - 1 - i][n - 1 - j];
                ans += min(cnt, 4 - cnt);
            }
        }
        cout << ans << '\n';
    }
}
