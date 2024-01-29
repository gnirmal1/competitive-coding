#include "bits/stdc++.h"
using namespace std;
using ll = long long;


int n;
ll solve(){
    priority_queue<ll> pq;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        pq.push(-x);
    }
    ll ans = 0;
    while(pq.size() > 1){
        int t = 0;
        t += pq.top(), pq.pop();
        t += pq.top(), pq.pop();
        ans += t;
        pq.push(t);
    }
    return -ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 
    while(true){
        cin >> n;
        if(n == 0) break;
        cout << solve() << '\n';
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 