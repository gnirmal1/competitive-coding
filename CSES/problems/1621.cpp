#include "bits/stdc++.h"
using namespace std;


int solve(){
    int n;
    cin >> n;
    set<int> st;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        st.insert(x);
    }
    return (int)st.size();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solve() << '\n';
}