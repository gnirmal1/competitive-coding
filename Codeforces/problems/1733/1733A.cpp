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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        long long sum = 0;
        for(int i = 0; i < k; ++i){
            int maxe = a[i];
            for(int j = i; j < n; j = j + k){
                maxe = max(maxe, a[j]); 
            }
            sum += maxe;
        }

        cout << sum << '\n';
    }
}