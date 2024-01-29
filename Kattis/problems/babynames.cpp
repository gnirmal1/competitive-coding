#include "bits/stdc++.h"
using namespace std;

// Template modified from https://usaco.guide/general/generic-code?lang=cpp#templates 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


void solve(){
    ordered_set<string> male, female;
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        else if(n == 1){
            string name; int gender;
            cin >> name >> gender;
            if(gender == 1) male.insert(name);
            else female.insert(name);
        }
        else if(n == 2){
            string name;
            cin >> name;
            if(male.find(name) != male.end()) male.erase(name);
            else female.erase(name);
        }
        else{
            string start, end; int suitability;
            cin >> start >> end >> suitability;
            int num1 = -1, num2 = -1;
            if(suitability == 0){
                num1 = male.order_of_key(end) - male.order_of_key(start);
                num2 = female.order_of_key(end) - female.order_of_key(start);
                cout << num1 + num2 << '\n';
            }
            else if(suitability == 1){
                num1 = male.order_of_key(end) - male.order_of_key(start);
                cout << num1 << '\n';
            }
            else{
                num2 = female.order_of_key(end) - female.order_of_key(start);
                cout << num2 << '\n';
            }
            
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    solve();
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 