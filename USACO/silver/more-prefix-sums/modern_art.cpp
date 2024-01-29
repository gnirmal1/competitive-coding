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
    int n;
    cin >> n;
    vvi targetGrid(n + 1, vi(n + 1));
    int maxcol = n*n + 1;;
    vector<int> minr(maxcol, n), maxr(maxcol), minc(maxcol, n), maxc(maxcol);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int c;
            cin >> c;
            targetGrid[i][j] = c;
            minr[c] = min(minr[c], i);
            maxr[c] = max(maxr[c], i);
            minc[c] = min(minc[c], j);
            maxc[c] = max(maxc[c], j);
        }
    }
    vector<bool> vis(maxcol);
    vector<vector<int>> prefix(n + 2, vector<int> (n + 2));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int c = targetGrid[i][j];
            if(!vis[c]){
                int r1 = minr[c], c1 = minc[c], r2 = maxr[c] + 1, c2 = maxc[c] + 1;
                prefix[r1][c1]++;
                prefix[r2][c2]++;
                prefix[r1][c2]--;
                prefix[r2][c1]--;
                vis[c] = true;
            }
        }
    }
    vector<int> paintedfirst(maxcol, true);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            prefix[i][j] +=  prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
            if(prefix[i][j] >= 2) paintedfirst[targetGrid[i][j]] = false;
        }
    }
    int ans = 0;
    for(int i = 1; i < maxcol; ++i){
        if(paintedfirst[i]) ans++;;
    }
    cout << ans;
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