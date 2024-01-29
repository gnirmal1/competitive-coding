#include "bits/stdc++.h"
using namespace std;

vector<int> digits(10, 0);

bool check(int n){
    for(int i = 0; i <= 9; ++i){
        for(int j = 0; j <= 9; j++){
            if(n - i - j < 0 || n - i - j > 9) continue;
            map<int, int> mp{{i, 0}, {j, 0}, {n - i - j, 0}};
            mp[i]++;
            mp[j]++;
            mp[n - i - j]++;
            if(digits[i] >= mp[i] && digits[j] >= mp[j] && digits[n - i - j] >= mp[n - i - j]) return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        digits.assign(10, 0);
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            digits[x%10]++;
        }
        if(check(3) || check(13) || check(23)) cout << "YES\n";
        else cout << "NO\n";
    }
}