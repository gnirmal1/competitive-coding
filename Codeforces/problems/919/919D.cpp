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

#define Sum(v) (accumulate(v.begin(), v.end(), 0ll))
#define Sort(v) (sort(v.begin(), v.end()))


constexpr ll INF = 1e9;
constexpr int MOD = 1e9 + 7;


int solve(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<set<int>> graph(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].insert(v);
    }
    vector<int> vis(n);
    vector<vector<int>> dp(n, vector<int> (26));
    bool cycle = 0;
    function<void(int)> dfs = [&](int v){
        vis[v] = 1;
        int c = (int)s[v] - 97;
        for(auto w : graph[v]){
            if(vis[w] == 0) dfs(w);
            else if(vis[w] == 1) cycle = 1;
            for(int j = 0; j < 26; ++j){
                dp[v][j] = max(dp[v][j], dp[w][j] + (c == j));
            }
        }
        if(graph[v].empty()) dp[v][c] = 1;
        vis[v] = 2;
    };
    int ans = 1;
    for(int i = 0; i < n; ++i){
        if(vis[i] == 0){
            dfs(i);
            if(cycle) return -1;
            for(int p : dp[i]) ans = max(ans, p);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 
    cout << solve() << '\n';
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 