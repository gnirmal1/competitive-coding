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


struct info{
    int catalog_price, pickup_cost, mileage;
    info() : catalog_price(0), pickup_cost(0), mileage(0){}
    info(int p, int q, int k) : catalog_price(p), pickup_cost(q), mileage(k){}
};

void solve(){
    int n, m;
    cin >> n >> m;
    map<string, string> spy_to_car;
    map<string, info> car_info;
    map<string, ll> ans;
    for(int i = 0; i < n; ++i){
        string car;
        int p, q, k;
        cin >> car >> p >> q >> k;
        car_info[car] = info(p, q, k);
    }
    while(m--){
        int t;
        string s;
        char e;
        cin >> t >> s >> e;
        if(e == 'p'){
            string C;
            cin >> C;
            if(ans[s] == -1) continue;
            if(spy_to_car.find(s) != spy_to_car.end()) ans[s] = -1;
            else {
                ans[s] += car_info[C].pickup_cost;
                spy_to_car[s] = C;
            }
        }
        else if(e == 'r'){
            int d;
            cin >> d;
            if(ans[s] == -1) continue;
            if(spy_to_car.find(s) == spy_to_car.end()) ans[s] = -1;
            else{
                ans[s] += d*car_info[spy_to_car[s]].mileage;
                spy_to_car.erase(s);
            }
        }
        else{
            int percent;
            cin >> percent;
            if(ans[s] == -1) continue;
            if(spy_to_car.find(s) == spy_to_car.end()) ans[s] = -1;
            else{
                ans[s] += (percent*car_info[spy_to_car[s]].catalog_price + 99)/100;
            }
        }
    }
    for(auto &[spy, car] : spy_to_car){
        ans[spy] = -1;
    }
    for(auto &[spy, res] : ans){
        if(res == -1) cout << spy << " INCONSISTENT\n";
        else cout << spy << " " << res << '\n';
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
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 