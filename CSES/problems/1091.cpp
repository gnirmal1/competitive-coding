#include "bits/stdc++.h"
using namespace std;



void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> t(m);
    multiset<int> h;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        h.insert(x);
    }
    for(int i = 0; i < m; ++i){
        cin >> t[i];
    }
    for(int i = 0; i < m; ++i) {
        if(h.empty()){
            cout << "-1\n";
            continue;
        }
        auto it = h.upper_bound(t[i]);
        if(it != h.begin()) {
            cout << *(--it) << '\n';
            h.erase(it);
        }
        else cout << "-1\n"; 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}