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


const int MAXN = 101;

void solve(){
    int n;
    cin >> n;
    vector<int> a(MAXN, 0), b(MAXN, 0), cnta(MAXN, 0), cntb(MAXN, 0);
    for(int k = 0; k < n; ++k){
        int x, y;
        cin >> x >> y;
        a[x]++;
        b[y]++;
        for(int i = 0; i < MAXN; ++i){
            cnta[i] = a[i];
            cntb[i] = b[i];
        }
        int i = 1, j = MAXN - 1;
        int ans = 0;
        while(j > 0 && i < 101){
            if(!cnta[i]){
                i++;
                continue;
            }
            if(!cntb[j]){
                j--;
                continue;
            }
            if(i + j > ans) ans = i + j;
            if(cnta[i] > cntb[j]){
                cnta[i] -= cntb[j];
                cntb[j] = 0;
            }
            else{
                cntb[j] -= cnta[i];
                cnta[i] = 0;
            }
        }

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