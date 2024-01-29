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

map<int, vpii> mp;

void solve(){
    int m, s;
    cin >> m >> s;
    vpii coins(m);
    cin >> coins;
    queue<pii> q;
    vvpii dist(s + 1, vpii(s + 1, {-1, -1}));
    dist[0][0] = {0, 0};
    q.emplace(0, 0);
    for(auto [i, j] : mp[s*s]) {
        dist[i][j] = {0, 1};
        q.emplace(i, j);
    }
    while(!q.empty()){
        auto [i, j] = q.front(); q.pop();
        for(auto [c, it] : coins){
            int x = i + c, y = j + it;
            if(x*x + y*y <= s*s){
                if (dist[x][y].first == -1){
                    dist[x][y] = {dist[i][j].first + 1, dist[i][j].second};
                    q.emplace(x, y);
                }
                else if(dist[i][j].second != dist[x][y].second){
                    cout << dist[i][j].first + dist[x][y].first + 1 << '\n';
                    return;
                }
            }
        }
    }
    cout << "not possible\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int id = 0;
    for(int i = 0; i <= 300; ++i){
        for(int j = 0; j <= 300; ++j){
            if(i*i + j*j > 90000) break;
            pii p = make_pair(i, j);
            mp[i*i + j*j].push_back(p);
        }
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 