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

int k;
const int MAXL = 30, MAXN = 2e5 + 1;
int Trie[MAXN*MAXL][2];
vi a;
void add(int num){
    int root = 0;
    for(int i = MAXL - 1; i >= 0; --i){
        bool bit = (num & (1 << i));
        if(Trie[root][bit] == -1){
            k++;
            Trie[k][0] = Trie[k][1] = -1;
            Trie[root][bit] = k;
        }
        root = Trie[root][bit];
    }
}


int query(int num){
    int root = 0, ans = 0;
    for(int i = MAXL - 1; i >= 0; --i){
        bool bit = (num & (1 << i));
        if(Trie[root][bit] == -1) bit = 1 - bit;    
        root = Trie[root][bit];
        ans += (bit << i);

    }
    return ans;
}

ll dnc(int l, int r, int b){
    if(b < 0) return 0;
    int mid = r, pow = 1 << b;
    while(mid >= l && a[mid] & pow) mid--;
    if(mid == r || mid < l) return dnc(l, r, b - 1);
    k = 0;
    Trie[0][0] = Trie[0][1] = -1;
    for(int i = mid + 1; i <= r; ++i) {
        add(a[i]);
    }
    int mn = 2e9;
    for(int i = l; i <= mid; ++i){
        mn = min(mn, a[i]^query(a[i]));
    }
    return mn + dnc(l, mid, b - 1) + dnc(mid + 1, r, b - 1);
}


ll solve(){
    int n;
    cin >> n;
    set<int> temp;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        temp.insert(x);
    }
    int sz = temp.size();
    for(auto el : temp) a.push_back(el);
    memset(Trie, -1, sizeof Trie);
    return dnc(0, sz - 1, MAXL - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    cout << solve() << '\n';
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 