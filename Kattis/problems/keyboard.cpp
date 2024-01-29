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

int dist[50][50][10002], grid[50][50];
int solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char ch;
            cin >> ch;
            grid[i][j] = ch - '*';
        }
    }
    string text;
    cin >> text;
    text += '*';
    memset(dist, -1, sizeof dist);
    vector<vvpii> next(n, vector(m, vpii(4, {-1, -1})));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            for(int a = j + 1; a < m; ++a){
                if(grid[i][j] != grid[i][a]){
                    next[i][j][0] = {i, a};
                    break; 
                }
            }

            for(int a = j - 1; a >= 0; --a){
                if(grid[i][j] != grid[i][a]){
                    next[i][j][1] = {i, a};
                    break; 
                }
            }

            for(int a = i + 1; a < n; ++a){
                if(grid[i][j] != grid[a][j]){
                    next[i][j][2] = {a, j};
                    break; 
                }
            }

            for(int a = i - 1; a >= 0; --a){
                if(grid[i][j] != grid[a][j]){
                    next[i][j][3] = {a, j};
                    break; 
                }
            }
        }
    }
    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    dist[0][0][0] = 0;
    while(!q.empty()){
        auto [i, j, k] = q.front(); q.pop();
        if(k >= text.size()) {
            return dist[i][j][k];
        }
        int cx = text[k] - '*';
        if(cx == grid[i][j]){
            q.emplace(i, j, k + 1);
            dist[i][j][k + 1] = dist[i][j][k] + 1;
        }
        for(auto [x, y] : next[i][j]){
            if(x == -1) continue;
            if(dist[x][y][k] == -1){
                q.emplace(x, y, k);
                dist[x][y][k] = dist[i][j][k] + 1;
            }
        }
    }
    return -1;
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