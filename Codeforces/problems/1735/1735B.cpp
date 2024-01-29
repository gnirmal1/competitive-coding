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
        int ans = 0;
        int a1;
        cin >> a1;
        for(int i = 1; i < n; ++i){
            int x;
            cin >> x;
            ans += x/(2*a1 - 1);
            if (x%(2*a1 - 1) == 0) ans--;
        }
        cout << ans << '\n';
    }
}
