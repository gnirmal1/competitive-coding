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
    int n, c;
    cin >> n >> c;
    vector<int> a(101, 0);
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a[x]++;
    }
    int ans = 0;
    for(int i : a){
        ans += min(i, c);
    }
    cout << ans << '\n';
    }
}