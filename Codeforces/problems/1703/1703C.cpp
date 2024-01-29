#include <iostream>
#include <string>
#include <vector>

using namespace std;

int cipher(int a, int b, string str){
  for (int i = 0; i < b; ++i){
    if (a == 0 && str[i] == 'U'){
      a = 9;
    }
    else if (a == 9 && str[i] == 'D'){
      a = 0;
    }
    else if (str[i] == 'U'){
      --a;
    }
    else{
      ++a;
    }
  }
  return a;
}

int main(){
  int t = 0;
  cin >> t;
  vector<vector<int>> result(t);

  int n;
  string str;
  int b;

  for (int i = 0; i < t; ++i){
    cin >> n ;
    vector<int> sequence(n, 0);
    for (int j = 0; j < n; ++j){
      cin >> sequence[j];
    }
    for (int k = 0; k < n; ++k){
      cin >> b >> str;
      sequence[k] = cipher(sequence[k], b, str);
    }
    result[i] = sequence;
    }

  for (int v1 = 0; v1 < t; ++v1){
    n = result[v1].size();
    for (int v2 = 0; v2 < n; ++v2){
      cout << result[v1][v2] << " ";

    }
    cout << endl;
  }
  return 0;

  }