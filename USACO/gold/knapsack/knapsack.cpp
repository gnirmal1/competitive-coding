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

ll solve(){
    int s, n;
    cin >> s >> n;
    vvpii mp(s + 1);
    for(int i = 0; i < n; ++i){
        int v, w, k;
        cin >> v >> w >> k;
        mp[w].emplace_back(v, min(k, s));
    }
    vll weights, value;
    for(int i = 1; i <= s; ++i){
        int curr = 0;
        sort(mp[i].rbegin(), mp[i].rend());
        for(auto [v, k] : mp[i]){
            if(curr > s) break;
            curr += k*i;
            int hi = log2(k);
            for(int j = 0; j < hi; j++){
                int pow2 = (1 << j);
                weights.push_back(i*pow2);
                value.push_back((ll)v*pow2);
            }
            k -= ((1 << hi) - 1);
            for(int j = 0; j < 12; ++j){
                int pow2 = (1 << j);
                if(k & pow2){
                    weights.push_back(i*pow2);
                    value.push_back((ll)v*pow2);
                }
            }
        }
    }
    vll dp(s + 1);
    int m = weights.size();
    for(int i = 0; i < m; ++i){
        for(int j = s; j >= weights[i]; --j){
            dp[j] = max(dp[j], dp[j - weights[i]] + value[i]);
        }
    }
    return dp[s];
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