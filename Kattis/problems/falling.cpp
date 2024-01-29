#include "bits/stdc++.h"
using namespace std;

int main(){
    int d;
    cin >> d;
    for(int i = 1; i*i <= d; ++i){
        if(d%i == 0){
            if((d/i + i)%2 == 0 && (d/i - i)%2 == 0){
            cout << (d/i - i)/2 << " " << (d/i + i)/2;
            return 0;
            } 
        }
    }
    cout << "impossible";
}