#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;

constexpr ll INF = 1e9;
constexpr ll MOD = 1e9 + 7;

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
// __builtin_ctzl() for long long and __ builtin_popcount()
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

#define Sum(v) (accumulate(v.begin(), v.end(), 0ll))

void dfs(int check, int b, int v, vector<vector<pair<int, int>>> &AL, vector<bool> &visited, vector<ll> &xorlist){
  visited[v] = true;
  for (auto &[w, weight]: AL[v]){
    if (!visited[w]){
        xorlist[w] = xorlist[v] ^ weight;
        if(check == 0 && w == b) continue;
        dfs(check, b, w, AL, visited, xorlist);
    }
  }
}



int solve(){
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<pair<int, int>>> AL(n);
    a--; b--;
    for(int i = 0; i < n - 1; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        AL[u].emplace_back(v, w);
        AL[v].emplace_back(u, w);
    }
    vector<bool> visited(n, false);
    vector<ll> xorlist1(n, -1), xorlist2(n, 0);
    xorlist1[a] = 0;
    dfs(0, b, a, AL, visited, xorlist1);
    if(xorlist1[b] == 0) return true;
    visited.assign(n, false);
    dfs(2, b, b, AL, visited, xorlist2);
    set<ll> st;
    for(int i = 0; i < n; ++i) if(i != b) st.insert(xorlist2[i]);
    for(int i = 0; i < n; ++i) if(i != b && st.find(xorlist1[i]) != st.end()) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int t;
    cin >> t;
    while(t--){
        puts(solve()? "YES" : "NO");
    }
}

// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 