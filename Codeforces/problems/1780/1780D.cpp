#include "bits/stdc++.h"
using namespace std;

void solve(){
    int cnt;
    cin >> cnt;
    int numones = 0, pow = 0, prev = cnt, ans = 0;
    while(numones < cnt){
        int power2 = (1 << pow);
        cout << "- " << power2 << endl;
        int curr;
        cin >> curr;
        if(curr == prev - 1) ans |= power2;
        else{
            pow += curr - prev + 1;
            ans |= (1 << pow);
        }
        numones++;
        pow++;
        prev = curr;
    }
    cout << "! " << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 