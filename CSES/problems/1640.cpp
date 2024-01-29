#include "bits/stdc++.h"
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    multimap<int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mp.insert({a[i], i});
    }
    for(int i = 0; i < n; ++i){
        auto it = mp.find(x - a[i]);
        if (it != mp.end() && (*it).second != i){
            printf("%d %d\n", i + 1, (*it).second + 1);
            return 0;
        }
    }
    cout << "IMPOSSIBLE\n";
}