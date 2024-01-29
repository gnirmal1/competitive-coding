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


ll memob[301][301][20][20][2], memoa[301][301][20][20][2],
     digits[301];

ll dp(int i, int j, string &num, int l, int r, bool tight){
    if(l > r || i > j) return 1;
    ll ans = 0;
    int dig = digits[i]; 

    int ubl = tight? (num[l] - '0') : 9;
    if(dig <= ubl){
        ans += dp(i + 1, j, num, l + 1, r, tight & (dig == ubl));
    }

    int ubr = tight? (num[r] - '0') : 9;
    if(dig <= ubr) {
        ans += dp(i, j, num, l, r - 1, tight);
    }

    ans += dp(i + 1, j, num, l, r, tight);
    return ans;
}

void solve(){
    ll n, a, b;
    cin >> n >> a >> b;
    a--;
    for(int i = 1; i <= n; ++i){
        cin >> digits[i - 1];
    }
    string numb = to_string(b);
    int nb = numb.length();
    string numa = to_string(a);
    int na = numa.length();
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--; r--;
        ll ans1 = dp(l, r, numb, 0, nb - 1, 1);
        cout << ans1 << '\n';
        ll ans2 = dp(l, r, numa, 0, na - 1, 1);
        cout << ans2 << '\n';
        ll ans = ans1 - ans2;
        cout << ans << '\n';
    }
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