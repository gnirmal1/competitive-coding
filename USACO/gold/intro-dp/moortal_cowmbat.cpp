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

vvi AM, dist, prefix;
int n, k, m, memo[100001][26];
string str;
int dp(int i, int curr){
    if(i == n) return 0;
    int &ans = memo[i][curr];
    if(ans != -1) return ans;
    ans = INF;
    int c = str[i] - 'a';
    if(i > 0) ans = dist[c][curr] + dp(i + 1, curr);
    if(i + k <= n){
        for(int newcurr = 0; newcurr < m; ++newcurr){
            ans = min(ans, prefix[newcurr][i + k] - prefix[newcurr][i] + dp(i + k, newcurr));
        }
    }
    return ans;
}

void solve(){
    ifstream cin ("cowmbat.in");
    ofstream cout ("cowmbat.out");
    cin >> n >> m >> k;
    cin >> str;
    AM.assign(m, vi(m));
    dist.assign(m, vi(m, INF));
    prefix.assign(m, vi(n + 1, 0));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < m; ++j){
            cin >> AM[i][j];
        }
    }
    for(int i = 0; i < m; ++i){
        priority_queue<pii> pq;
        dist[i][i] = 0;
        pq.emplace(0, i);
        while(!pq.empty()){
            auto [d, v] = pq.top(); pq.pop();
            if(d > dist[i][v]) continue;
            for(int j = 0; j < m; ++j){
                if(d + AM[v][j] < dist[i][j]){
                    dist[i][j] = d + AM[v][j];
                    pq.emplace(dist[i][j], j);
                }
            }
        }
    }

    for(int i = 0; i < m; ++i){
        for(int j = 1; j <= n; ++j){
            int c = str[j - 1] - 'a';
            prefix[i][j] = prefix[i][j - 1] + dist[c][i]; 
        }
    }
    memset(memo, -1, sizeof memo);
    cout << dp(0, 0);
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