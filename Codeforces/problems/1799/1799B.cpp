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

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int num1 = 0;;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] == 1) num1++;
    }
    if(num1 == n || n == 1){
        cout << "0\n";
        return;
    }
    else if(num1 != 0){
        cout << "-1\n";
        return;
    }
    vector<pair<int, int>> res;
    while(true){
        int d = 1e9 + 1;
        int j = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] < d){
                d = a[i];
                j = i;
            }
        }
        for(int i = 0; i < n; ++i){
            int &x = a[i];
            while(x > d){
                res.push_back({i + 1, j + 1});
                x = (x + d - 1)/d;
            }
        }
        bool flag = 1;
        for(int i = 0; i < n; ++i){
            if(a[i] != d) {
                flag = 0;
                continue;
            }
        }
        if(flag) break;
    }
    cout << res.size() << '\n';
    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 