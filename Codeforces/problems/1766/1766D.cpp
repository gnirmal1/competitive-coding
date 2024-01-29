#include "bits/stdc++.h"
using namespace std;

// Template modified from https://usaco.guide/general/generic-code?lang=cpp#templates 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
# define int long long
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

const int MAXN = 1e7 + 1;

bool v[MAXN];
int len, sp[MAXN];

void Sieve(){
    sp[0] = sp[1] = 1;
	for (int i = 2; i < MAXN; i += 2) sp[i] = 2;//even numbers have smallest prime factor 2
	for (long long i = 3; i < MAXN; i += 2){
		if (v[i]) continue;
        sp[i] = i;
        for (long long j = i; (j*i) < MAXN; j += 2){
            if (!v[j*i]) {
                v[j*i] = true;
                sp[j*i] = i;
            }
        }
	}
}

void getPrimeFactorization(int n, vector<int> &primes){
    while(n != 1){
        primes.push_back(sp[n]);
        int x = sp[n];
        while(n != 1 && n % x == 0) n /= x;
    }
}

int solve(){
    int x, y;
    cin >> x >> y;
    if(abs(x - y) == 1) return -1;
    if(__gcd(x, y) != 1) return 0;
    else if(x%2 == 1 && y%2 == 1) return 1;
    if(y < x) swap(x, y);
    vector<int> primes;
    int num = y - x;
    int ans = 1e9;
    getPrimeFactorization(num, primes);
    for(int p : primes){
        int t = (x/p) + 1;
        int z = t*p - x;
        ans = min(z, ans);
    }
    return ans;
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 
    Sieve();
    int t;
    cin >> t;
    while(t--){
        cout << solve() << '\n';
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 