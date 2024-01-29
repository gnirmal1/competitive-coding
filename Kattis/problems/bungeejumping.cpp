#include "bits/stdc++.h"
using namespace std;

double const g = 9.81;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true){
        double k, l, s, w, vf;
        cin >> k >> l >> s >> w;
        if (k == 0 && l == 0 && s == 0 && w == 0) break;
        if(s <= l){
            vf = 2*g*s;
            if (vf <= 100) cout << "James Bond survives.\n";
            else cout << "Killed by the impact.\n";
        }
        else{
            vf = 2*g*s - (k*(s - l)*(s - l))/w;
            if(vf > 100) cout << "Killed by the impact.\n";
            else if (vf < 0) cout << "Stuck in the air.\n";
            else cout << "James Bond survives.\n";
        }
    }
}