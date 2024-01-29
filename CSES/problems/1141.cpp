#include "bits/stdc++.h"
using namespace std;


int solve(){
    int n;
    cin >> n;
    vector<int> k(n);
    for(int i = 0; i < n; ++i){
        cin >> k[i];
    }
    set<int> st;
    int ans = 0, start = 0, end = 0;
    for(int i = 0; i < n; ++i){
        auto it = st.find(k[i]);
        if(it != st.end()){
            int j = start;
            while(k[j] != k[i]){
                st.erase(k[j]);
                j++;
            }
            st.erase(k[j]);
            start = j + 1;
        }
        end++;
        st.insert(k[i]);
        ans = max(ans, end - start);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
}