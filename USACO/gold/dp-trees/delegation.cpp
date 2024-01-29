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

vi graph[100000];
bool flag = 1;
int dfs(int v, int p, int k){
    vi lines;
    if(!flag) return 0;
    for(int w : graph[v]){
        if(w != p){
            lines.push_back(dfs(w, v, k) + 1);
        }
    }
    Sort(lines);
    int i = 0, j = lines.size() - 1;
    int cnt = 0, last = 0;
    while(i < j){
        if(lines[i] == k) i++;
        else if(lines[j] == k) j--;
        else if(lines[i] + lines[j] == k){
            i++;
            j--;
        }
        else if(lines[i] + lines[j] > k){
            last = lines[j];
            j--;
            cnt++;
        }
        else{
            last = lines[i];
            i++;
            cnt++;
        }
    }
    if(i == j && lines[i] != k){
        last = lines[i];
        cnt++;
    }
    if(cnt <= 1) return last;
    flag = 0;
    return 0;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int k = n - 1;
    string ans = string(k, '0');
    for(int i = 1; i*i <= k; ++i){
        if(k%i == 0){
            flag = 1;
            dfs(0, -1, i);
            if(flag) ans[i - 1] = '1';
            flag = 1;
            dfs(0, -1, k/i);
            if(flag) ans[k/i - 1] = '1';
        }
    }
    cout << ans;
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