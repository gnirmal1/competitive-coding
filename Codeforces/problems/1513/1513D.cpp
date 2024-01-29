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


class UnionFind {     
                            
private:
    vi p, rank, setSize;                           
    int numSets;

public:
    UnionFind(int N) {
        p.assign(N, 0); 
        for (int i = 0; i < N; ++i){
            p[i] = i;
        }
        rank.assign(N, 0);                           // optional speedup
        setSize.assign(N, 1);                        // optional speedup
        numSets = N;                                 // optional speedup
    }

    int findSet(int i) {
        int root = i;
        while(root != p[root]){
            root = p[root];
        }

        while(i != root){
            int next = p[i];            // william fiset non recursive implementation
            p[i] = root;
            i = next;
        }

        return root;
    
    }
    bool isSameSet(int i, int j) { 
        return findSet(i) == findSet(j); 
    }

    int numDisjointSets() { 
        return numSets;
    }     
    int sizeOfSet(int i) { 
        return setSize[findSet(i)];
    } 

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;                 // i and j are in same set
        int x = findSet(i), y = findSet(j);          // find both rep items
        if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
        p[x] = y;                                    // set x under y
        if (rank[x] == rank[y]) ++rank[y];           // optional speedup
        setSize[y] += setSize[x];                    // combine set sizes at y
        --numSets;                                   // a union reduces numSets
    }
};

ll solve(){
    int n, p;
    cin >> n >> p;
    vi a(n);
    priority_queue<pii> pq;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        pq.emplace(-a[i], i);
    }
    ll ans = 0;
    UnionFind dsu(n);
    while(!pq.empty() && dsu.numDisjointSets() > 1){
        auto [val, i] = pq.top(); pq.pop();
        val *= -1;
        int r = i + 1, l = i - 1;;
        while(r < n && !dsu.isSameSet(i, r) && a[r] % val == 0){
            dsu.unionSet(i, r);
            ans += min(val, p);
            r++;
        }

        while(l >= 0 && !dsu.isSameSet(i, l) && a[l] % val == 0){
            dsu.unionSet(i, l);
            ans += min(val, p);
            l--;
        }
    }
    return ans + (ll)p * (dsu.numDisjointSets() - 1);
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