#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
  
signed main(){
  int t = 0;
  cin >> t;
  while(t--)
  {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> arr(n, 0);
    arr[0] = l;
    bool flag = 1;
    for (int i = 2; i <= n; ++i){
      if (l%i == 0){
        arr[i - 1] = l;
      }
      else if (r >= (l + (i - l%i))){
        arr[i - 1] = l + (i - l % i);
      }
      else{
        cout << "NO" << endl;
        flag = 0;
        break;
      }
    }
    if (flag){
      cout << "YES" << endl;
      for (int k = 0; k < n; ++k){
        if (k == n - 1){
          cout << arr[k];
        }
        else{
        cout << arr[k] << " "; 
        }
      }
      cout << '\n';
    }
  }
  return 0;
  }