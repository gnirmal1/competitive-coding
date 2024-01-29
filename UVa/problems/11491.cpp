#include "bits/stdc++.h"
using namespace std;


int n, d;
void solve(){
    string num;
    cin >> num;
    stack<int> stck;
    for(int i = 0; i < n; ++i){
        int x = num[i] - '0';
        while(!stck.empty() && stck.top() < x && d > 0){
            stck.pop();
            d--;   
        }
        stck.push(x);
    }
    while(!stck.empty() && d > 0){
        stck.pop();
        d--;   
    }
    string res = "";
    while(!stck.empty()){
        res += (stck.top() + 48);
        stck.pop();
    }
    reverse(res.begin(), res.end());
    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    while(true){
        cin >> n >> d;
        if(n == 0 && d == 0) break;
        solve();
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 