#include "bits/stdc++.h"
using namespace std;

int n;
int rack[2][1000000 + 1];
bool ok(int w){
    for(int row = 0; row < 2; ++row){
        int i = 0;
        while(i < n){
            if(rack[row][i] <= w) {
                i++;
                continue;
            }
            int next = i;
            while(next + 1 < n && rack[row][next + 1] <= w){
                next++;
            }
            if(next == n - 1 || rack[row][next + 1] != rack[row][i]) return false;
            i = next + 2;
        }
    }
    return true;
}

int solve(){
    cin >> n;
    int hi = 0;
    for(int i = 0; i < n; ++i){
        cin >> rack[0][i];
        hi = max(rack[0][i], hi);
    }
    for(int i = 0; i < n; ++i){
        cin >> rack[1][i];
        hi = max(rack[1][i], hi);
    }
    int lo = -1;
    while(hi - lo > 1){
        int mid = (hi + lo)/2;
        ok(mid)? hi = mid : lo = mid;
    }
    return hi;
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