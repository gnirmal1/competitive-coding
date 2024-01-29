#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
 
string photo(int n, int x, vector<int> &heights){
  sort(heights.begin(), heights.end());
  int pos = 0;
  int min_el = heights[pos];
  int cnt = 0;
  for (int i = 0; i < 2*n; ++i){
    if (heights[i] >= min_el + x){
      min_el = heights[++pos];
      ++cnt;
    }
  }
  if (cnt == n){
    return "YES";
  }
  else{
    return "NO";
  }
  
  
}
 
 
signed main(){
  int t = 0;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int j = 0; j < n; ++j){
      cin >> arr[j];
    }
    bool flag = 1;
    for (int i = 1; i < n; ++i){
      if ((arr[i] % arr[0]) != 0){
        cout << "NO" << endl;
        flag = 0;
        break;
      }
    }
    if (flag){
      cout << "YES" << endl;
    }
  }
  return 0;
  }