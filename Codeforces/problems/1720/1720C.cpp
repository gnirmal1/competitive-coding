#include "bits/stdc++.h"
using namespace std;


int solve(){
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string prev;
        cin >> prev;
        int count = 0;
        for(int i = 0; i < m; ++i){
            if (prev[i] == '1') count++;
        }
        bool flag1 = false, flag2 = false;
        for(int i = 1; i < n; i++){
            string str;
            cin >> str;
            for(int i = 0; i < m; ++i){
                int zero = 0;
                if(str[i] == '1') count++;
                if(prev[i] == '0') zero++;
                if(prev[i + 1] == '0') zero++;
                if(str[i] == '0') zero++;
                if(str[i + 1] == '0') zero++;
                if(zero > 0) flag1 = true;
                if(zero > 1) flag2 = true;
            }
            prev = str;
        }
        int diff;
        if(flag2) diff = 0;
        else if(flag1) diff = 1;
        else diff = 2;        
        cout << count - diff << '\n';       
    }
}
