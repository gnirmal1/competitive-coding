#include "bits/stdc++.h"
using namespace std;

int dr[] = { 1, 0, -1, 0};            
int dc[] = { 0, 1, 0, -1};
int grid[1001][1001], r, c, clk1 = 2, clk2 = -1;

void dfs(int i, int j, int x, int clk){
    grid[i][j] = clk;
    for(int d = 0; d < 4; ++d){
        int i1 = i + dr[d], j1 = j + dc[d];
        if(i1 < 0 || j1 < 0) continue;
        if(i1 >= r || j1 >= c) continue;
        if(grid[i1][j1] == x) dfs(i1, j1, x, clk);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 
    memset(grid, 0, sizeof grid);
    cin >> r >> c;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            char x;
            cin >> x;
            grid[i][j] = x - '0';
        }
    }

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(grid[i][j] == 1) dfs(i, j, 1, clk1++);
            else if(grid[i][j] == 0) dfs(i, j, 0, clk2--);
        }
    }

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if(grid[--r1][--c1] == grid[--r2][--c2] && grid[r1][c1] < 0) cout << "binary\n";
        else if (grid[r1][c1] == grid[r2][c2]) cout << "decimal\n";
        else cout << "neither\n";
    }
}
