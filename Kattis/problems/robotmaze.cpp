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

int dr[] = {0, 1, -1, 0},
    dc[] = {1, 0, 0, -1};

int dist[1000][1000][4][2];
int solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vi(m));
    int si, sj, di, dj;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char c;
            cin >> c;
            if(c == 'R'){
                si = i, sj = j;
            }
            else if(c == 'D'){
                di = i, dj = j;
            }
            grid[i][j] = (c != 'B');
        }
    }
    memset(dist, -1, sizeof dist);
    queue<tuple<int, int, int, int>> q;
    for(int d = 0; d < 4; ++d){
        int x = si + dr[d], y = sj + dc[d];
        if(x < 0 || x >= n || y < 0 || y >= m || !grid[x][y]) continue;
        dist[x][y][d][0] = 1;
        q.emplace(x, y, d, 0);
    }
    while(!q.empty()){
        auto [i, j, dir, steps] = q.front(); q.pop();
        for(int d = 0; d < 4; ++d){
            int x = i + dr[d], y = j + dc[d];
            if(x < 0 || x >= n || y < 0 || y >= m || !grid[x][y]) continue;
            if(d == 3 - dir) continue;
            if(d == dir && steps == 1) continue;
            int next_steps = (d == dir? 1 : 0);
            if(dist[x][y][d][next_steps] == -1){
                dist[x][y][d][next_steps] = dist[i][j][dir][steps] + 1;
                q.emplace(x, y, d, next_steps);
            }
        }
    }
    int ans = INF;
    for(int d = 0; d < 4; ++d){
        for(int s = 0; s < 2; ++s){
            if(dist[di][dj][d][s] != -1) ans = min(ans, dist[di][dj][d][s]);
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

    int t;
    cin >> t;
    while(t--){
        cout << solve() << '\n';
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 