#include "bits/stdc++.h"
using namespace std;


void solve(){
    int n;
    cin >> n;
    set<int> st;
    for(int i = 0; i < n; ++i) st.insert(i);
    int j = 0;
    while(!st.empty()){
        auto it = st.find(j);
        if(++it == st.end()) it = st.begin();
        cout << *it + 1 << " "; 
        int x = *it;
        if (++it == st.end()) it = st.begin();
        j = *it;
        st.erase(x);
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}