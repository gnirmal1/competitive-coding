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


int n;
int dr[] = { 1, 1, 0,-1,-1,-1, 0, 1};            
int dc[] = { 0, 1, 1, 1, 0,-1,-1,-1};
vector<string> grid;

void dfs(int i, int j){
    grid[i][j] = '.';
    for(int d = 0; d < 8; ++d){
        int i1 = i + dr[d], j1 = j + dc[d];
        if(i1 < 0 || j1 < 0) continue;
        if(i1 >= n || j1 >= n) continue;
        if(grid[i1][j1] == 'x' || grid[i1][j1] == '@') dfs(i1, j1);
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
        cin >> n;
        grid.assign(n, "");
        for(int i = 0; i < n; ++i){
            cin >> grid[i];
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 'x'){
                    dfs(i, j);
                    ans++;
                }
            }
        }
        printf("Case %d: %d\n", ++linecnt, ans);
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 