#include "bits/stdc++.h"
using namespace std;


// CTU open 2009
int x, y, n;
vector<int> primes, res;
void solve(int num, int start, int left, int right){
    if(right == 0) return;
    if(left == 1) res.push_back(num);
    for(int i = start; i < n; ++i){
        int p = primes[i];  
        solve(num*p, i, (left + p - 1)/p, right/p);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    while(true){
        cin >> n;
        if(n == 0) break;
        res.clear(); primes.clear();
        for(int i = 0; i < n; ++i){
            int p;
            cin >> p;
            primes.push_back(p);
        }
        sort(primes.begin(), primes.end());
        cin >> x >> y;
        solve(1, 0, x, y);
        if(res.empty()) cout << "none";
        bool first = 1;
        sort(res.begin(), res.end());
        for(int i : res){
            if(!first) cout << ",";
            first = 0;
            cout << i;
        }
        cout << '\n';
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 