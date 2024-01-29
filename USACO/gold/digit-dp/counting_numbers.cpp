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



ll memo[20][11][2][2];

ll dp(string &num, int n, int prev, bool tight, bool leading){
    if(n == 0) return 1;
    ll &ans = memo[n][prev][tight][leading];
    if(ans != -1) return ans;
    ans = 0;
    int ub = tight? (num[num.length() - n] - '0') : 9;
    if(leading || (!leading && prev != 0)){
        ans += dp(num, n - 1, 0, tight & (0 == ub), leading);
    }
    for(int dig = 1; dig <= ub; ++dig){
        if(dig != prev){
            ans += dp(num, n - 1, dig, tight & (dig == ub), 0);
        }
    }
    return ans;
}

ll solve(){
    ll a, b;
    cin >> a >> b;
    int toadd = 0;
    if(a == 0) toadd = 1;
    if(a != 0) a--;
    string r = to_string(b);
    int nr = r.length();
    string l = to_string(a);
    int nl = l.length();
    memset(memo, -1, sizeof memo);
    ll ans1 = dp(r, nr, -1, 1, 1);
    memset(memo, -1, sizeof memo);
    ll ans2 = dp(l, nl, -1, 1, 1);
    ll ans = ans1 - ans2 + toadd;
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