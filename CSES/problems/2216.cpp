#include "bits/stdc++.h"
using namespace std;


int solve(){
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x] = i;
    }
    int ans = 1;
    for(int i = 1; i <= n - 1; ++i){
        if(mp[i] > mp[i + 1]) ans++;
    }
    return ans;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
}