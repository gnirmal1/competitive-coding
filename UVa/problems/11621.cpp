#include "bits/stdc++.h"
using namespace std;



vector<long long> numbers;
void generate(){
    long long upper = (1ll << 31);
    numbers.push_back(upper);
    for(int i = 0; i < 31; ++i){
        long long power2 = (1 << i);
        while(power2 <= upper){
            numbers.push_back(power2);
            power2 *= 3;
        }
    }
    sort(numbers.begin(), numbers.end());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    generate();
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        cout << *lower_bound(numbers.begin(), numbers.end(), n) << '\n';
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 