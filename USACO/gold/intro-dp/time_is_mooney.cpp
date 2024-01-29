#include "bits/stdc++.h"
using namespace std;

using vi = vector<int>;
constexpr int INF = 1e9;

const int MAXN = 1001, MAXT = 1001;
vi graph[MAXN];
int memo[MAXN][MAXT], money[MAXN], C;

// v is the current vertex and t is the number of days travelled till now
int dp(int v, int t){ 
    if(t == MAXT) return -INF; // invalid journey
    int &ans = memo[v][t];
    if(ans != -1) return ans;
    ans = v ? -INF : -C*t*t; // if we are vertex 0 we can end the journey here, 
                            // but for anything else we cant end it here
    for(int w : graph[v]){
        ans = max(ans, dp(w, t + 1));
    }
    ans += money[v];
    return ans;
}

void solve(){
    ifstream cin ("time.in");
    ofstream cout ("time.out");
    int n, m;
    cin >> n >> m >> C;
    for(int i = 0; i < n; ++i){
        cin >> money[i];
    }
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--; b--;           // 0 based indexing
        graph[a].push_back(b);
    }
    memset(memo, -1, sizeof memo);


    cout << dp(0, 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    solve();
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 