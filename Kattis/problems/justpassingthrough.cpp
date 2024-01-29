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

int grid[500][500];
int dr[] = {0, 1, -1},
    dc[] = {1, 1, 1};
int n, m;
int pass(int i, int j){
    if(i == 0 || i == n - 1 || j == 0 || j == m - 1) return 0;
    if(grid[i + 1][j] == -1 || grid[i - 1][j] == -1 ||
        grid[i][j + 1] == -1 || grid[i][j - 1] == -1) return 0;
    if(grid[i + 1][j] > grid[i][j] && grid[i - 1][j] > grid[i][j] 
        && grid[i][j + 1] < grid[i][j] && grid[i][j - 1] < grid[i][j]) return 1;
    return 0;
}

void solve(){
    int p;
    cin >> n >> m >> p;
    vector<vvi> dist(n, vvi(m, vi(p + 1, INF)));
    using T = tuple<int, int, int, int>;
	priority_queue<T, vector<T>, greater<T>> pq;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
        if(grid[i][0] != -1){
            dist[i][0][0] = grid[i][0];
            pq.emplace(grid[i][0], i, 0, 0);
        }
    }
    while(!pq.empty()){
        auto [d, i, j, passes] = pq.top(); pq.pop();
        if(d > dist[i][j][passes]) continue;
        if(j == m - 1 && passes == p) {
            cout << dist[i][j][passes] << '\n';
            return;
        }
        for(int k = 0; k < 3; ++k){
            int x = i + dr[k], y = j + dc[k];
            if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == -1) continue;
            int ch = pass(x, y);
            if(passes + ch <= p && d + grid[x][y] < dist[x][y][passes + ch]){
                dist[x][y][passes + ch] = d + grid[x][y];
                pq.emplace(dist[x][y][passes + ch], x, y, passes + ch);
            }
        }
    }
    cout << "impossible\n";
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