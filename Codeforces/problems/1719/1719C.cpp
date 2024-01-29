#include "bits/stdc++.h"
using namespace std;


int solve(){
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        vector<pair<int, int>> wins(n + 1, {-1, -1});
        wins[1].first = 1;
        if(a[1] != n){
            int max = a[1], curr = 1;
            for(int i = 2; i <= n; ++i){
                if(a[i] > max){
                    wins[curr].second = i - 1;
                    wins[i].first = i - 1;
                    max = a[i];
                    curr = i;
                }
                if(a[i] == n){
                    wins[i].first = i - 1;
                    wins[i].second = 1e9 + 3;
                    break;
                }
            }
        }
        else wins[1].second = 1e9 + 3;
        for(int j = 0; j < q; ++j){
            int i, k;
            cin >> i >> k;
            cout << min(wins[i].second - wins[i].first, k < wins[i].first ? 0 : k - wins[i].first + 1) << '\n';
        }
    }
}
