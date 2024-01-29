#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string row1, row2;
        cin >> row1 >> row2;

        bool flag = 1;
        for (int i = 0; i < n; ++i){
            if (row1[i] != row2[i] && (row1[i] == 'R' || row2[i] == 'R')){
                cout << "NO\n";
                flag = 0;
                break;
            }
        }   
        if (flag) cout << "YES\n"; 
                
        
    }

	return 0;
}