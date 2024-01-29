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

void solve(){
    ifstream fin ("shortcut.in");
    ofstream fout ("shortcut.out");
    int n, m, t;
    fin >> n >> m >> t;
    vll c(n);
    for(int i = 0; i < n; ++i){
        fin >> c[i];
    }
    vvpii graph(n);
    for(int i = 0; i < m; ++i){
        int a, b, w;
        fin >> a >> b >> w;
        a--; b--;
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }
    vll dist(n, INF);
    vpii parent(n, {-1, -1});
    using T = pair<ll, ll>;
	priority_queue<T, vector<T>, greater<T>> pq;
    dist[0] = 0;
    pq.emplace(0, 0);
    while(!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        if(d > dist[v]) continue;
        for(auto [w, weight] : graph[v]){
            if(d + weight < dist[w] || (d + weight == dist[w] && v < parent[w].first)){
                dist[w] = d + weight;
                parent[w] = {v, weight};
                pq.emplace(dist[w], w);
            }
        }
    }
    vector<ll> shortcut(n, 0);
    for(int i = 0; i < n; ++i){
        ll x = i, curr = dist[i];
        while(x != 0){
            if(curr > t) shortcut[x] += (ll)c[i]*(curr - t);
            auto [p, weight] = parent[x];
            curr -= weight;
            x = p;
        }
    }
    fout << *max_element(shortcut.begin(), shortcut.end());
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