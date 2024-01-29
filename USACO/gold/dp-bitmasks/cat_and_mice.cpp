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

int n;
double m;
double dist[16][16], out[16], mult[16];
double cost(int x1, int y1, int x2, int y2){
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

bool can(double v0){
    int hi = (1 << (n + 1));
    vector<vector<double>> dp(n + 1, vector<double>(hi, INF));
    dp[0][1] = 0;
    bool ans = 0;
    for(int mask = 1; mask < hi; ++mask){
        if(!(mask&1)) continue;
        for(int last = 0; last <= n; ++last){
            if((mask & (1 << last)) == 0) continue;
            if(mask > 1 && last == 0) continue;
            if(mask == hi - 1){
                ans |= (dp[last][mask] <= out[last] + 1e-9);
            }
            int num_mice = __builtin_popcount(mask) - 1;
            for(int i = 0; i <= n; ++i){
                if((mask & (1 << i)) == 0){
                    int newmask = mask ^ (1 << i);
                    double time_to_reach = dist[last][i]/(mult[num_mice]*v0);
                    double newtime = time_to_reach + dp[last][mask];
                    if(newtime <= out[i] + 1e-9){
                        dp[i][newmask] = min(dp[i][newmask], newtime);
                    }
                }
            }
        }
    }
    return ans;
}

double solve(){
    cin >> n;
    vpii coordinates = {{0, 0}};
    for(int i = 1; i <= n; ++i){
        int x, y;
        cin >> x >> y >> out[i];
        coordinates.emplace_back(x, y);
    }
    cin >> m;
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            auto [x1, y1] = coordinates[i];
            auto [x2, y2] = coordinates[j];
            dist[i][j] = cost(x1, y1, x2, y2);
        }
    }
    mult[0] = 1;
    for(int i = 1; i <= n; ++i){
        mult[i] = mult[i - 1]*m;
    }
    double l = 0, r = INF, mid;
    for(int i = 0; i < 60; ++i){
        mid = l + (r - l)/2;
        if(can(mid)) r = mid;
        else l = mid;
    }
    return mid;
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