#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int finish, routes;
bool vis[22], reachable[22], AM[22][22];
vector<set<int>> graph;
vi res;

void dfs(int v){
  reachable[v] = true;
  for (int w : graph[v]){
    if (!reachable[w]){
      dfs(w);
    }
  }
}

void solve(int v){
    if(v == finish){
        printf("1");
        for(int x : res){
            printf(" %d", x);
        }
        printf("\n");
        routes++;
        return;
    }
    for(int w : graph[v]){
        if(!vis[w] && reachable[w]){
            res.push_back(w + 1);
            vis[w] = true;
            solve(w);
            res.pop_back();
            vis[w] = false;
        }
    }
}

int main(){
    int lineCount = 0;
    while(cin >> finish){
        finish--;
        graph.assign(21, {}); res.clear();
        memset(vis, false, sizeof vis);
        memset(reachable, false, sizeof reachable);
        while(true){
            int a, b;
            cin >> a >> b;
            if(a == 0 && b == 0) break;
            a--; b--;
            graph[a].insert(b);
            graph[b].insert(a);
        }
        routes = 0;
        vis[0] = true;
        dfs(finish);
        printf("CASE %d:\n", ++lineCount);
        if(reachable[0]) solve(0);
        printf("There are %d routes from the firestation to streetcorner %d.\n", routes, finish + 1);
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 