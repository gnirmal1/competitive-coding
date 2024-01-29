#include "bits/stdc++.h"
using namespace std;


int solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> movies(n);
    for(int i = 0; i < n; i++){
        cin >> movies[i].second >> movies[i].first;
    }
    sort(movies.begin(), movies.end());
    int curr = movies[0].first, ans = 1;
    for(int i = 1; i < n; ++i){
        if(movies[i].second >= curr){
            ans++;
            curr = movies[i].first;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
}