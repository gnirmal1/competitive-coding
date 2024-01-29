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

int solve(){
    ll n, c;
    cin >> n >> c;
    vector<ll> a(n);
    cin >> a;
    vector<ll> costs;
    for(ll i = 1; i <= n; ++i){
        costs.push_back(a[i - 1] + min(i, n + 1 - i));
    }
    Sort(costs);
    vector<ll> temp = costs;
    for(int i = 1; i < n; ++i){
        costs[i] += costs[i - 1];
    }
    int ans = 0;
    for(ll i = 0; i < n; ++i){
        if(a[i] + i + 1 > c) continue;
        ans = max(ans, 1);
        ll z = c - (a[i] + i + 1), x = a[i] + min(i + 1, n - i);
        int pos1 = upper_bound(costs.begin(), costs.end(), z) - costs.begin();
        int pos2 = upper_bound(temp.begin(), temp.end(), x) - temp.begin();
        if(pos2 > pos1) ans = max(ans, pos1 + 1);
        else{
            int y = pos1 + 1;
            if(pos1 == n || costs[pos1 - 1] - temp[pos2 - 1] + temp[pos1] > z)
            y--;
            ans = max(ans, y);
        }
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