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
 

void solve(){
    int n, m;
    cin >> n >> m;
    vvpii graph(n);
    for(int i = 0; i < m; ++i){
        int u, v, y;
        cin >> u >> v >> y;
        u--; v--;
        graph[u].emplace_back(v, y);
        graph[v].emplace_back(u, y);
    }
    string str = string(n, '0');
    function<void(int)> dfs = [&](int v){
        str[v] = '1';
        for(auto [w, y] : graph[v]){
            if(str[w] == '0') dfs(w);
        }
    };
    dfs(0);
    if(str[n - 1] == '0') {
        cout << "inf\n";
        return;
    }
    vector<pair<string, ll>> ans;
    priority_queue<pii, vpii, greater<pii> > pq;
    ll time = 1;
    pq.emplace(-1, n - 1);
    while(str[0] == '1'){
        auto [t, v] = pq.top(); pq.pop();
        ans.emplace_back(str, t);
        time += t;
        vi curr_removed = {v};
        vpii temp;
        str[v] = '0';
        int sz = pq.size();

        for(int i = 0; i < sz; ++i){
            if(pq.top().first > t) temp.emplace_back(pq.top().first - t, pq.top().second);
            else {
                str[pq.top().second] = '0';
                curr_removed.push_back(pq.top().second);
            }
            pq.pop();
        }
        for(auto [a, b] : temp) pq.emplace(a, b);
        for(int i : curr_removed){
            for(auto [j, y] : graph[i]){
                if(str[j] == '1') pq.emplace(y, j);
            }
        }
    }
    cout << time << " " << ans.size() - 1 << '\n';
    for(int i = 1; i < ans.size(); ++i){
        cout << ans[i].first << " " << ans[i].second << '\n';
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