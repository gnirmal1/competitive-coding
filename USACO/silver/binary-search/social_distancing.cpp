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

bool ok(int n, vector<pair<ll, ll>> &intervals, ll D){
    ll sz = intervals[0].second - intervals[0].first + 1;
    ll totalfit = (sz + D - 1)/D;
    ll rem = sz % D;
    ll next = rem ? intervals[0].second + D - rem + 1: intervals[0].second + 1; 
    int m = intervals.size();
    for(int i = 1; i < m; ++i){
        if(next > intervals[i].second) continue;
        ll sz = (intervals[i].second - max(next, intervals[i].first) + 1);
        totalfit += (sz + D - 1)/D;
        rem = sz % D;
        next = rem ? intervals[i].second + D - rem + 1: intervals[i].second + 1; 
    }
    return totalfit >= n;
}

void solve(){
    ifstream cin ("socdist.in");
    ofstream cout ("socdist.out");
    int n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> intervals(m);
    for(int i = 0; i < m; ++i){
        cin >> intervals[i].first >> intervals[i].second;
    }
    Sort(intervals);
    ll lo = 1, hi = 1e18 + 1, ans = -1;
    while(lo <= hi){
        ll mid = lo + (hi - lo)/2;
        if(ok(n, intervals, mid)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    cout << ans;
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