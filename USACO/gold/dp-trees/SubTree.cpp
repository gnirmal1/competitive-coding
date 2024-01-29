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

int m;
vvi graph;
vvll pref, suff;
vll dp1, dp2;
void dfs1(int v, int p){
    pref[v].push_back(1);
    int gn = graph[v].size();
    for(int i = 0; i < gn; ++i){
        int w = graph[v][i];
        if(w != p){
            dfs1(w, v);
            dp1[v] = ((dp1[v]*(dp1[w] + 1))%m + m)%m;
        }
        pref[v].push_back(dp1[v]);
    }

    ll curr = 1;
    suff[v].push_back(1);
    for(int i = gn - 1; i >= 0; --i){
        int w = graph[v][i];
        if(w != p){
            curr = ((curr*(dp1[w] + 1))%m + m)%m;
        }
        suff[v].push_back(curr);
    }
}

void dfs2(int v, int p){
    int gn = graph[v].size();
    for(int i = 0; i < gn; ++i){
        int w = graph[v][i];
        if(w != p){
            ll x = ((pref[v][i]*suff[v][gn - i - 1] % m) + m) % m;
            dp2[w] = ((dp2[v]*x + 1) % m + m) % m;
            dfs2(w, v);
        }
    }
}

void solve(){
    int n;
    cin >> n >> m;
    graph.assign(n, {});
    pref.assign(n, {});
    suff.assign(n, {});
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dp1.assign(n, 1);
    dp2.assign(n, 1);
    dfs1(0, -1);
    dfs2(0, -1);
    for(int i = 0; i < n; ++i){
        ll ans = ((dp1[i]*dp2[i]) % m + m) % m;
        cout << ans << '\n';
    }
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