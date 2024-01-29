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


int vis[100000], parent[100000];
vvi graph;
int s = -1, e = -1;
void dfs(int v){
    vis[v] = 1;
    for(int w : graph[v]){
        if(vis[w] == 0) {
            parent[w] = v;
            dfs(w);
        }
        else if (vis[w] == 1) {
            s = w; e = v;
        }
    }
    vis[v] = 2;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int n, m;
    cin >> n >> m;
    graph.assign(n, {});
    memset(vis, 0, sizeof vis);
    memset(parent, -1, sizeof parent);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
    }
    for(int i = 0; i < n; ++i){
        if(vis[i] == 0) dfs(i);
    }
    if(s != -1){
        vector<int> res = {s + 1};
        for(int i = e; i != s; i = parent[i]){
            res.push_back(i + 1);
        }
        res.push_back(s + 1);
        reverse(res.begin(), res.end());
        cout << res.size() << '\n' << res << '\n';
    }
    else cout << "IMPOSSIBLE\n";
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 