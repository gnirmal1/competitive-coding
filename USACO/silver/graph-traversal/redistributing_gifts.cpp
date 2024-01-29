#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;
typedef vector<int> vi;


vvi graph;
vvi reverse_graph;
vector<int> visited;
int visited_token = 1;
vi component;
vi postvisit;

int i = 0;
int num_v;
int comp = 1;


void Postvisit(int v){
  if (i >= num_v) return;
  postvisit[i] = v;
  i++;
}

void dfs(int v, vvi &g){
  visited[v] = visited_token;
  component[v] = comp;

  for (int w : g[v]){
    if (visited[w] != visited_token){
      dfs(w, g);
    }
  }
  Postvisit(v);
}

void scc(){
    for (int v = 0; v < num_v; ++v){
        if (visited[v] != visited_token){
            dfs(v, reverse_graph);
        }
    }
    visited_token++; // effectively resets visited array
    for(int k = num_v - 1; k >= 0; --k){
        if (visited[postvisit[k]] != visited_token){
            dfs(postvisit[k], graph);
            comp++;
        }
    }
}

int main() {
  cin >> num_v;
  graph.assign(num_v, {});
  reverse_graph.assign(num_v, {});
  vvi pref(num_v, vi(num_v));
  for(int i = 0; i < num_v; ++i){
    bool flag = 1;
    for(int j = 0; j < num_v; ++j){
        int x;
        cin >> x;
        x--;
        pref[i][j] = x;
        if(flag) {
            graph[i].push_back(x);
            reverse_graph[x].push_back(i);
        }
        if(x == i) flag = 0;
    }
  }
  visited.assign(num_v, 0);
  component.assign(num_v, 0);
  postvisit.assign(num_v, 0);

  scc();
  vi ans(num_v);
  for(int i = 0; i < num_v; ++i){
    for(int j = 0; j < num_v; ++j){
        if(component[i] == component[pref[i][j]]) {
            ans[i] = pref[i][j] + 1;
            break;
        }
    }
  }
  for(int i = 0; i < num_v; ++i) cout << ans[i] << '\n';
  return 0;
}
