#include "bits/stdc++.h"
using namespace std;


bool solve(){
    int n;
    cin >> n;
    vector<int> a;
    int pcnt = 0, ncnt = 0, zcnt = 0;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if (x == 0){
            if (zcnt < 2) a.push_back(0);
            zcnt++;
        }
        else if (x < 0){
            if (ncnt < 2) a.push_back(x);
            ncnt++;
        }
        else{
            if (pcnt < 2) a.push_back(x);
            pcnt++;
        }
    }
    if (pcnt > 2 || ncnt > 2) return 0;
    if (pcnt == 0 && ncnt == 0) return 1;
    n = a.size();
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            for(int k = j + 1; k < n; ++k){
                if (find(a.begin(), a.end(), a[i] + a[j] + a[k]) == a.end()) return 0;
            }
        }
    }
    return 1;
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
