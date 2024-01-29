#include "bits/stdc++.h"
using namespace std;

// Template modified from https://usaco.guide/general/generic-code?lang=cpp#templates 
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

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
    int n, t;
    cin >> n >> t;
    vi diff(n + 1);
    map<int, int> cheersf, cheersb;
    diff[0] = 1;
    cheersf[1] = 0;
    for(int i = 1; i <= n; ++i){
        int a;
        cin >> a >> diff[i];
        if(a > 0 && (cheersf.find(a) == cheersf.end() || diff[i] < cheersf[a])){
            cheersf[a] = i;
        }
        else if(a < 0 && (cheersb.find(-a) == cheersb.end() || diff[i] < cheersb[-a])){
            cheersb[-a] = i;
        }
    }
    int m = 2*t;
    vector<queue<int>> buckets(m + 1);
    vi dist(m + 1, INF);
    vpii par(m + 1);
    dist[0] = 0;
    buckets[0].push(0);
    for(int d = 0; d <= m; d += (buckets[d].empty())){
        if(buckets[d].empty()) continue;
        int v = buckets[d].front(); buckets[d].pop();
        if(d > dist[v]) continue;
        if(v == t) break;
        for(auto [enthu, index] : cheersf){
            int next = v + enthu;
            if(next > m) break;
            if(d + diff[index] < dist[next]){
                dist[next] = d + diff[index];
                par[next] = {v, index};
                buckets[dist[next]].push(next);
            }
        }
        for(auto [enthu, index] : cheersb){
            int next = v - enthu;
            if(next <= 0) break;
            if(d + diff[index] < dist[next]){
                dist[next] = d + diff[index];
                par[next] = {v, index};
                buckets[dist[next]].push(next);
            }
        }
    }
    vi res;
    int x = t;
    while(x != 0){
        auto [p, ind] = par[x];
        res.push_back(ind + 1);
        x = p;
    }
    cout << res.size() << '\n';
    for(int i : res){
        cout << i << " ";
    }
    cout << '\n';

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