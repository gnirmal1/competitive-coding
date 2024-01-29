#include "bits/stdc++.h"
using namespace std;

// Template modified from https://usaco.guide/general/generic-code?lang=cpp#templates 

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

using namespace __gnu_pbds;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
int memo[1001][1001][2];
int dp(int l, int r, bool dir, vi &p){
    if(l == 0 && r == n) return 0;
    int &ans = memo[l][r][dir];
    if(ans != -1) return ans;
    ans = 1e9;
    int len = n - r + l;
    if(dir){
        if(r + 1 <= n){
            ans = min(ans, len*(p[r + 1] - p[r]) + dp(l, r + 1, 1, p));
        }
        if(l - 1 >= 0){
            ans = min(ans, len*(p[r] - p[l - 1]) + dp(l - 1, r, 0, p));
        }
    }
    else{
        if(r + 1 <= n){
            ans = min(ans, len*(p[r + 1] - p[l]) + dp(l, r + 1, 1, p));
        }
        if(l - 1 >= 0){
            ans = min(ans, len*(p[l] - p[l - 1]) + dp(l - 1, r, 0, p));
        }
    }
    return ans;
}

void solve(){
    ifstream fin ("cowrun.in");
    ofstream fout ("cowrun.out");
    fin >> n;
    vi p(n + 1);
    for(int i = 1; i <= n; ++i){
        fin >> p[i];
    }
    Sort(p);
    int start = lower_bound(p.begin(), p.end(), 0) - p.begin();
    memset(memo, -1, sizeof memo);
    fout << dp(start, start, 1, p) << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    vector<int> count(31);
    for(int i = 2; i <= 30; ++i){
        if(count[i] != 0) continue;
        for(int j = i; j <= 30; j += i){
            count[j]++;
        }
    }
    cout << count << '\n';
    // solve();
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 