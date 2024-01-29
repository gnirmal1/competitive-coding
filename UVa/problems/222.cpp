#include "bits/stdc++.h"
using namespace std;

int n;
double d, cap, mileage, base_cost;
vector<pair<double, double>> stations;

double solve(int left, double dist){
    if(dist + cap*mileage >= d || left == n) return 0;

    double best = 1e9;
    for(int i = left; i < n; ++i){
        double fuel_used = (stations[i].first - dist)/mileage;
        if(cap < fuel_used) break;
        if(cap - fuel_used <= cap/2.0){
            best = min(best, 200 + fuel_used*stations[i].second + solve(i + 1, stations[i].first));
        }
        else if (cap - fuel_used > cap/2.0 && i + 1 < n 
        && stations[i + 1].first > dist + mileage*cap)
        return 200 + fuel_used*stations[i].second + solve(i + 1, stations[i].first);
    }

    return best;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int linecount = 0;
    while(true){
        cin >> d;
        if(d == -1) break;
        cin >> cap >> mileage >> base_cost >> n;
        stations.clear();
        for(int i = 0; i < n; ++i){
            double x, y;
            cin >> x >> y;
            stations.emplace_back(x, y);
        }
        printf("Data Set #%d\n", ++linecount);
        printf("minimum cost = $%.2f\n", base_cost + solve(0, 0)/100.0);
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 