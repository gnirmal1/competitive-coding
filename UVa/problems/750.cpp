#include "bits/stdc++.h"
using namespace std;

int a, b, lineNum, row[8];

bool check(int r, int c){
    for(int i = 0; i < c; ++i){
        if(row[i] == r || abs(row[i] - r) == abs(i - c)) return false;
    }
    return true;
}

void solve(int c){
    if(c == 8 && row[b] == a){
        printf("%2d      %d", ++lineNum, row[0]+1);
        for(int i = 1; i < 8; ++i) printf(" %d", row[i] + 1);
        printf("\n");
        return;
    }
    for(int r = 0; r < 8; ++r){
        if(c == b && r != a) continue;
        if(check(r, c)){
            row[c] = r;
            solve(c + 1);
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        a--; b--;
        memset(row, 0, sizeof row);
        lineNum = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        solve(0);
        if(t) printf("\n");
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 