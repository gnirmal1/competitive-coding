#include "bits/stdc++.h"
using namespace std;

struct custom_compare{
    bool operator() (const tuple<int, int, int> &a, const tuple<int, int, int> &b){
        return get<0>(a)*get<1>(b) < get<1>(a)*get<0>(b);
    }
};

void solve(){
    int n;
    cin >> n;
    vector<tuple<int, int, int>> orders;
    for(int i = 0; i < n; ++i){
        int t, f;
        cin >> t >> f;
        orders.emplace_back(t, f, i);
    }
    stable_sort(orders.begin(), orders.end(), custom_compare());
    bool first = 1;
    for(auto &[t, f, i] : orders){
        if(!first) cout << " ";
        first = 0;
        cout << i + 1;
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int t;
    cin >> t;
    while(t--){
        solve();
        if(t) cout << '\n';
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 