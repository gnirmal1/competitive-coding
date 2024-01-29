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


void solve(int n){
    bool flag = 1;
    for(int i = 1234; i <= 98765/n; ++i){
        set<char> digits;
        string denom = to_string(i), num = to_string(n*i);
        if(num.size() > 5) continue;
        if(i < 10000) denom = '0' + denom;
        for(int j = 0; j < denom.size(); ++j){
            digits.insert(denom[j]);
        }
        for(int j = 0; j < num.size(); ++j){
            digits.insert(num[j]);
        }
        if(digits.size() == 10){
            flag = 0;
            cout << num << " / " << denom << " = " << n << '\n';
        }
    }
    if(flag) cout << "There are no solutions for " << n << ".\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 
    int n;
    bool first = 1;
    while(true){
        cin >> n;
        if(n == 0) break;
        if(!first) cout << '\n';
        first = 0;
        solve(n);
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 