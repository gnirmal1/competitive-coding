#include "bits/stdc++.h"
using namespace std;


long long workout(){
    long long res = 0;
    vector<pair<int, int>> jim(10);
    vector<pair<int, int>> gym(10);
    vector<int> start(10);
    for(int i = 0; i < 10; ++i) cin >> jim[i].first >> jim[i].second;
    for(int i = 0; i < 10; ++i) cin >> gym[i].first >> gym[i].second >> start[i];
    int cnt = 0, i = 0;
    while(cnt < 30){
        if (res < start[i]){
            start[i] = max(res + jim[i].first, (long long)start[i]);
            res += jim[i].first + jim[i].second;
            cnt++;
            i = (i + 1) % 10;
        }
        else{
            double x = (double)(res - start[i])/(double)(gym[i].first + gym[i].second);
            start[i] += ceil(x) * (gym[i].first + gym[i].second);
            if (start[i] == res) start[i] += gym[i].first + gym[i].second;
            if (start[i] - gym[i].second > res) res = start[i] - gym[i].second;
        }
    }
    return res - jim[9].second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << workout() << '\n';
}