#include "bits/stdc++.h"
using namespace std;

string convertToBase3(int N){
    string result = "";
    while(N>0){
        int rem = N%3;
        N = N/3;
        result += rem;
    }
    reverse(result.begin(), result.end());
    return result;
}

int linecount = 0;
void solve(int n){
    set<char> uniquePeople;
    vector<string> sentences;
    int flag = 0;
    bool impossible = 0;
    for(int i = 0; i < n; ++i){
        string sentence;
        getline(cin, sentence);
        if(sentence[0] == 'I' && sentence[1] == 't'){
            if(flag == 0 && sentence == "It is day") flag = 1;
            else if(flag == 2 && sentence == "It is day") impossible = 1;
            if(flag == 0 && sentence == "It is night") flag = 2;
            else if(flag == 1 && sentence == "It is night") impossible = 1;
        }
        else{
            uniquePeople.insert(sentence[0]);
            sentences.push_back(sentence);
        }
    }
    printf("Conversation #%d\n", linecount);
    if(impossible){
        printf("This is impossible.\n");
        return;
    }

    vector<char> people;
    for(char c : uniquePeople) people.push_back(c);
    map<string, vector<string>> mpDay, mpNight;
    mpDay["I am lying"] = {};
    mpDay["I am not lying"] = {"divine", "evil", "human"};
    mpDay["I am evil"] = {};
    mpDay["I am not evil"] = {"divine", "evil", "human"};
    mpDay["I am human"] = {"evil", "human"};
    mpDay["I am not human"] = {"divine"};
    mpDay["I am divine"] = {"divine", "evil"};
    mpDay["I am not divine"] = {"human"};
    

    mpNight["I am lying"] = {};
    mpNight["I am not lying"] = {"divine", "evil", "human"};
    mpNight["I am evil"] = {"human"};
    mpNight["I am not evil"] = {"divine", "evil"};
    mpNight["I am human"] = {"evil"};
    mpNight["I am not human"] = {"divine", "human"};
    mpNight["I am divine"] = {"divine", "evil", "human"};
    mpNight["I am not divine"] = {};

    map<char, string> maskMap;
    maskMap['0'] = "divine";
    maskMap['1'] = "evil";
    maskMap['2'] = "human";

    int upper = pow(3, people.size());
    for(string time : {"day", "night"}){
        if(time == "day" && flag == 2) continue;
        if(time == "night" && flag == 1) continue;
        for(int num = 0; num < upper; ++num){
            string mask = convertToBase3(num);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int n;
    while(true){
        cin >> n;
        if(n == 0) break;
        linecount++;
        solve(n);
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 
