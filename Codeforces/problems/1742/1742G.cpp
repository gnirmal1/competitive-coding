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


int turnOffBits(int x, int i){
    int ans = 0;
    for(int j = 0; j <= i; ++j){
        int y = (1 << j);
        if(y & x) ans |= y;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<bool> used(n, false);
    int mx = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int hi = log2(mx) + 1, j = 0, i = hi - 1, temp = 1<<hi;
    while(i >= 0){
        int mxnum = -1, mxInd = -1;
        for(int k = 0; k < n; ++k){
            if(!used[k]){
                if(mxnum == -1 || (mxnum & (~(temp))) < (a[k] & (~(temp)))) {
                    mxnum = a[k];
                    mxInd = k;
                }
            }
        }
        temp |= turnOffBits(mxnum, hi - 1);
        i--;
        if(mxnum != -1){
            used[mxInd] = true;
            b[j] = mxnum;
            j++;
            while(i >= 0 && ((1<<i) & (mxnum))){
                temp |= (1 << i);
                i--;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        if(!used[i]){
            b[j] = a[i];
            j++;
        }
    }
    cout << b << '\n';
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