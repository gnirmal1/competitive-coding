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



void solve(){
    int n;
    cin >> n;
    vi city(25);
    for(int i = 0; i < n; ++i){
        int a, b, people;
        cin >> a >> b >> people;
        city[5*a + b] = people;
    }
    int cost = 1e9;
    vi optimal;
    for(int a = 0; a < 25; ++a){
        for(int b = a + 1; b < 25; ++b){
            for(int c = b + 1; c < 25; ++c){
                for(int d = c + 1; d < 25; ++d){
                    for(int e = d + 1; e < 25; ++e){
                        int sum = 0;
                        for(int area = 0; area < 25; ++area){
                            if(city[area] == 0) continue;
                            int mn = 1e9;
                            for(int office : {a, b, c, d, e}){
                                int i1 = office / 5;
                                int j1 = office % 5;
                                int i2 = area / 5;
                                int j2 = area % 5;
                                mn = min(mn, abs(i1 - i2) + abs(j1 - j2));
                            }
                            sum += city[area]*mn;
                        }
                        if(sum < cost){
                            cost = sum;
                            optimal = {a, b, c, d, e};
                        }
                    }
                }
            }
        }
    }
    bool start = 1;
    for(int i : optimal){
        if(!start) cout << " ";
        start = 0;
        cout << i;
    }
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
        cout << '\n';
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 