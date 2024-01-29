#include "bits/stdc++.h"
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 
    int n, m;
    cin >> n >> m;
    vector<vector<int>> AL(n);
    vector<int> in_degree(n), res;
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        AL[a].push_back(b);
        in_degree[b]++;
    }
    queue<int> q;    

    for (int u = 0; u < n; ++u)
      if (in_degree[u] == 0)                     // next to be processed
        q.push(u);                              // smaller index first

    while (!q.empty()) {                        // Kahn's algorithm
      int u = q.front(); q.pop();
      res.push_back(u + 1);
      for (auto v : AL[u]) {
        --in_degree[v];                          // virtually remove u->v
        if (in_degree[v] == 0)          // not a candidate, skip
            q.push(v);                              // enqueue v in pq
      }
    }
    if(res.size() == n){
        for(int i : res) cout << i << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 