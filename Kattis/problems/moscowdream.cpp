#include "bits/stdc++.h"
using namespace std;

int main(){
    int n, a, b, c;
    scanf("%d %d %d %d", &a, &b, &c, &n);
    puts((a >= 1 && b >= 1 && c>=1 && a+b+c >= n)? "YES\n" : "NO\n");
}