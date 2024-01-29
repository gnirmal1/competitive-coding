#include "bits/stdc++.h"
using namespace std;


bool solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    for(int i = 0; i < n; ++i){
        if (a[i] > b[i]) return false;
        else if (a[i] < b[i]){
            if (max(a[(i + 1) % n] + 1, b[(i + 1)%n] + 1) < b[i]) return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        puts(solve() ? "YES" : "NO");
    }
}
