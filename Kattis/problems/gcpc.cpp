#include "bits/stdc++.h"
using namespace std;

// Template modified from https://usaco.guide/general/generic-code?lang=cpp#templates 



vector<int> solved, penalty;

struct comp_fx
{
    bool operator()(const int &a, const int &b) const
    {
        if (solved[a] == solved[b]){
            if(penalty[a] == penalty[b]) return a < b;
            return penalty[a] < penalty[b];
        }
        return solved[a] > solved[b];
    }
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<int, null_type, comp_fx, rb_tree_tag,tree_order_statistics_node_update>;

void solve(){
    int n, m;
    cin >> n >> m;
    solved.assign(n + 1, 0);
    penalty.assign(n + 1, 0);
    ordered_set oset;
    while(m--){
        int t, p;
        cin >> t >> p;
        if(oset.find(t) != oset.end()) oset.erase(oset.find(t));
        solved[t]++;
        penalty[t] += p;
        oset.insert(t);
        cout << oset.order_of_key(1) + 1 << '\n';
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    solve();
}
// when using printf, scanf for long long use %dint
// when using accumulate use 0int if sum is long long 