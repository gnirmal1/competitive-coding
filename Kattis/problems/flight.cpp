#include "bits/stdc++.h"
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;

vi graph[2500];
pii not_allowed;
int n;

bool check(int u, int v){
    return (u == not_allowed.first && v == not_allowed.second) ||
            (v == not_allowed.first && u == not_allowed.second);
}

void dfs(int v, int p, int &maxdist, int &end, vi &dist){
    for(int w : graph[v]){
        if(w != p && !check(v, w)){
            dist[w] = dist[v] + 1;
            if(dist[w] > maxdist){
                end = w;
                maxdist = dist[w];
            }
            dfs(w, v, maxdist, end, dist);
        }
    }
}

pii center_and_diameter(int v){
    vi dist(n), dista(n), distb(n);
    int maxdist = 0, end = v;
    dfs(v, -1, maxdist, end, dist);
    maxdist = 0;
    dfs(end, -1, maxdist, end, dista);
    maxdist = 0;
    dfs(end, -1, maxdist, end, distb);
    if(maxdist == 0) return make_pair(v, 0);
    for(int i = 0; i < n; ++i){
        int d = max(dista[i], distb[i]);
        if(d == (maxdist + 1)/2) return make_pair(i, maxdist);
    }
    return make_pair(-1, -1);
}


void solve(){
    cin >> n;
    vector<pii> edges;
    for(int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        edges.emplace_back(u, v);
    }
    int min_diameter = 1e9;
    pii edge_removed, edge_added;
    for(auto [u, v] : edges){
        not_allowed = {u, v};
        auto [c1, d1] = center_and_diameter(u);
        auto [c2, d2] = center_and_diameter(v);
        int r1 = (d1 + 1)/2, r2 = (d2 + 1)/2;
        int new_diameter = max(max(d1, d2), r1 + r2 + 1);
        if(new_diameter < min_diameter){
            min_diameter = new_diameter;
            edge_removed = {u + 1, v + 1};
            edge_added = {c1 + 1, c2 + 1};
        }
    }
    cout << min_diameter << '\n';
    cout << edge_removed.first << " " << edge_removed.second << '\n';
    cout << edge_added.first << " " << edge_added.second << '\n';
}

int main(){
    solve();
}
