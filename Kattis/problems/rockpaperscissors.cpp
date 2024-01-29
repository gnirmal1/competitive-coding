#include <bits/stdc++.h>
using namespace std;

void WinAvg(int n, int k){
    vector<int> wins(n + 1, 0);
    vector<int> loss(n + 1, 0);
    for(int i = 1; i <= (k*n*(n - 1))/2; ++i){
        int p1, p2;
        string m1, m2;
        cin >> p1;
        cin >> m1;
        cin >> p2;
        cin >> m2;
        if(m1 == "paper" && m2 == "scissors"){wins[p2]++; loss[p1]++;}
        else if(m2 == "paper" && m1 == "scissors"){wins[p1]++; loss[p2]++;}
        else if(m1 < m2){wins[p1]++; loss[p2]++;}
        else if(m2 < m1){wins[p2]++; loss[p1]++;}
    }

    for(int i = 1; i <= n; ++i){
        if(wins[i] != 0 || loss[i] != 0){
            cout << setprecision(3) << fixed << ((double)wins[i]/((double)wins[i] + (double)loss[i])) << '\n';
        }
        else cout << "-\n";
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        int k;
        cin >> k;
        WinAvg(n, k);
    }
}