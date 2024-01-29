#include "bits/stdc++.h"
using namespace std;


long long solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long s1 = 0;
    int mid = (n - 1)/2;
    for(int i = 0; i < n; ++i)
        s1 += abs(arr[i] - arr[mid]);
    return s1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
}