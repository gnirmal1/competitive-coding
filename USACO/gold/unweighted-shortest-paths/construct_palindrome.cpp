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

int getind(int i, int j, int n){
    return i*n + j;
}
int solve(){
    int n, m;
    cin >> n >> m;
    vvpii graph(n);
    for(int i = 0; i < m; ++i){
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--; b--;
        graph[a].emplace_back(b, c - 'a');
        graph[b].emplace_back(a, c - 'a');
    }
    vvi new_graph(n*n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int curr = getind(i, j, n);
            for(auto [w1, c1] : graph[i]){
                for(auto [w2, c2] : graph[j]){
                    if(c1 == c2) new_graph[curr].push_back(getind(w1, w2, n));
                }
            }
        }
    }
    queue<int> q;
    vi dist(n*n, INF);
    int start = getind(0, n - 1, n);
    q.push(start);
    dist[start] = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(auto w : new_graph[v]){
            if(dist[w] == INF){
                dist[w] = dist[v] + 2;
                q.push(w);
            }
        }
    }

    int ans = INF;
    for(int i = 0; i < n; ++i){
        ans = min(ans, dist[getind(i, i, n)]);
        for(auto [j, c] : graph[i]){
            ans = min(ans, dist[getind(i, j, n)] + 1);
        }
    }
    if(ans == INF) return -1;
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