#include<bits/stdc++.h>
using namespace std;

void BasicPrg(int n, int t, vector<int> &A){
    if(t == 1){
        cout << "7";
    }
    else if(t == 2){
        if(A[0] > A[1]) cout << "Bigger";
        else if(A[0] == A[1]) cout << "Equal";
        else cout << "Smaller";
    }
    else if(t == 3){
        printf("%d\n", max(min(A[0], A[1]), min(max(A[0], A[1]), A[2])));
    }
    else if(t == 4){
        printf("%lld\n", accumulate(A.begin(), A.end(), 0LL));
    }
    else if(t == 5){
        long long esum = 0;
        for(int i = 0; i < n; ++i){
            if(!(A[i] & 1)) {
                esum += A[i];
            }
        }
        printf("%lld\n", esum);
    }
    else if(t == 6){
        string res = "";
        for(int i = 0; i < n; ++i){
            res += char(A[i] % 26 + 97);
        }
        cout << res << '\n';
    }
    else{
        int cnt, j;
        cnt = j = 0;
        while(true){
            if (j >= n){
                printf("Out\n");
                break;
            }
            if (j == n - 1) {
                printf("Done\n"); 
                break;
            }
            if (cnt == n + 1){
                printf("Cyclic\n"); 
                break;
            }
            j = A[j];
            cnt++;
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<int> A(n);
    for (int i = 0; i < n; ++i){
        cin >> A[i];
    }
    BasicPrg(n, t, A);
    
}