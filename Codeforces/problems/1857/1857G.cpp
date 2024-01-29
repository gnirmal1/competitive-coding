#include "bits/stdc++.h"
using namespace std;

# define int long long
constexpr int MOD = 998244353;

int binpow(int a, int b) {
    a %= MOD;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

class UnionFind {     
                            
private:
    vector<int> p, rank, setSize;                           
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


int solve(){
    int n, S;
    cin >> n >> S;
    vector<tuple<int, int, int>> edges;
    for(int i = 1; i < n; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.emplace_back(w, u, v);
    }
    sort(edges.begin(), edges.end());
    UnionFind ufds(n);
    int ans = 1;
    for(auto [w, u, v]: edges){
        int cnt = ufds.sizeOfSet(u)*ufds.sizeOfSet(v) - 1;
        ans *= binpow(S - w + 1, cnt);
        ans %= MOD;
        ufds.unionSet(u, v);
    }
    return ans;
}

signed main(){
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