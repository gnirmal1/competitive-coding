#include "bits/stdc++.h"
using namespace std;


void solve(){
    int x, n;
    cin >> x >> n;
    set<int> lights;
    multiset<int> paths;
    lights.insert(0); lights.insert(x);
    paths.insert(x); 
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        auto it = lights.upper_bound(l);
        int hi = *it;
        int lo = *(--it);
        paths.erase(paths.find(hi - lo));
        paths.insert(hi - l);
        paths.insert(l - lo);
        lights.insert(l);
        cout << *(paths.rbegin()) << " ";
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}