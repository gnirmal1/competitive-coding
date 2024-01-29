#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

map<string, vector<int>> words;
vector<int> scores(3, 0);

void func(int i, string& str){

    if (words.find(str) == words.end()){
        scores[i] += 3;
        words[str] = {i};
    }
    else if (words[str].size() == 1){
        scores[words[str][0]] -= 2;
        scores[i] += 1;
        words[str].push_back(i);
    }
    else if (words[str].size() == 2){
        scores[words[str][0]] -= 1;
        scores[words[str][1]] -= 1;
        words[str].push_back(i);
    }
}


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        words.clear();
        scores.assign(3, 0);
        for (int i = 0; i < 3; ++i){
            for (int j = 0; j < n; ++j){
                string str1;
                cin >> str1;
                func(i, str1);
            }
        }        
        
        printf("%d %d %d\n", scores[0], scores[1], scores[2]);
    }

	return 0;
}