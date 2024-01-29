#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, i, j;
    while(scanf("%d %d %d", &N, &i, &j) != EOF){
        int round = 1;
        while(round <= N){
            if(abs(i - j) == 1 && min(i, j)&1){
                cout << round << '\n';
                break;
            }
            else{
                i = (int)((i + 1) / 2);
                j = (int)((j + 1) / 2);
                round++;
            }
        }
    }
}