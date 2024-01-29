#include "bits/stdc++.h"
using namespace std;


int solve(){
    int n, h, ta, td;
    cin >> n >> h >> ta >> td;
    vector<int> heights(n);
    for(int i = 0; i < n; ++i){
        cin >> heights[i];
    }
    if(2*ta <= td) return n*ta;
    int ans = 0;
    sort(heights.begin(), heights.end());
    int i = 0, j = n - 1;
    while(i < j){
        if(heights[i] + heights[j] >= h) ans += ta;
        else{
            ans += td;
            i++;
        }
        j--;
    }
    if(i == j) ans += ta;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int t, linecnt = 1;
    cin >> t;
    while(t--){
        cout << "Case " << linecnt << ": " << solve() << '\n';
        linecnt++;
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 