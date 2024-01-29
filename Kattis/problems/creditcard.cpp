#include "bits/stdc++.h"
using namespace std;


int creditCard(){
    double r, b, m;
    cin >> r >> b >> m;
    int cnt = 0;
    while(true){
        double interest = (r * b) / 100.0;
        interest = round(interest * 100.0) / 100.0;
        b += interest;
        b -= m;
        b = round(b * 100.0) / 100.0;
        cnt++;
        if (b <= 0) return cnt;
        if (cnt >= 1200) return -1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int res = creditCard();
        if (res == -1) cout << "impossible\n";
        else cout << res << '\n';
    }
}