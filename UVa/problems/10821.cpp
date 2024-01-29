#include "bits/stdc++.h"
using namespace std;


int N, H;
void recurse(int left, int right, int level){
    if(left > right) return;
    if(left == right){
        printf(" %d", left);
        return;
    }
    int len = right - left + 1,
        power2 = (int)log2(len),
        k = len - (1 << power2);
    if(H - level == power2 + 1){
        printf(" %d", left + k);
        recurse(left, left + k - 1, level + 1);
        recurse(left + k + 1, right, level + 1);
    }
    else{
        printf(" %d", left);
        recurse(left + 1, right, level + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int linecount = 0;
    while(true){
        cin >> N >> H;
        if(N == 0 && H == 0) break;
        printf("Case %d:", ++linecount);
        int lo = (int)log2(N) + 1;
        if(H < lo){
            printf(" Impossible.\n");
            continue;
        }
        for(int i = 1; i <= N; ++i){
            lo = (int)log2(N - i + 1) + 1;
            if(H > lo){
                printf(" %d", i);
                H--;
            }
            else{
                recurse(i, N, 0);
                break;
            }
        }
        printf("\n");
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 