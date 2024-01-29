#include "bits/stdc++.h"
using namespace std;

void solve(){
    int n;
    cin >> n;
    int lo = 1, hi = n;
    while(true){
        if(hi - lo == 2){
            cout << "Q " << lo << " " << lo << " " << hi << " " << hi << endl;
            int w1, w2;
            cin >> w1 >> w2;
            if(w1 == 1){
                cout << "A " << lo << endl;
                return;
            }
            else if(w2 == 1){
                cout << "A " << hi << endl;
                return;
            }
            else {
                cout << "A " << lo + 1 << endl;
                return;
            }
        }
        int delta = (hi - lo + 1)/4;
        int n1 = lo + delta, n3 = hi - delta, n2 = (lo + hi)/2;
        cout << "Q " << lo << " " << n2 << " " << n1 << " " << n3 << endl;
        int w1, w2;
        cin >> w1 >> w2;
        if(w1 == 0 && w2 == 0){
            if(n3 + 1 >= hi){
                cout << "A " << hi << endl;
                return;
            }
            lo = n3; hi = min(n, hi + 1);
        }
        else if(w1 == 1 && w2 == 1){
            if(n1 == n2){
                cout << "A " << n1 << endl;
                return;
            }
            lo = max(1, n1 - 1); hi = min(n2 + 1, n);
        }
        else if(w1 == 1 && w2 == 0){
            if(n1 - 1 <= lo){
                cout << "A " << lo << endl;
                return;
            }
            lo = max(1, lo - 1); hi = n1;
        }
        else{
            if(n2 + 1 >= n3){
                cout << "A " << n3 << endl;
                return;
            }
            lo = n2; hi = min(n, n3 + 1);
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    solve();
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long