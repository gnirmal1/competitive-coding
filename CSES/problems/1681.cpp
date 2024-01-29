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


void solve(){
    int n, m;
    cin >> n >> m;
    vvi graph(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
    }
    vector<bool> vis(n);
    vll dp(n, 0);
    dp[n - 1] = 1;
    function<void(int)> dfs = [&](int v){
        vis[v] = true;
        for(auto w : graph[v]){
            if(!vis[w]) dfs(w);
            dp[v] = (dp[v] + dp[w]) % MOD;
        }
    };
    dfs(0);
    cout << dp[0] << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 
    solve();
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 