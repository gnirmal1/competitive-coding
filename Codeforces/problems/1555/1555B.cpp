#include "bits/stdc++.h"
using namespace std;

int minDist(){
    int W, H, x1, y1, x2, y2, w, h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    if(h > H - (y2 - y1) && w > W - (x2 - x1)) return -1;
    int maxh = max(y1, H - y2);
    int maxw = max(x1, W - x2);
    if (h <= maxh || w <= maxw) return 0;
    else return min((y2 - y1 > H - h) ? 1e9 : h - maxh , (x2 - x1 > W - w) ? 1e9 : w - maxw);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        cout << minDist() << '\n';
    }
}
