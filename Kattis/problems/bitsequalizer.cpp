#include<bits/stdc++.h>
using namespace std;

int BitsEqualizer(string &S, string &T){
    int n = S.length();
    vector<bool> equalized(n, false);
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(!equalized[i] && S[i] != T[i]){
            if(S[i] == '0'){
                for(int j = i + 1; j < n; ++j){
                    if (!equalized[j] && S[j] == '1' && T[j] == '0'){
                        equalized[i] = equalized[j] = true;
                        break;
                    }
                }
                if(!equalized[i]) equalized[i] = true;
                ans++;
            }
            else if(S[i] == '1'){
                int first = -1;
                for(int j = 0; j < n; ++j){
                    if(!equalized[j] && S[j] == '?' && T[j] == '1') first = j;
                    if (!equalized[j] && S[j] == '0' && T[j] == '1'){
                        equalized[i] = equalized[j] = true;
                        ans++;
                        break;
                    }
                }
                if(!equalized[i]){
                    if(first == -1) return -1;
                    else ans += 2;
                    if(first < i) ans--;
                    equalized[i] = equalized[first] = true;
                }
            }

            else ans++;    
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        string s, t;
        cin >> s >> t;
        cout << "Case " << i << ": " << BitsEqualizer(s, t) << '\n';
    }
    
}