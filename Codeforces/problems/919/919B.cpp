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

const int target = 10;
ll memo[301][target + 1][2];
ll dp(string &num, int n, int sum, bool tight){
    if(n == 0 && sum == 0) return 1;
    if(sum < 0 || n == 0) return 0;
    ll &ans = memo[n][sum][tight];
    if(ans != -1) return ans;
    ans = 0;
    int ub = tight? (num[num.length() - n] - '0') : 9;
    for(int dig = 0; dig <= ub; ++dig){
        ans += dp(num, n - 1, sum - dig, tight & (dig == ub));
    }
    return ans;
}

void solve(){
    ll k;
    cin >> k;
    string numr = string(300, '9');
    int nr = numr.length();
    memset(memo, -1, sizeof memo);

    cout << dp(numr, nr, target, 1) << '\n';
    string ans = ""; 
    ll currt = target;
    for(int i = nr; i >= 1; --i){
        ll sum = 0, dig = 0;
        while(true){
            ll x = dp(numr, i - 1, currt - dig, 1);
            if(sum + x >= k) break;
            sum += x;
            dig++;
        }
        if(!ans.empty() || dig != 0) ans += (dig + '0');
        currt -= dig;
        k -= sum;
    } 
    cout << ans << '\n';
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