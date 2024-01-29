#include "bits/stdc++.h"
using namespace std;


int solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> customers(2*n);
    for(int i = 0; i < 2*n; i = i + 2){
        cin >> customers[i].first >> customers[i + 1].first;
        customers[i].second = 1;
        customers[i + 1].second = -1;
    }
    sort(customers.begin(), customers.end());

    // priority_queue<int, vector<int>, greater<>> restaurant;
    // int ans = 0;
    // for(int i = 0; i < n; ++i){
    //     while(!restaurant.empty() && restaurant.top() < customers[i].first) restaurant.pop();
    //     restaurant.push(customers[i].second);
    //     ans = max(ans, (int)restaurant.size());
    // }
    int curr = 0, ans = 0;
    for(const pair<int, int> &customer : customers){
        curr += customer.second;
        ans = max(ans, curr);
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
}