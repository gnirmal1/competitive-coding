#include<bits/stdc++.h>
using namespace std;

void BattleSim(string &str){
    int n = str.length();
    int i = 0;
    set<string> perms = {"RBL", "RLB", "BLR", "BRL", "LRB", "LBR"};
    map<char, char> counters = {{'R', 'S'}, {'B', 'K'}, {'L', 'H'}};
    string temp = "";
    string res = "";
    while(i < n){
        if(i <= n - 3){
            temp = "";
            temp += str[i]; temp += str[i + 1]; temp += str[i + 2];
            if (perms.find(temp) != perms.end()){
                res += 'C';
                i += 3;
            }
            else{
                res += counters[str[i]];
                i++;
            }
        }
        else{
            res += counters[str[i]];
            i++;

        }
    }
    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    BattleSim(s);
    
}