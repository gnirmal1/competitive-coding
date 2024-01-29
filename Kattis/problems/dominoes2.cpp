#include "bits/stdc++.h"
using namespace std;



using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvpii = vector<vpii>;



vector<bool> vis;
vvi AL;
int cnt;
void dfs(int v){
    vis[v] = true;
    cnt++;
    for(int w : AL[v]){
        if(!vis[w])
        dfs(w);
    }
}


int solve(){
    int n, m, l;
    cin >> n >> m >> l;
    AL.assign(n, {});
    vis.assign(n, false);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;
        AL[a].push_back(b);
    }
    int ans = 0;
    for(int i = 0; i < l; ++i){
        int z;
        cin >> z;
        z--;
        if(!vis[z]){
            cnt = 0;
            dfs(z);
            ans += cnt;
        }
    }
    return ans;
}

int main(){
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