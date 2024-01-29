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

int dr[] = { 1, 0, -1, 0};            
int dc[] = { 0, 1, 0, -1};
vector<string> grid(20);

void dfs(int i, int j, int i1, int i2, int j1, int j2, vector<vector<int>> &temp){
    temp[i][j] = 1;
    for(int d = 0; d < 4; ++d){
        int x = i + dr[d], y = j + dc[d];
        if(x >= i1 && x <= i2 && y >= j1 && y <= j2
            && grid[i][j] == grid[x][y] && temp[x][y] == 0) dfs(x, y, i1, i2, j1, j2, temp);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 
    ifstream fin ("where.in");
    int n;
    fin >> n;
    for(int i = 0; i < n; ++i){
        fin >> grid[i];
    }
    vector<vector<int>> pcl;
    for(int i1 = 0; i1 < n; ++i1){
        for(int j1 = 0; j1 < n; ++j1){
            for(int i2 = i1; i2 < n; ++i2){
                for(int j2 = j1; j2 < n; ++j2){
                    vector<vector<int>> temp(n, vector<int> (n));
                    bool flag = 1;
                    map<char, int> mp;
                    for(int i = i1; i <= i2; ++i){
                        for(int j = j1; j <= j2 && flag; ++j){
                            if(temp[i][j] == 0){
                                dfs(i, j, i1, i2, j1, j2, temp);
                                mp[grid[i][j]]++;
                                if(mp.size() > 2) flag = 0;
                            }
                        }
                    }
                    if(mp.size() == 2){
                        vector<int> t;
                        for(auto [c, cnt] : mp) t.push_back(cnt);
                        Sort(t);
                        if(t[0] == 1 && t[1] >= 2) pcl.push_back({i1, i2, j1, j2});
                    }
                }
            }
        }
    }
    int m = pcl.size(), ans = 0;;
    vector<bool> can(m, true);
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j){
            if(i != j && pcl[i][0] <= pcl[j][0] && pcl[j][1] <= pcl[i][1] && 
                pcl[i][2] <= pcl[j][2] && pcl[j][3] <= pcl[i][3]) can[j] = false;
        }
    }
    for(int i = 0; i < m; ++i) if(can[i]) ans++;
    ofstream fout ("where.out");
    fout << ans << '\n';

}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 