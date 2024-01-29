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
        vector<int> a(n + 1);
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        vector<long long> prefix(n + 1, 0);
        for(int i = 1; i <= n; ++i){
            prefix[i] = prefix[i - 1];
            if (a[i] < i) prefix[i]++;
        }
        long long ans = 0;
        for(int j = 1; j <= n; ++j){
            if (a[j] < j && a[j] > 0) ans += prefix[a[j] - 1];
        }
        cout << ans << '\n';
    }
}
