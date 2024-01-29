#include "bits/stdc++.h"
using namespace std;

void rotate(int dx, int x, int y, int &tx, int &ty){
    tx = x + y, ty = dx + y - x;
}

void solve(int dx, int dy, int n, int q){
    vector<vector<int>> prefix_2d(dx + dy + 1, vector<int> (dx + dy + 1));
    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        int tx, ty;
        rotate(dx, x, y, tx, ty);
        prefix_2d[tx][ty]++;
    }
    for(int i = 1; i <= dx + dy; ++i){
        for(int j = 1; j <= dx + dy; ++j){
            prefix_2d[i][j] = prefix_2d[i][j - 1] + prefix_2d[i - 1][j]
                                - prefix_2d[i - 1][j - 1] + prefix_2d[i][j];
        }
    }
    while(q--){
        int m;
        cin >> m;
        int ans = -1, ans_x = 0, ans_y = 0;
        for(int j = 1; j <= dy; j++){
            for(int i = 1; i <= dx; ++i){
                int l1, r1, l2, r2;
                rotate(dx, i, j - m, l1, r1);
                rotate(dx, i, j + m, l2, r2);
                l1 = max(1, l1);
                r1 = max(1, r1);
                l2 = min(dx + dy, l2);
                r2 = min(dx + dy, r2);
                int temp = prefix_2d[l2][r2] - prefix_2d[l1 - 1][r2]
                            - prefix_2d[l2][r1 - 1] + prefix_2d[l1 - 1][r1 - 1];
                if(temp > ans){
                    ans = temp;
                    ans_x = i;
                    ans_y = j;
                }
            }
        }
        printf("%d (%d,%d)\n", ans, ans_x, ans_y);
    }
}
int main(){
    int cnt = 0;
    while(true){
        int dx, dy, n, q;
        cin >> dx >> dy >> n >> q;
        if(dx == 0 && dy == 0 && n == 0 && q == 0) break;
        printf("Case %d:\n", ++cnt);
        solve(dx, dy, n, q);
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 