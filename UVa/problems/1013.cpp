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


constexpr ll INF = 1e18;
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


double edge_weight(int x1, int y1, int x2, int y2){
    return sqrt((x1 - x2)*(x1 - x2) + 
                (y1 - y2)*(y1 - y2));
}

int num_case = 1;
void solve(int n){
    vvi info;
    double total_pop = 0;
    for(int i = 0; i < n; ++i){
        int x, y, m;
        cin >> x >> y >> m;
        info.push_back({x, y, m});
        total_pop += m;
    }
    vector<pair<double, int>> cost(n, {INF, -1});
    vector<vector<pair<double, int>>> mst(n);
    vi vis(n);
    cost[0] = {0, -1};
    priority_queue<pair<double, int>> pq;
    pq.emplace(0, 0);
    while(!pq.empty()){
        auto [c, w] = pq.top(); pq.pop();
        if(vis[w]) continue;
        vis[w] = 1;
        if(w != 0){
            int v = cost[w].second;
            mst[v].emplace_back(-c, w);
            mst[w].emplace_back(-c, v);
        }
        for(int i = 0; i < n; ++i){
            double weight = edge_weight(info[w][0], info[w][1],
                                        info[i][0], info[i][1]);
            if(!vis[i] && weight < cost[i].first){
                cost[i] = {weight, w};
                pq.emplace(-weight, i);
            }
        }
    }

    vector<double> dp(n);
    function<void(int, int)> dfs = [&](int v, int p){
        for(auto [weight, w] : mst[v]){
            if(w == p) continue;
            dp[w] = max(dp[v], weight);
            dfs(w, v);
        }
    };
    dfs(0, -1);
    double ans = 0;
    for(int i = 0; i < n; ++i){
        ans += dp[i]*info[i][2];
    }
    ans /= total_pop;

    printf("Island Group: %d Average %.2lf\n\n", num_case, ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        solve(n);
        num_case++;
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 