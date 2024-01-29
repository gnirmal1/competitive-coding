#include "bits/stdc++.h"
using namespace std;
using ll = long long;
constexpr int MOD = 100000007;


void solve(ll n){
    bool flag = 1;
    vector<ll> answers;
    for(ll i = 1; i*i <= n; ++i){
        if(n%i == 0){
            ll second = n/i;
            if(second > 6*i && (second - 6*i)%7 == 0){
                ll a = (((second - 6*i)/7) % MOD + MOD)%MOD;
                ll ans = ((a*a*2)%MOD + MOD)%MOD;
                flag = 0;
                printf("Possible Missing Soldiers = %lld\n", ans);
            }
        }
    }
    if(flag) printf("No Solution Possible\n");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    ll n;
    bool first = 1;
    while(true){
        cin >> n;
        if(n == 0) break;
        first = 0;
        solve(n);
        printf("\n");
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 