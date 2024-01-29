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

typedef pair<int, int> pii;
typedef vector<vector<pii>> vvpii;
typedef vector<int> vi;

#define Sum(v) (accumulate(v.begin(), v.end(), 0ll))


bool bad(int i, int j, int n, int m, vector<string> &grid){
    return (i + 1 < n && grid[i + 1][j] == '#') || 
            (i > 0 && grid[i - 1][j] == '#') ||
            (j + 1 < m && grid[i][j + 1] == '#') ||
            (j > 0 && grid[i][j - 1] == '#');
}

int getIndex(int i, int j, int m){
    return m*i + j;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n ; ++i){
        cin >> grid[i];
    }
    vector<vector<pair<int, int>>> graph(m*n);
    vector<int> dist(m*n, -1), parent(m*n, -1);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(bad(i, j, n, m, grid)) continue;
            if(i + 1 < n && j + 1 < m && !bad(i + 1, j + 1, n, m, grid)){
                if(grid[i + 1][j + 1] == '#') graph[getIndex(i, j, m)].emplace_back(getIndex(i + 1, j + 1, m), 0);
                else graph[getIndex(i, j, m)].emplace_back(getIndex(i + 1, j + 1, m), 1);
            }
            if(i > 0 && j + 1 < m && !bad(i - 1, j + 1, n, m, grid)){
                if(grid[i - 1][j + 1] == '#') graph[getIndex(i, j, m)].emplace_back(getIndex(i - 1, j + 1, m), 0);
                else graph[getIndex(i, j, m)].emplace_back(getIndex(i - 1, j + 1, m), 1);
            }
            if(i + 1 < n && j > 0 && !bad(i + 1, j - 1, n, m, grid)){
                if(grid[i + 1][j - 1] == '#') graph[getIndex(i, j, m)].emplace_back(getIndex(i + 1, j - 1, m), 0);
                else graph[getIndex(i, j, m)].emplace_back(getIndex(i + 1, j - 1, m), 1);
            }
            if(i > 0 && j > 0 && !bad(i - 1, j - 1, n, m, grid)){
                if(grid[i - 1][j - 1] == '#') graph[getIndex(i, j, m)].emplace_back(getIndex(i - 1, j - 1, m), 0);
                else graph[getIndex(i, j, m)].emplace_back(getIndex(i - 1, j - 1, m), 1);
            }
        }
    }
    deque<int> pq;
    for(int i = 0; i < n; ++i){
        int v = getIndex(i, 0, m);
        if(bad(i, 0, n, m, grid)) continue;
        if(grid[i][0] == '#') {
            pq.push_front(v);
            dist[v] = 0;
        }
        else {
            pq.push_back(v);
            dist[v] = 1;
        }
    }
    while(!pq.empty()){
        int v = pq.front();
        pq.pop_front();
        for (auto &[w, weight] : graph[v]){
            if(dist[w] != -1) continue;
            if(weight == 0){
                dist[w] = dist[v];
                pq.push_front(w);
            }
            else if(weight == 1){
                dist[w] = dist[v] + 1;
                pq.push_back(w);
            }
            parent[w] = v;
        }
    }
    int ans = 1e9, minInd = -1;
    for(int i = 0; i < n; ++i){
        int v = getIndex(i, m - 1, m);
        if(dist[v] != -1 && dist[v] < ans){
            ans = dist[v];
            minInd = v;   
        }
    }
    if(minInd == -1) cout << "NO\n";
    else{
        cout << "YES\n";
        int dest = minInd;
        while(dest != -1){
            grid[dest/m][dest % m] = '#';
            dest = parent[dest];
        }
        for(int i = 0; i < n; ++i){
            cout << grid[i] << '\n';
        }
    }   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 