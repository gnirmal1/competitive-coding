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
        string T;
        cin >> T;
        T = 'x' + T;
        long long ans = 0;
        vector<bool> vis(n + 1, false);
        for(int i = 1; i <= n; ++i){
            if(T[i] == '0'){
                for(int j = i; j <= n; j += i){
                    if(T[j] == '0' && !vis[j]){
                        ans += i;
                        vis[j] = true;
                    }
                    if(T[j] == '1') break;
                }
            }
        }
        cout << ans << '\n';
    }
}
