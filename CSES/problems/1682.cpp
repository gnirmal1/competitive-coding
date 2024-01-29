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
  int num_e; // number of edges
  cin >> num_v >> num_e;
  graph.assign(num_v, {});
  reverse_graph.assign(num_v, {});
  while(num_e--){
    int v, w;
    cin >> v >> w;
    v--; w--;
    graph[v].push_back(w);
    reverse_graph[w].push_back(v); // for undirected graph
  }

  visited.assign(num_v, 0);
  component.assign(num_v, 0);
  postvisit.assign(num_v, 0);

  scc();
  if(comp == 2) cout << "YES\n";
  else{
    cout << "NO\n";
    int a, b;
    for(int i = 0; i < num_v; ++i){
        if(component[i] > 1) b = i + 1;
        else a = i + 1;
    }
    cout << a << " " << b << '\n';
  }
  return 0;
}
