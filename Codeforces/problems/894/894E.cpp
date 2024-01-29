#include "bits/stdc++.h"
using namespace std;

// Template modified from https://usaco.guide/general/generic-code?lang=cpp#templates 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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
constexpr int MOD = 998244353;

// #define IO(NAME) \
//     cin.tie(0)->sync_with_stdio(0); \
//     if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
//     freopen(NAME ".out","w",stdout);

template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
 
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
 
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}


// bitwise ops
// j is 0 based indexing 
// __builtin_ctzll() for long long and __ builtin_popcount()
#define LSB(S) ((S) & -(S))


ll LCM(int a, int b)
{
    return ((ll)a * b) / __gcd(a, b);
}

bool nCr_Parity(int n, int r){
    int i = 0;
    while(i <= 30){ // for 32 bit integers
        int x = 1<<i;
        if((x&r) > (x&n)) return 0;
        ++i;
    }
    return 1; // 1 is odd 
}

vi component, order, vis;
void dfs1(int v, vvpii &graph){
    vis[v] = true;
    for(auto [w, weight] : graph[v]){
        if(!vis[w]) dfs1(w, graph);
    }
    order.push_back(v);
}

ll total;
int cc = 1;
void dfs2(int v, vvpii &graph){
    vis[v] = cc;
    component.push_back(v);
    for(auto [w, weight] : graph[v]){
        if(vis[w] == 0) dfs2(w, graph);
        if(vis[w] == vis[v]){
            double y = (-1 + sqrt(1 + 8*weight))/2.0;
            ll x = floor(y);
            total += weight*(x + 1) - (ll) x*(x + 1)*(x + 2)/6;
        }
    }
}


ll solve(){
    int n, m;
    cin >> n >> m;
    vvpii graph(n), rgraph(n), sccgraph(n);
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].emplace_back(v, w);
        rgraph[v].emplace_back(u, w);
    }
    int s;
    cin >> s;
    s--;

    vis.assign(n, false);
    for(int i = 0; i < n; ++i){
        if(!vis[i]) dfs1(i, graph);
    }
    reverse(order.begin(), order.end());
    vis.assign(n, false);
    vi roots(n), root_nodes;
    vll dp(n);
    for(int i : order){
        if(vis[i] == 0){
            total = 0;
            dfs2(i, rgraph);
            cc++;
            int root = component.front();
            dp[root] = total;
            for(auto u : component) roots[u] = root;
            root_nodes.push_back(root);
            component.clear();
        }
    }
    for(int v = 0; v < n; ++v){
        for(auto [w, weight] : graph[v]){
            if(roots[w] == roots[v]) continue;
            sccgraph[roots[v]].emplace_back(roots[w], weight);
        }
    }

    vi vis(n);
    function<void(int)> dfs3 = [&](int v){
        vis[v] = true;
        ll x = 0;
        for(auto [w, weight] : sccgraph[v]){
            if(!vis[w]) dfs3(w);
            x = max(x, weight + dp[w]);
        }
        dp[v] += x;
    };

    dfs3(roots[s]);
    return dp[roots[s]];
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