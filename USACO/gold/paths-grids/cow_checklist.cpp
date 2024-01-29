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


constexpr ll INF = 1e18;
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

int cost(int x1, int y1, int x2, int y2){
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}


ll memo[1001][1001][2];
pii coord[1001][2];
int n, m;

int cost(int i1, int j1, int state1, int i2, int j2, int state2){
    int x1, y1, x2, y2;
    if(!state1){
        x1 = coord[i1][state1].first;
        y1 = coord[i1][state1].second;
    }
    else{
        x1 = coord[j1][state1].first;
        y1 = coord[j1][state1].second;
    }

    if(!state2){
        x2 = coord[i2][state2].first;
        y2 = coord[i2][state2].second;
    }
    else{
        x2 = coord[j2][state2].first;
        y2 = coord[j2][state2].second;
    }
    return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

ll dp(int i, int j, int state){
    if(i == n && j == m){
        if(!state) return 0;
        return INF;
    }
    ll &ans = memo[i][j][state];
    if(ans != -1) return ans;
    ans = INF;
    if(i + 1 <= n){
        ans = min(ans, dp(i + 1, j, 0) + cost(i + 1, j, 0, i, j, state));
    }
    if(j + 1 <= m){
        ans = min(ans, dp(i, j + 1, 1) + cost(i, j + 1, 1, i, j, state));
    }
    return ans;
}

void solve(){
    ifstream fin ("checklist.in");
    ofstream fout ("checklist.out");
    fin >> n >> m;
    for(int i = 1; i <= n; ++i){
        fin >> coord[i][0].first >> coord[i][0].second;
    }
    for(int i = 1; i <= m; ++i){
        fin >> coord[i][1].first >> coord[i][1].second;
    }
    memset(memo, -1, sizeof memo);
    fout << dp(1, 0, 0) << '\n';
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