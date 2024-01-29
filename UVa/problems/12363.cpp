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

void solve(int n){
    int c, q;
    cin >> c >> q;
    vvi graph(n), transformed_graph(n);
    for(int i = 0; i < c; ++i){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vi dfs_num(n, -1), dfs_low(n, -1);
    int tim = 0;
    function<void(int, int)> dfs1 = [&](int v, int p){
        dfs_num[v] = dfs_low[v] = tim++;
        for(int w : graph[v]){
            if(dfs_num[w] == -1){
                dfs1(w, v);
                if(dfs_low[w] > dfs_num[v]){
                    transformed_graph[v].push_back(w);
                    transformed_graph[w].push_back(v);
                }
                dfs_low[v] = min(dfs_low[v], dfs_low[w]);
            }
            else if(w != p){
                dfs_low[v] = min(dfs_low[v], dfs_num[w]);
            }
            
        }
    };
    int cc = 1;
    vector<int> comp(n);
    function<void(int)> dfs2 = [&](int v){
        comp[v] = cc;
        for(int w : transformed_graph[v]){
            if(comp[w] == 0){
                dfs2(w);
            }
        }
    };
    dfs1(0, -1);

    for(int i = 0; i < n; ++i){
        if(comp[i] == 0){
            dfs2(i);
            cc++;
        }
    }

    while(q--){
        int s, t;
        cin >> s >> t;
        s--; t--;
        if(comp[s] == comp[t]) cout << "Y\n";
        else cout << "N\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    while(true){
        int r;
        cin >> r;
        if(r == 0) break;
        solve(r);
        cout << "-\n";
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 