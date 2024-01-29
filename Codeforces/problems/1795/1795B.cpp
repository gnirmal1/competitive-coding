#include "bits/stdc++.h"
using namespace std;

int solve(){
    int n, k;
    cin >> n >> k;
    bool l = 0, r = 0;
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        l |= x == k;
        r |= y == k;
    }
    return l && r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int t;
    cin >> t;
    while(t--){
        puts(solve()? "YES" : "NO");
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 