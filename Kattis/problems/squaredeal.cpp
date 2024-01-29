#include "bits/stdc++.h"
using namespace std;

int solve(){
    int height[3], width[3];
    cin >> height[0] >> width[0] >> height[1] >> width[1] >> height[2] >> width[2];
    if(height[0] == height[1] && height[0] == height[2] && width[0] + width[1] + width[2] == height[0] ||
        width[0] == width[1] && width[0] == width[2] && height[0] + height[1] + height[2] == width[0]) return true;
    for(int i = 0; i < 3; ++i){
        vector<int> temp;
        int sum = 0;
        for(int j = 0; j < 3; ++j){
            if(j != i){
                sum += height[j] + width[j];
                temp.push_back(height[j]); temp.push_back(width[j]);
            }
        }
        int orig = sum;
        if(temp[0] == temp[2]) sum -= 2*temp[0];
        else if(temp[0] == temp[3]) sum -= 2*temp[0];
        else if(temp[1] == temp[2]) sum -= 2*temp[1];
        else if(temp[1] == temp[3]) sum -= 2*temp[1];
        int common = (orig - sum)/2;
        if(common != 0 && (sum == height[i] && sum == common + width[i] 
        || sum == width[i] && sum == common + height[i])) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    puts(solve()? "YES" : "NO");
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 