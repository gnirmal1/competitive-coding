#include "bits/stdc++.h"
using namespace std;


long long solve(){
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());
    long long ans = 1;
    for(int i = 0; i < n; ++i){
        if (coins[i] <= ans) ans += coins[i];
        else return ans;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
}