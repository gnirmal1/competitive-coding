#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;

constexpr ll INF = 1e9;
constexpr ll MOD = 1e9 + 7;

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

#define Sum(v) (accumulate(v.begin(), v.end(), 0ll))



int solve(){
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    cin >> a;
    sort(a.begin(), a.end());
    vector<vector<int>> serum = {{2, 2, 3}, {2, 3, 2}, {3, 2, 2}};
    int ans = 0;
    for(int k = 0; k < 3; ++k){
        ll pow = h;
        int uses = 0, cnt = 0;
        for(int i = 0; i < n; ++i){
            while(uses < 3 && a[i] >= pow){
                pow *= serum[k][uses];
                uses++;
            }
            if(a[i] < pow) {
                pow += (int)(a[i]/2);
                cnt++;
            }
            if(a[i] >= pow && uses >= 3) break;
        }
        ans = max(ans, cnt);
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

// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 