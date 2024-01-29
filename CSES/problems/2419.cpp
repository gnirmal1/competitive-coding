#include "bits/stdc++.h"
using namespace std;

int MAX = 30;

int PowerOf2(int num){
    int ans = 0;
    while(num > 0){
        ans += (int)num/2;
        num /= 2;
    }
    return ans;
}

bool nCr_Parity(int n, int r){
    int i = 0;
    while(i <= MAX){
        int x = 1<<i;
        if((x&r) > (x&n)) return 0;
        ++i;
    }
    return 1;
}
long long solve(){
    int n;
    cin >> n;
    long long ans = 0;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i <= (n - 1)/2; ++i){
        if(nCr_Parity(n - 1, i)) {
            ans ^= a[i];
            if (i != n - 1 - i) ans ^= a[n - 1 - i];
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
}