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



double ascent_h[5005], ascent_t[5005], descent_h[5005], descent_t[5005];
int a, d, H;
bool check(double t){
    int ind1 = upper_bound(ascent_t, ascent_t + a, t) - ascent_t;
    int ind2 = upper_bound(descent_t, descent_t + d, t) - descent_t;
    if(ind1 == 0 || ind2 == 0) return true;
    double h1 = (ascent_t[ind1]*ascent_h[ind1 - 1] - ascent_t[ind1 - 1]*ascent_h[ind1] + t*(ascent_h[ind1] - ascent_h[ind1 - 1]))/(ascent_t[ind1] - ascent_t[ind1 - 1]);
    double h2 = (descent_t[ind2]*descent_h[ind2 - 1] - descent_t[ind2 - 1]*descent_h[ind2] + t*(descent_h[ind2] - descent_h[ind2 - 1]))/(descent_t[ind2] - descent_t[ind2 - 1]);
    if(h1 < H - h2) return true;
    return false;
}

double solve(){
    cin >> a >> d;
    for(int i = 1; i <= a; ++i){
        int h, t;
        cin >> h >> t;
        ascent_h[i] = h + ascent_h[i - 1];
        ascent_t[i] = t + ascent_t[i - 1];
    }
    H = ascent_h[a];
    for(int i = 1; i <= d; ++i){
        int h, t;
        cin >> h >> t;
        descent_h[i] = h + descent_h[i - 1];
        descent_t[i] = t + descent_t[i - 1];
    }
    double lo = 0.0, hi = 1000000.0;
    for(int i = 0; i < 60; ++i){
        double mid = (lo + hi)/2;
        check(mid) ? lo = mid : hi = mid;
    }
    return hi;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(6) << fixed;
    // IO(""); 

    cout << solve() << '\n';
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 