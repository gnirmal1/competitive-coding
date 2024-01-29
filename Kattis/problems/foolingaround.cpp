#include "bits/stdc++.h"
using namespace std;
const int MAXN = 1000;

bool v[MAXN], winner[MAXN];
vector<int> primes;

void Sieve(){
    memset(v, true, sizeof v);
    v[0] = v[1] = false;
    for (int i = 2; i <= MAXN; i++) {
        if (v[i] && (long long)i * i <= MAXN) {
            for (int j = i * i; j <= MAXN; j += i)
                v[j] = false;
        }
        if(v[i]) primes.push_back(i);
}
}

vector<int> B;
void solve(){
    for(int i = 1; i <= MAXN; ++i){
        if(!winner[i]){
            if(v[i + 1]) winner[i] = true;
            else {
                B.push_back(i);
                for(int p : primes){
                    if(p - 1 + i > MAXN) break;
                    winner[p - 1 + i] = true;
                }
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 
    Sieve();
    solve();
    printf("{");
    for(int x : B){
        printf("%d,", x);
    }
    printf("}");

}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 