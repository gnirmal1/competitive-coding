#include "bits/stdc++.h"
using namespace std;


void solve(){
    int n;
    cin >> n;
    cout << "0\n";
    long long diff = 0;
    for(int i = 2; i <= n; ++i){
        long long sq = i*i;
        cout << (sq*(sq - 1)/2) - diff << '\n';
        diff += (i - 1)*8;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}