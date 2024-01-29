#include "bits/stdc++.h"
using namespace std;

int dr[] = { 1, 0, -1, 0};            
int dc[] = { 0, 1, 0, -1};
int grid[21][21], m, n, coord_x, coord_y, sz, flag;

void dfs(int i, int j){
    grid[i][j] = 2;
    sz++;
    if(i == coord_x && j == coord_y) flag = 0;
    for(int d = 0; d < 4; ++d){
        int i1 = i + dr[d], j1 = (j + dc[d] + n) % n;
        if(i1 < 0 || i1 >= m) continue;
        if(grid[i1][j1] == 1) dfs(i1, j1);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 
    while(cin >> m >> n){
        memset(grid, 0, sizeof grid);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                char x;
                cin >> x;
                grid[i][j] = x;
            }
        }
        int ans = 0;
        cin >> coord_x >> coord_y;
        int targ = grid[coord_x][coord_y];
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == targ) grid[i][j] = 1;
                else grid[i][j] = 0;
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    sz = 0, flag = 1;
                    dfs(i, j);
                    if(flag) ans = max(ans, sz);
                }
            }
        }
        cout << ans << '\n';
    }
}
