#include<bits/stdc++.h>
using namespace std;

void Bender(int L){
    map<pair<int, int>, string> mp;
    mp = {{{1,0}, "+x"}, {{2,0}, "+x"}, {{1,2}, "-x"}, {{2,2}, "-x"}, {{1, 1}, "+y"}, {{1, 3}, "-y"}, {{2, 1}, "+z"}, {{2, 3}, "-z"}};
    map<char, int> co;
    co = {{'y', 0}, {'z', 1}};
    vector<int> arr = {0, 0};
    int curr = -1;
    for (int i = 1; i < L; ++i){
        string str;
        cin >> str;
        if (str == "No") continue;
        if (curr == -1){
            curr = co[str[1]];
        }
        if (curr == co[str[1]]){
            if(str[0] == '+') arr[curr] = ((arr[curr] + 1) % 4 + 4) % 4;
            else arr[curr] = ((arr[curr] - 1) % 4 + 4) % 4;
        }
        else{
            if (arr[curr] == 0 || arr[curr] == 2){
                if(str[0] == '+') arr[co[str[1]]] = ((arr[curr] + 1) % 4 + 4) % 4;
                else arr[co[str[1]]] = ((arr[curr] - 1) % 4 + 4) % 4;
                arr[curr] = 0;
                curr = co[str[1]];
            }
        }

    }

    if (curr == -1) cout << "+x\n";
    else cout << mp[{curr + 1, arr[curr]}] << '\n';
    

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true){
        int L;
        cin >> L;
        if (L == 0) break;
        Bender(L);
    }
    return 0;
}