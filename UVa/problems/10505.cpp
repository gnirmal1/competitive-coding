#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin >> n;
    map<int, vector<int>> graph;
    for(int i = 0; i < n; ++i){
        int cnt;
        cin >> cnt;
        for(int j = 0; j < cnt; ++j){
            int e;
            cin >> e;
            e--;
            if(e < n){
                graph[i].push_back(e);
                graph[e].push_back(i);
            }
        }
    }
    map<int, bool> color;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(color.find(i) == color.end()){
            queue<int> q;
            q.push(i);
            color[i] = 0;
            bool isBipartite = true;
            int l = 1, r = 0; // l means num vertices with color 0
            while(!q.empty()){
                int v = q.front();
                q.pop();
                for(int w : graph[v]){
                    if(color.find(w) == color.end()){
                        color[w] = 1 - color[v];
                        if(color[w]) r++;
                        else l++;
                        q.push(w);
                    }
                    else if(color[w] == color[v]){
                        isBipartite = false;
                    }
                }
            }
            if(isBipartite) ans += max(l, r);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    while(m--){
        cout << solve() << '\n';
    }
}