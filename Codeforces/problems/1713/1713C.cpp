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
        int n;
        cin >> n;
        int hi = (int)sqrt(2*n - 2);
        int cnt = 0;
        vector<int> arr(n, -1);
        vector<bool> used(n, false);
        int j = n - 1;
        while(j >= 0){
            if (hi*hi <= n - 1 + j && !used[hi*hi - j]){
                arr[j] = hi*hi - j;
                used[hi*hi - j] = true;
                cnt++;
                j--;

            }
            else hi--;
        }
        if (cnt != n) cout << "-1\n";
        else{
            for(int i = 0; i < n; ++i){
                cout << arr[i] << " ";
            }
            cout << '\n';
        }
    }
}
