#include <bits/stdc++.h>
using namespace std;

bool ticTacToe(){
    int x = 0;
    int o = 0;
    vector<int> winner(9, 0);
    map<char, int> mp = {{'X', 1}, {'O', -1}, {'.', 0}};
    for(int i = 1; i <= 3; ++i){
        for(int j = 1; j <= 3; ++j){
            char c;
            cin >> c;
            if(i == 1) winner[1] += mp[c];
            if(i == 2) winner[2] += mp[c];
            if(i == 3) winner[3] += mp[c];

            if(j == 1) winner[4] += mp[c];
            if(j == 2) winner[5] += mp[c];
            if(j == 3) winner[6] += mp[c];

            if(i == j) winner[7] += mp[c];
            if(i + j == 4) winner[8] += mp[c];

            if (c == 'X') x++;
            else if (c == 'O') o++;
        }
    }
    sort(winner.begin(), winner.end());
    bool winnero = false, winnerx = false;
    if(winner[0] == -3) winnero = true;
    if (winner[8] == 3) winnerx = true;
    if((x - o) != 1 && x != o) return false;
    if(winnerx && o == x || winnero && x == o + 1 || winnerx && winnero) return false;
    return true;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        puts(ticTacToe() ? "yes" : "no");
    }
}