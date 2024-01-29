#include "bits/stdc++.h"
using namespace std;

int h, w, holes;
int dr[] = { 1, 0, -1, 0};            
int dc[] = { 0, 1, 0, -1};
int grid[201][201], temp[201][201];

char get_heiroglyph()
{
    switch(holes)
    {
        case 0: return 'W';
        case 1: return 'A';
        case 2: return 'K';
        case 3: return 'J';
        case 4: return 'S';
    }
    return 'D';
}


void dfs(int i, int j, int c, bool flag){
    temp[i][j] = 2;
    if(flag) grid[i][j] = 2;
    for(int d = 0; d < 4; ++d){
        int i1 = i + dr[d], j1 = j + dc[d];
        if(i1 < 0 || j1 < 0) continue;
        if(i1 >= h || j1 >= 4*w) continue;
        if(flag && grid[i1][j1] == c) dfs(i1, j1, c, flag);
        else if(temp[i1][j1] == c) dfs(i1, j1, c, flag);
    }
}

void calc_holes(){
    for(int j = 0; j < 4*w; ++j){
        if(temp[0][j] == 0) dfs(0, j, 0, 0);
        if(temp[h - 1][j] == 0) dfs(h - 1, j, 0, 0);
    }
    for(int i = 0; i < h; ++i){
        if(temp[i][0] == 0) dfs(i, 0, 0, 0);
        if(temp[i][4*w - 1] == 0) dfs(i, 4*w - 1, 0, 0);
    } // flood fill background Zeroes

    holes = 0;
    for(int i = 1; i < h - 1; ++i){
        for(int j = 1; j < 4*w - 1; ++j){
            if(temp[i][j] == 0){
                dfs(i, j, 0, 0);
                holes++;
            }
        }   
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int linecnt = 0;
    while(true){
        cin >> h >> w;
        if(h == 0 && w == 0) break;
        memset(grid, 0, sizeof grid);
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < 4*w; j += 4){
                char c;
                cin >> c;
                int bin;
                if(isdigit(c)) bin = c - '0';
                else bin = c - 'a' + 10;
                for(int k = 3; k >= 0; --k){
                    grid[i][j + 3 - k] = (bin >> k) & 1;
                }
            }
        }

        string ans = "";
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < 4*w; ++j){
                if(grid[i][j] == 1){
                    memset(temp, 0, sizeof temp);
                    dfs(i, j, 1, 1);
                    calc_holes();
                    ans += get_heiroglyph();
                }
            }
        }
        sort(ans.begin(), ans.end());
        cout << "Case " << ++linecnt << ": " << ans << '\n';
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 