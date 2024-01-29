#include<bits/stdc++.h>

using namespace std;

template<typename T>
string concat(T str_lst){
  int n = str_lst.size();
  int m;

  bool flag = false;
  vector<string> new_str_lst = str_lst;
  string str;
  string left_str, right_str;
  string ans;
  sort(new_str_lst.begin(), new_str_lst.end());
  for (int i = 0; i < n; ++i){
    flag = false;
    str = str_lst[i];
    m = str.size();
    for (int j = 1; j < m; ++j ){
      left_str = str.substr(0, j);
      right_str = str.substr(j, m - j);
      if (binary_search(new_str_lst.begin(), new_str_lst.end(), left_str) && 
      binary_search(new_str_lst.begin(), new_str_lst.end(), right_str)){
        ans += '1';
        flag = true;
        break;
      }
    }
    if (!flag){
      ans += '0';
    }

  }
  return ans;
}

int main(){
  int t = 0;
  cin >> t;
  vector<string> result(t, "");

  int n;
  
  for (int i = 0; i < t; ++i){
    cin >> n ;
    vector<string> str_list(n, "");
    for (int j = 0; j < n; ++j){
      cin >> str_list[j];
    }
    result[i] = concat(str_list);
    }

  for (int v1 = 0; v1 < t; ++v1){
    cout << result[v1] << endl;
  }
  
  return 0;

  }