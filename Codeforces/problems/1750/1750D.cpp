#include "bits/stdc++.h"
using namespace std;

// Template from https://usaco.guide/general/generic-code?lang=cpp#templates 

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

#define sum(v) (accumulate(v.begin(), v.end(), 0ll))
#define sort(v) (sort(v.begin(), v.end()))


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
// __builtin_ctzl() for long long and __ builtin_popcount()
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


ll PIE(int n, int upper, vi &primes){
    int num_primes = primes.size();
    int ans = 0;
    for(int mask = 1; mask < (1 << num_primes); ++mask){
        int x = 0, prod = 1;;
        while(x < num_primes){
            int pow = (1 << x);
            if(pow & mask) prod *= primes[x];
            x++;
        }
        int parity = __builtin_popcount(mask);
        if(parity&1) ans += (upper/prod);
        else ans -= (upper/prod);
    }
    return ans;
}


int solve(){
    int n, m;
    cin >> n >> m;
    vi a(n);
    cin >> a;
    vi primes; int temp = a[0];
    for(int i = 2; i*i <= a[0]; ++i){
        if(temp % i == 0) primes.push_back(i);
        while(temp % i == 0) temp /= i;
    }
    if(temp > 1) primes.push_back(temp);
    ll ans = 1;
    for(int i = 1; i < n; ++i){
        if(a[i - 1] % a[i] != 0) return 0;
        int upper = m/a[i], k = a[i - 1] / a[i];
        vi new_primes;
        for(int i : primes) if(k % i == 0) new_primes.push_back(i);
        int invalid = PIE(k, upper, new_primes);
        ans = ans * (upper - invalid) % MOD;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int t;
    cin >> t;
    while(t--){
        cout << solve() << '\n';
    }
}