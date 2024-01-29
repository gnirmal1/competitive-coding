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
        int n, x, y;
        cin >> n >> x >> y;
        if (x == 0 && y == 0) cout << "-1\n";
        else if (x == 0 || y == 0){
            int m = max(x, y);
            if((n - 1)%m == 0){
                int x = (n - 1)/m;
                int curr = 2;
                for(int i = 0; i < x; ++i){
                    for(int j = 0; j < m; ++j){
                        cout << curr << " ";
                    }
                    curr += m;
                }
                cout << '\n';
            }
            else cout << "-1\n";
        }
        else cout << "-1\n";
    }
}
