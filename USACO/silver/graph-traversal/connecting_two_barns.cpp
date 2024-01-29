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

ll solve(){
    int n, m;
    cin >> n >> m;
    vi comp(n);
    vvi graph(n), comp_al(n + 1);
    int cc = 1;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    function<void(int)> dfs = [&](int v){
        comp[v] = cc;
        comp_al[cc].push_back(v);
        for(auto w : graph[v]){
            if(comp[w] == 0){
                dfs(w);
            }
        }
    };
    for(int i = 0; i < n; ++i){
        if(comp[i] == 0){
            dfs(i);
            Sort(comp_al[cc]);
            cc++;
        }
    }
    ll ans = 1e18;
    if(comp[0] == comp[n - 1]) return 0;
    vi temp_s = comp_al[comp[0]], temp_d = comp_al[comp[n - 1]];

    for(int i = 2; i < cc; ++i){
        ll sum_s = 1e18, sum_d = 1e18;
        for(auto v : comp_al[i]){
            auto it = lower_bound(temp_s.begin(), temp_s.end(), v);
            if(it != temp_s.end()) sum_s = min(sum_s, ll (*it - v) * (*it - v));
            if(it != temp_s.begin()){
                --it;
                sum_s = min(sum_s, ll (*it - v) * (*it - v));
            }

            it = lower_bound(temp_d.begin(), temp_d.end(), v);
            if(it != temp_d.end()) sum_d = min(sum_d, ll (*it - v) * (*it - v));
            if(it != temp_d.begin()){
                --it;
                sum_d = min(sum_d, ll (*it - v) * (*it - v));
            }
        }
        ans = min(ans, sum_s + sum_d);
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