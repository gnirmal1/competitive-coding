#include "bits/stdc++.h"
using namespace std;


int solve(){
    bitset<2001> can = 0;
    can[0] = 1;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int w;
        cin >> w;
        can |= (can << w);
    }
    int closest = 0;
    for(int i = 0; i <= 2000; ++i){
        if(can[i] && abs(1000 - i) <= abs(1000 - closest)) 
            closest = i;
    }
    return closest;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    cout << solve() << '\n';
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 