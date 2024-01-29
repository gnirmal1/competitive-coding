#include "bits/stdc++.h"
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int n, ans;
vvi pages;
vi curr;
bool preprocces[20][20];
bool check(int index){
    for(int i : curr)
    if(!preprocces[i][index]) return false;

    return true;
}

void solve(int left, int cnt){
    for(int i = left; i < n; ++i){
        if(check(i)){
            curr.push_back(i);
            solve(i + 1, cnt + pages[i][0]*pages[i][1]);
            curr.pop_back();
        }
    }
    ans = max(ans, cnt);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    while(true){
        cin >> n;
        if(n == 0) break;
        pages.clear();
        curr.clear();
        memset(preprocces, false, sizeof preprocces);
        for(int i = 0; i < n; ++i){
            int w, h, x, y;
            cin >> w >> h >> x >> y;
            pages.push_back({w, h, x, y});
        }
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                if(pages[i][2] >= pages[j][2] + pages[j][0] ||
                pages[j][2] >= pages[i][2] + pages[i][0] ||
                pages[i][3] >= pages[j][3] + pages[j][1] ||
                pages[j][3] >= pages[i][3] + pages[i][1]) preprocces[i][j] = preprocces[j][i] = true;
                else preprocces[i][j] = preprocces[j][i] = false;
            }
        }
        ans = 0;
        solve(0, 0);
        cout << ans << '\n';
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 