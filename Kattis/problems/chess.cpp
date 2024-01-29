#include "bits/stdc++.h"
using namespace std;


void chess(){
    int startcol, endcol;
    char x, y;
    int startrow, endrow;
    cin >> x >> startrow >> y >> endrow;
    startcol = x - 'A'; endcol = y - 'A';
    char startsq, endsq;
    if (((startcol & 1) && (startrow & 1)) || (!(startcol & 1) && !(startrow & 1))) startsq = 'W';
    else startsq = 'B';
    if (((endcol & 1) && (endrow & 1)) || (!(endcol & 1) && !(endrow & 1))) endsq = 'W';
    else endsq = 'B';

    if(startsq != endsq) cout << "Impossible\n";
    else{
        if(startcol == endcol && startrow == endrow) printf("0 %d %d\n", x, startrow);
        else if(abs(startcol - endcol) == abs(startrow - endrow)) printf("1 %d %d %d %d\n", x, startrow, y, endrow);
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        chess();
    }
}