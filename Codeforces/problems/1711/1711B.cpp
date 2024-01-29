#include "bits/stdc++.h"
using namespace std;


int solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    vector<int> AL(n, 0);
    vector<pair<int, int>> edgelist(m);
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        x--; y--;
        AL[x]++;
        AL[y]++;
        edgelist[i].first = x;
        edgelist[i].second = y;
    }
    if (!(m&1)) return 0;
    int ans = 1e9;
    for(int i = 0; i < m; ++i){
        int a = edgelist[i].first, b = edgelist[i].second;
        if(AL[a]%2 == 0 && AL[b]%2 == 0) ans = min(ans,arr[a] + arr[b]);
        if(AL[a]%2 == 1) ans = min(ans, arr[a]);
        if(AL[b]%2 == 1) ans = min(ans, arr[b]);
    }
    return ans;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cout << solve() << '\n';
    }
}
