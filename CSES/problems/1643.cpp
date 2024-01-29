#include "bits/stdc++.h"
using namespace std;


long long solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long ans = -1e9, sum = 0;
    for(int i = 0; i < n; ++i){
        sum += arr[i];
        ans = max(ans, sum);
        if (sum < 0) sum = 0;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
}