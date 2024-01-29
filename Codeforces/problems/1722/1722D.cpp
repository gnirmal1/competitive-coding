#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string direction;
        cin >> direction;

        long long ans = 0;
        int mid = n/2;

        queue<int> lq;
        queue<int> rq;
        for (int i = 0; i < mid; ++i){
            if(direction[i] == 'R'){
                ans += n - 1 - i;
            }
            else{
                ans += i;
                lq.push(i);

            }
        }

        for (int i = n - 1; i >= mid; --i){
            if(direction[i] == 'L'){
                ans += i;
            }
            else{
                ans += n - 1 - i;
                if (i == mid && n%2 == 1){
                    continue;
                }
                rq.push(i);
            }
        }

        for (int i = 0; i < n; ++i){
            if (lq.empty() && rq.empty()) cout << ans << " ";
            else{
                if (lq.empty()){
                    ans += 2*rq.front() + 1 - n;
                    cout << ans << " ";
                    rq.pop();
                }
                else if(rq.empty()){
                    ans += n - 1 - 2*lq.front();
                    cout << ans << " ";
                    lq.pop();
                }
                else if (n - 1 - 2*lq.front() > 2*rq.front() + 1 - n){
                    ans += n - 1 - 2*lq.front();
                    cout << ans << " ";
                    lq.pop();
                }
                else{
                    ans += 2*rq.front() + 1 - n;
                    cout << ans << " ";
                    rq.pop();
                }
            }
        }

        cout << '\n';
    }
	return 0;


}