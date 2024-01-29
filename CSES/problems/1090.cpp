#include "bits/stdc++.h"
using namespace std;


int solve(){
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
    sort(p.begin(), p.end());
    int ans = 0, i = 0, j = n - 1;
    while(i <= j){
        if(p[i] + p[j] <= x) i++;
        j--;
        ans++;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
}