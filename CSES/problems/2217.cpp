#include "bits/stdc++.h"
using namespace std;


void solve(){
    int n, m;
    cin >> n >> m;
    unordered_map<int, int> mp;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        arr[i] = x;
        mp[x] = i;
    }
    int ans = 1;
    for(int i = 1; i <= n - 1; ++i){
        if(mp[i] > mp[i + 1]) ans++;
    }

    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        int orig2 = mp[arr[a]], orig1 = mp[arr[a] - 1], orig3 = mp[arr[a] + 1];
        int orig5 = mp[arr[b]], orig4 = mp[arr[b] - 1], orig6 = mp[arr[b] + 1]; 
        mp[arr[a]] = b;
        mp[arr[b]] = a;

        if(arr[a] != n && orig2 < orig3 && b > mp[arr[a] + 1]) ans++;
        else if(arr[a] != n && orig2 > orig3 && b < mp[arr[a] + 1]) ans--;

        if(arr[a] != 1 && orig1 < orig2 && b < mp[arr[a] - 1]) ans++;
        else if(arr[a] != 1 && orig1 > orig2 && b > mp[arr[a] - 1]) ans--;

        if(arr[a] != arr[b] + 1){
            if(arr[b] != n && orig5 < orig6 && a > mp[arr[b] + 1]) ans++;
            else if(arr[b] != n && orig5 > orig6 && a < mp[arr[b] + 1]) ans--;
        }
        if(arr[a] != arr[b] - 1){
            if(arr[b] != 1 && orig4 < orig5 && a < mp[arr[b] - 1]) ans++;
            else if(arr[b] != 1 && orig4 > orig5 && a > mp[arr[b] - 1]) ans--;
        }

        swap(arr[a], arr[b]);
        cout << ans << '\n';
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}