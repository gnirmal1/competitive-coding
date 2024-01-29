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

int dp[300], h, k, ans, MAXN = 20;
vi max_perm;
void check(vi & permutation){
    memset(dp, 0, sizeof dp);
    for(int sum = 0; sum < 300; ++sum){
        if(dp[sum] < h){
            for(int coin : permutation){
                dp[sum + coin] = dp[sum + coin] == 0? dp[sum] + 1 : min(dp[sum] + 1, dp[sum + coin]);
            }
        }
        if(sum > 0 && dp[sum] == 0){
            if(ans < sum - 1){
                ans = sum - 1;
                max_perm = permutation;
            }
            return;
        }
    }
}
void combination(vi &permutation, int left, int sz){
    if(sz == 0){
        check(permutation);
        return;
    }
    for(int i = left; i <= MAXN; ++i){
        permutation.push_back(i);
        combination(permutation, i + 1, sz - 1);
        permutation.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    while(true){
        cin >> h >> k;
        ans = 0;
        MAXN = min(h*10, 35);
        if(h == 0 && k == 0) break;
        if(h == 0){
            for(int j = 1; j <= k; ++j)
            printf("%3d", j);
            printf(" ->%3d\n", 0);
            continue;
        }
        if(k == 0){
            printf(" ->%3d\n", 0);
            continue;
        }
        vi perm = {1};
        combination(perm, 2, k - 1);
        for(int j : max_perm)
        printf("%3d", j);
        printf(" ->%3d\n", ans);
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 