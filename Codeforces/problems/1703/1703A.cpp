#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  int t = 0;
  cin >> t;
  vector<bool> result(t, true);
  string str;
  for (int i = 0; i < t; ++i){
    cin >> str;
    if (str == "YES" || str == "yes" || str == "Yes" || str == "yEs" || str == "yeS"
    || str == "YEs" || str == "YeS" || str == "yES"){
      result[i] = true; 
    }
    else{
      result[i] = false;
    }
  }

  for (int i = 0; i < t; ++i){
    if (result[i]){
      cout << "YES\n";
    }
    else{
      cout << "NO\n";
    }

  }
  return 0;

  }