#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p;
    cin >> n >> p;
    int c = 0, a = 0;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        x -= p;
        c += x;
        if(x > 0 && c > a) a = c;
        else if(c < 0) c = 0;
    }
    cout << a;
}