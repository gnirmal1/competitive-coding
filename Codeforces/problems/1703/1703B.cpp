#include <iostream>
#include <string>
#include <vector>

using namespace std;

int balloons(int n, string str){
  vector<bool> visited(int('Z') + 1, false);
  int total = 0;
  for (int i = 0; i < n; ++i){
    if (!visited[int(str[i])]){
      total += 2;
      visited[int(str[i])] = true;
    }
    else{
      ++total;
    }
  }
  return total;

}
int main(){
  int t = 0;
  cin >> t;
  vector<int> result(t, true);

  int n;
  string str;

  for (int i = 0; i < t; ++i){
    cin >> n >> str;
    result[i] = balloons(n, str);
    }

  for (int i = 0; i < t; ++i){
    cout << result[i] << endl;
  }
  return 0;

  }