#include "bits/stdc++.h"
using namespace std;

// Template modified from https://usaco.guide/general/generic-code?lang=cpp#templates 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
using vi = vector<ll>;
using pii = pair<ll, ll>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvpii = vector<vpii>;

#define Sum(v) (accumulate(v.begin(), v.end(), 0ll))
#define Sort(v) (sort(v.begin(), v.end()))


constexpr ll INF = 1e9;
constexpr ll MOD = 998244353;

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



ll solve(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), cold(k), hot(k);
    cin >> a >> cold >> hot;
    vector<ll> dp(k + 1, -1);
    dp[0] = cold[a[0] - 1];
    ll prev = a[0];
    for(ll i = 1; i < n; ++i){
        vector<ll> curr(k + 1, -1);
        ll prev_min = 1e18 + 1;
        for(ll j = 0; j <= k; ++j){
            if(j != a[i] && dp[j] != -1 && dp[j] < prev_min)
            prev_min = dp[j];
        }

        for(ll j = 0; j <= k; ++j){
            if(j != prev && dp[j] != -1){
                curr[j] = dp[j] + ((prev == a[i]) ? hot[a[i] - 1] : cold[a[i] - 1]);
            }
            else if(j == prev){
                if(dp[a[i]] != -1) curr[j] = dp[a[i]] + hot[a[i] - 1];
                if(curr[j] == -1) curr[j] = prev_min + cold[a[i] - 1];
                else curr[j] = min(curr[j], prev_min + cold[a[i] - 1]);
            }
        }
        dp = curr;
        prev = a[i];
    }
    ll ans = dp[0];
    for(ll i = 1; i <= k; ++i){
        if(dp[i] != -1 && dp[i] < ans)
            ans = dp[i];
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    ll t;
    cin >> t;
    while(t--){
        cout << solve() << '\n';
    }
}
// when using prllf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 