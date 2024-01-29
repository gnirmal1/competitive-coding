#include "bits/stdc++.h"
using namespace std;

double d, s;
bool check(double x){
    if(x + s < x*cosh(d/(2*x))) return true;
    return false;
}
void solve(){
    cin >> d >> s;
    double lo = 0.0, hi = 1000000.0; 
    for(int i = 0; i < 50; ++i){
        double mid = (lo + hi)/2.0;
        check(mid) ? lo = mid : hi = mid;
    }
    double ans = 2*hi*sinh(d/(2*hi));
    cout << ans << '\n';
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