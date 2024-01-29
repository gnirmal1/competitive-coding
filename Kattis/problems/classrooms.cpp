#include "bits/stdc++.h"
using namespace std;

int solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> activities(n);
    for(int i = 0; i < n; ++i){
        cin >> activities[i].second >> activities[i].first;
    }
    sort(activities.begin(), activities.end());
    multiset<int> pq;
    int skipped = 0;
    for(int i = 0; i < n; ++i){
        if(!pq.empty()){
            auto it = pq.lower_bound(activities[i].second);
            if(it != pq.begin()){
                it--;
                pq.erase(it);
                pq.insert(activities[i].first);
                continue;
            }
        }
        if(pq.size() < k){
            pq.insert(activities[i].first);
            continue;
        }
        skipped++;
    }
    return n - skipped;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    cout << solve() << '\n';
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 