#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void solve(){
    int n, k;
    cin >> n >> k;
    ordered_set<int> st;
    for(int i = 0; i < n; ++i) st.insert(i);
    int j = 0;
    while(!st.empty()){
        j = (j + k)%n;
        auto it = st.find_by_order(j);
        cout << *it + 1 << " ";
        st.erase(it);
        n--;
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}