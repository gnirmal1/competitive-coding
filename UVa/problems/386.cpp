#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> tuples;
    map<int, int> mp;
    for(int i = 6; i <= 200; ++i) mp[i*i*i] = i;
    for(int b = 2; b <= 200; b++){
        for(int c = b; c <= 200; c++){
            for(int d = c; d <= 200; d++){
                int sum = b*b*b + c*c*c + d*d*d;
                if(sum > 8000000) continue;
                if(mp.find(sum) != mp.end()) tuples.push_back({mp[sum], b, c, d});    
            }
        }
    }

    sort(tuples.begin(), tuples.end());
    for(auto& tupl : tuples){
        printf("Cube = %d, Triple = (%d,%d,%d)\n",tupl[0],tupl[1],tupl[2],tupl[3]);
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 