#include "bits/stdc++.h"
using namespace std;


int solve(){
    int n;
    cin >> n;
    vector<int> k(n);
    for(int i = 0; i < n; ++i){
        cin >> k[i];
    }
    multiset<int> bases;
    for(int i = 0; i < n; ++i){
        auto it = bases.upper_bound(k[i]);
        if(it != bases.end()) bases.erase(it);
        bases.insert(k[i]);
    }
    return bases.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
}