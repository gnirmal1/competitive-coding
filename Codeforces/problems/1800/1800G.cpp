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


vector<vector<int>> AL;
vector<bool> symmetrical;
map<vector<int>, int> tree_hash; // this uses different logic to bypass
                                //hash collision problems;
int last;

int dfs(int v, int parent){
    vector<int> children;
    for(int w : AL[v]){
        if(w == parent) continue;
        children.push_back(dfs(w, v));
    }
    Sort(children);
    if(tree_hash.find(children) == tree_hash.end()){
        map<int, int> cnt_types;
        for(int hash_val : children){
            cnt_types[hash_val]++;
        }
        int num_odd = 0, middle_sym = 1;
        for(auto &[hash_val, cnt] : cnt_types){
            if(cnt % 2 == 1){
                num_odd++;
                middle_sym &= symmetrical[hash_val];
            }
        }
        symmetrical[last] = (num_odd < 2) && middle_sym; 
        tree_hash[children] = last++;
    }
    return tree_hash[children];
}


int solve(){
    int n;
    cin >> n;
    AL.assign(n, {});
    symmetrical.assign(n + 1, 0);
    tree_hash.clear();
    tree_hash[{}] = 0;
    symmetrical[0] = true; // node with no children is symmetrical and
                        // its hash is set as 0
    last = 1;
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        u--; v--;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }
    return symmetrical[dfs(0, 0)];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int t;
    cin >> t;
    while(t--){
        puts(solve()? "YES" : "NO");
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 