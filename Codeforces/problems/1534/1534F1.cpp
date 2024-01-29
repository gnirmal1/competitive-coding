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


int n, m;
vpii component, order;
int cc = 1;
int dr[] = {-1,0, 0, 1},
    dc[] = {0,-1, 1, 0};

int getInd(int i, int j){
    return i*m + j;
}

void dfs1(int i, int j, vvi &grid){
    int val = grid[i][j];
    if(val == cc) grid[i][j] = cc + 2;
    else grid[i][j] = cc + 1;
    for(int d = 0; d < 4; ++d){
        int x = i + dr[d], y = j + dc[d];
        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] > cc) continue;
        if(val == cc - 1 && dr[d] == -1) continue; 
        if(grid[x][y] == cc || dr[d] == 1) dfs1(x, y, grid);
    }
    order.emplace_back(i, j);
}

void dfs2(int i, int j, vvi &grid){
    int val = grid[i][j];    
    if(val == cc) grid[i][j] = cc + 2;
    else grid[i][j] = cc + 1;
    component.emplace_back(i, j);
    for(int d = 0; d < 4; ++d){
        int x = i + dr[d], y = j + dc[d];
        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] > cc || grid[x][y] == 0) continue;
        if(val == cc - 1 && dr[d] != -1) continue; 
        if(val == cc && dr[d] == 1 && grid[x][y] == cc - 1) continue; 
        dfs2(x, y, grid);
    }
}

int solve(){
    cin >> n >> m;
    vvi grid(n, vi(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char c;
            cin >> c;
            grid[i][j] = (c == '#');
        }
    }
    vi a(m);
    cin >> a;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == cc) dfs1(i, j, grid);
        }
    }
    reverse(order.begin(), order.end());
    cc += 2;
    vpii root_nodes;
    map<pii, pii> roots;
    for(auto [i, j] : order){
        if(grid[i][j] <= cc){
            dfs2(i, j,  grid);
            auto root = component.front();
            for(auto p : component) roots[p] = root;
            root_nodes.push_back(root);
            component.clear();
        }
    }
    cc += 2;
    vi indegree(n*m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int val = grid[i][j];
            if(val == 0) continue;
            for(int d = 0; d < 4; ++d){
                int x = i + dr[d], y = j + dc[d];
                if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) continue;
                if(val == cc - 1 && dr[d] == -1) continue; 
                if(grid[x][y] == cc || dr[d] == 1){
                    if(roots[{x, y}] == roots[{i, j}]) continue;
                    auto [f, s] = roots[{x, y}];
                    indegree[getInd(f, s)]++;
                }
            }
        }
    }

    int ans = 0;
    for(auto [i, j] : root_nodes){
        if(indegree[getInd(i, j)] == 0) ans++;
    }
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