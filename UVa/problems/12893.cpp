#include "bits/stdc++.h"
using namespace std;
using ll = long long;


int solve(){
    ll n;
    cin >> n;
    int ans = 0;
    while(n > 0){
        ans += n%2;
        n /= 2;
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