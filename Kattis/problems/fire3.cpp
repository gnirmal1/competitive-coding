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
    int r, c;
    cin >> r >> c;
    vvi grid(r, vi(c));
    vvpii dist(r, vpii(c, {1e9, -1}));
    queue<pii> q;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            char x;
            cin >> x;
            if(x == '#' || x == 'F') grid[i][j] = 0;
            else grid[i][j] = 1;
            if(x == 'F') {
                dist[i][j] = {0, 0};
                q.push({i, j});
            }
            else if(x == 'J') {
                q.push({i, j});
                dist[i][j] = {0, 1};
            }
        }
    }
    int dr[] = {1, -1, 0, 0},
        dc[] = {0, 0, 1, -1};
    while(!q.empty()){
        auto [i, j] = q.front(); q.pop();
        for(int d = 0; d < 4; ++d){
            int x = i + dr[d], y = j + dc[d];
            if(x < 0 || x >= r || y < 0 || y >= c) continue;
            if(grid[x][y] && dist[x][y].first == 1e9){
                dist[x][y] = {dist[i][j].first + 1, dist[i][j].second};
                q.emplace(x, y);
            }
            else if(dist[x][y].first == dist[i][j].first + 1 && dist[i][j].second == 0)
                dist[x][y].second = 0;
        }
    }

    int ans = 1e9;
    for(int i = 0; i < r; ++i){
        if(dist[i][0].second) ans = min(ans, dist[i][0].first);
        if(dist[i][c - 1].second) ans = min(ans, dist[i][c - 1].first);
    }

    for(int j = 0; j < c; ++j){
        if(dist[0][j].second) ans = min(ans, dist[0][j].first);
        if(dist[r - 1][j].second) ans = min(ans, dist[r - 1][j].first);
    }
    if(ans == 1e9) cout << "IMPOSSIBLE\n";
    else cout << ans + 1 << '\n';
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