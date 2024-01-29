#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> sticker(n);
        vector<pair<int, int>> prize(n);
        for(int i = 0; i < n; ++i){
            int k;
            cin >> k;
            for(int j = 0; j < k; ++j){
                int x;
                cin >> x;
                --x;
                sticker[i].push_back(x);
            }
            int y;
            cin >> y;
            prize[i] = {y, i};
        }

        vector<int> tickets(m);
        for(int i = 0; i < m; ++i){
            cin >> tickets[i];
        }

        sort(prize.begin(), prize.end());

        int ans = 0;

        for(auto &[money, i] : prize){
            int mn = 200;
            for(int j : sticker[i]) mn = min(mn, tickets[j]);
            ans += mn*money;
            for(int j : sticker[i]) tickets[j] -= mn;
        }

        cout << ans << '\n';
    }
}