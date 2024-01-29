#include "bits/stdc++.h"
using namespace std;


int solve(){
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string t;
        cin >> t;
        vector<int> root(26), child(26, -1), parent(26, -1);
        for(int i = 0; i < 26; ++i) root[i] = i;
        string ans = "";
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            int x = t[i] - 'a';
            if (parent[x] != -1) {
                ans += (char)(parent[x] + 97);
                continue;
            }
            for(int j = 0; j < 26; ++j){
                if(child[j] == -1 && x != j && (root[j] != x || cnt == 25)){
                    child[j] = x;
                    parent[x] = j;
                    cnt++;
                    ans += (char)(parent[x] + 97);
                    if (cnt > 25) break;
                    while(child[x] != -1){
                        root[x] = root[j];
                        x = child[x];
                    }
                    root[x] = root[j];
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
}
