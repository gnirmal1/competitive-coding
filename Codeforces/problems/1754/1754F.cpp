#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;

constexpr ll INF = 1e18;
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


int getInd(int i, int j, int m){
    return m*i + j;
}

ll solve(){
    int n, m;
    cin >> n >> m;
    int p, q;
    cin >> p >> q;
    vector<string> grid(n);
    for(int i = 0; i < n; ++i){
        cin >> grid[i];
    }
    vector<vector<pair<int, int>>> graph(n*m);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(n*m, INF);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int v = getInd(i, j, m);
            if(grid[i][j] != '#'){
                if(j < m - 1 && grid[i][j + 1] == 'L')
                    graph[v].push_back({getInd(i, j + 2, m), q});
                if(j > 0 && grid[i][j - 1] == 'R')
                    graph[v].push_back({getInd(i, j - 2, m), q});
                if(i < n - 1 && grid[i + 1][j] == 'U')
                    graph[v].push_back({getInd(i + 2, j, m), q});
                if(i > 0 && grid[i - 1][j] == 'D')
                    graph[v].push_back({getInd(i - 2, j, m), q});


                if((j < m - 1 && grid[i][j + 1] == 'U') || (i < n - 1 && grid[i + 1][j] == 'L'))
                    graph[v].push_back({getInd(i + 1, j + 1, m), p});
                if((j < m - 1 && grid[i][j + 1] == 'D') || (i > 0 && grid[i - 1][j] == 'L'))
                    graph[v].push_back({getInd(i - 1, j + 1, m), p});
                if((j > 0 && grid[i][j - 1] == 'U') || (i < n - 1 && grid[i + 1][j] == 'R'))
                    graph[v].push_back({getInd(i + 1, j - 1, m), p});
                if((j > 0 && grid[i][j - 1] == 'D') || (i > 0 && grid[i - 1][j] == 'R'))
                    graph[v].push_back({getInd(i - 1, j - 1, m), p});
            }

            if(grid[i][j] == '.'){
                pq.emplace(0, v);
                dist[v] = 0;
            }
        }
    }

    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();
        if (dist[v] < d) continue;
        for (auto &[w, weight] : graph[v]){
            if (d + weight < dist[w]){  // relax edges
                dist[w] = d + weight;
                pq.emplace(dist[w], w);
            }
        }
    }

    ll ans = INF;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int v = getInd(i, j, m);
            if(j < m - 1) ans = min(ans, dist[v] + dist[getInd(i, j + 1, m)]);
            if(i < n - 1) ans = min(ans, dist[v] + dist[getInd(i + 1, j, m)]);
        } 
    }
    return ans == INF ? -1 : ans;
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