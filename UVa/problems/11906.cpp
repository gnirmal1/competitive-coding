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


int r, c, m, n;
vvi AL;
vi dir_x = {1, 1, -1, -1},
   dir_y = {1, -1, 1, -1};
vector<bool> vis;
int eve, odd;

int getInd(int x, int y){
    return x*c + y;
}

void dfs(int v){
    vis[v] = true;
    if(AL[v].size() % 2 == 0) eve++;
    else odd++;
    for(int w : AL[v]){
        if(!vis[w])
        dfs(w);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int t, linecnt = 0;
    cin >> t;
    while(t--){
        int w;
        cin >> r >> c >> m >> n >> w;
        int sz = r*c;
        AL.assign(sz, {});
        vis.assign(sz, false);
        vector<vector<bool>> grid(r, vector<bool> (c, false));
        for(int i = 0; i < w; ++i){
            int wx, wy;
            cin >> wx >> wy;
            grid[wx][wy] = true;
        }
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(grid[i][j]) continue;
                int ind = getInd(i, j);
                if(ind == 14){
                    int f = 1;
                }
                set<pii> st;
                for(int d = 0; d < 4; ++d){
                    int x = i + dir_x[d]*m,
                        y = j + dir_y[d]*n;
                    if(x >= 0 && x < r && y >= 0 && y < c && !grid[x][y]
                        && st.find({x, y}) == st.end()){
                        AL[ind].push_back(getInd(x, y));
                        st.emplace(x, y);
                    }
                    x = i + dir_x[d]*n;
                    y = j + dir_y[d]*m;
                    if(x >= 0 && x < r && y >= 0 && y < c && !grid[x][y]
                        && st.find({x, y}) == st.end()){
                        AL[ind].push_back(getInd(x, y));
                        st.emplace(x, y);
                    }
                }
            }
        }
        eve = 0, odd = 0;
        dfs(0);
        printf("Case %d: %d %d\n", ++linecnt, eve, odd);
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 