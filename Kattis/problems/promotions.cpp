#include "bits/stdc++.h"
using namespace std;
const int MAXN = 5000;

void dfs(int v, vector<int> graph[], bitset<MAXN> dp[]){
    dp[v][v] = 1;
    for(int w : graph[v]){
        if(dp[w] == 0) dfs(w, graph, dp);
        dp[v] |= dp[w];
    }
}
int main(){
    int a, b, e, p, u, v;
    scanf("%d %d %d %d", &a, &b, &e, &p);
    vector<int> graph[e], rgraph[e];
    for(int i = 0; i < p; ++i){
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }
    bitset<MAXN> dp[e], rdp[e];
    int ans_a = 0, ans_b = 0, no_possibility = 0;
    for(int i = 0; i < e; ++i){
        if(dp[i] == 0) dfs(i, graph, dp);
        if(rdp[i] == 0) dfs(i, rgraph, rdp);
        int cnt1 = dp[i].count(), cnt2 = rdp[i].count();
        if(e - cnt1 < a) ans_a++;
        if(e - cnt1 < b) ans_b++;
        if(cnt2 > b) no_possibility++;
    }
    printf("%d\n%d\n%d", ans_a, ans_b, no_possibility);
}