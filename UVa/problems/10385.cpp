#include "bits/stdc++.h"
using namespace std;

int n;
double tot, running[25], cycling[25];
double f(double r){
    double diff = 1e9, cheater_time = 3600*(r/running[n - 1] + (tot - r)/cycling[n - 1]);
    for(int i = 0; i < n - 1; ++i){
        double t = 3600*(r/running[i] + (tot - r)/cycling[i]);
        diff = min(diff, t - cheater_time);
    }
    return diff;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> running[i] >> cycling[i];
    }
    double lo = 0, hi = tot;
    for(int i = 0; i < 50; ++i){
        double delta = (hi - lo)/3.0;
        double m1 = lo + delta;
        double m2 = hi - delta;
        f(m1) > f(m2)? hi = m2 : lo = m1;
    }
    int ans = (int)round(f(hi));
    if(ans < 0) printf("The cheater cannot win.\n");
    else printf("The cheater can win by %d seconds with r = %.2fkm and k = %.2fkm.\n", ans, hi, tot - hi);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    while(cin >> tot){
        solve();
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 