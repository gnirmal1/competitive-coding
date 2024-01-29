#include "bits/stdc++.h"
using namespace std;

int main(){
    int t;
    cin >> t;
    multiset<pair<int, int>> pq;
    while(t--){
        string s;
        cin >> s;
        if(s == "add"){
            int e, g;
            cin >> e >> g;
            pq.emplace(e, g);
        }
        else{
            int x;
            cin >> x;
            long long ans = 0;
            if(pq.empty()){
                cout << "0\n";
                continue;
            }
            auto it = pq.upper_bound({x, 1e5 + 1});
            while((--it)->second != 0 && it->first <= x){
                x -= it->first;
                ans += it->second;
                pq.erase(it);
                if(pq.empty()) break;
                it = pq.upper_bound({x, 1e5 + 1});
            }
            cout << ans << '\n';
        }
    }
}