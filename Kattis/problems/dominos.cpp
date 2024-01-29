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


vector<bool> used;
int leaves;

void dfs1(int v, vvi &graph, vi &order, bool flag) {
    used[v] = true;
    for (auto u : graph[v]){
        if (!used[u])
            dfs1(u, graph, order, flag);
    }
    if(flag && graph[v].empty()) leaves++;
    else order.push_back(v);
}

void dfs2(int v, vvi &graph, vi &component) {
    used[v] = true;
    component.push_back(v);

    for (auto u : graph[v]){
        if (!used[u])
            dfs2(u, graph, component);
    }
}


int solve(){
    int n, m; // number of edges
    cin >> n >> m;
    vvi adj(n), adj_rev(n);
    vi component, order;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj_rev[b].push_back(a);
    }

    used.assign(n, false);

    for (int i = 0; i < n; i++){
        if (!used[i])
            dfs1(i, adj, order, 0);
    }

    used.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0);
    vector<int> root_nodes;
    vector<vector<int>> adj_scc(n);
    for (auto v : order){
        if (!used[v]) {
            dfs2(v, adj_rev, component);
            int root = component.front();
            for (auto u : component) roots[u] = root;
            root_nodes.push_back(root);

            component.clear();
        }
    }
    vi indegree(n);
    for (int v = 0; v < n; v++){
        for (auto u : adj[v]) {
            int root_v = roots[v],
                root_u = roots[u];

            if (root_u != root_v){
                adj_scc[root_v].push_back(root_u);
                indegree[root_u]++;
            }
        }
    }
    int ans = 0;
    for(auto i : root_nodes){
        if(indegree[i] == 0) ans++;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int t;
    cin >> t;
    while(t--){
        cout << solve() << '\n';
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 