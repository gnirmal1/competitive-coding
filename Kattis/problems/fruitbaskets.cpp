#include "bits/stdc++.h"
using namespace std;


long long n, cnt = 0, d = 0;
int fruits[50];
void solve(int left, int tot){
    for(int i = left; i < n; ++i){
        if(fruits[i] + tot < 200){
            d += tot + fruits[i];
            solve(i + 1, tot + fruits[i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> fruits[cnt];
        sum += fruits[cnt++];
    }
    solve(0, 0);
    long long ans = (1ll << (n - 1)) * sum - d;
    cout << ans << '\n';
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 