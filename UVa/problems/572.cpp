#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvpii = vector<vpii>;


int m, n;
int dr[] = { 1, 1, 0,-1,-1,-1, 0, 1};            
int dc[] = { 0, 1, 1, 1, 0,-1,-1,-1};
vector<string> grid;

void dfs(int i, int j){
    grid[i][j] = '.';
    for(int d = 0; d < 8; ++d){
        int i1 = i + dr[d], j1 = j + dc[d];
        if(i1 < 0 || j1 < 0) continue;
        if(i1 >= m || j1 >= n) continue;
        if(grid[i1][j1] == '@') dfs(i1, j1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    while(true){
        cin >> m >> n;
        if(m == 0) break;
        grid.assign(m, "");
        for(int i = 0; i < m; ++i){
            cin >> grid[i];
        }
        int ans = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '*') continue;
                if(grid[i][j] == '@'){
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 