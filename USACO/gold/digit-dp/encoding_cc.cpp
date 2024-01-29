#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7, MAXN = 100001;
ll pw10[MAXN], memo[MAXN][2][11], cntmemo[MAXN][2];

ll count(string &num, int n, bool tight){
    if(n == 0) return 1;
    if(!tight) return pw10[n];
    ll &ans = cntmemo[n][tight];
    if(ans != -1) return ans;
    ans = 0;
    int ub = num[num.length() - n] - '0';
    for(int dig = 0; dig <= ub; ++dig){
        ans += count(num, n - 1, tight & (dig == ub));
    }
    ans %= MOD;
    return ans;
}

ll dp(string &num, int n, bool tight, int prev){
    if(n == 0) return 0;
    ll &ans = memo[n][tight][prev];
    if(ans != -1) return ans;
    ans = 0;
    int ub = tight? (num[num.length() - n] - '0') : 9;
    for(int dig = 0; dig <= ub; ++dig){
        if(dig != prev){
            ll contri = (dig*pw10[n - 1]) % MOD;
            ans += (contri*count(num, n - 1, tight & (dig == ub))) % MOD;
        }
        ans += dp(num, n - 1, tight & (dig == ub), dig);
    }
    ans %= MOD;
    return ans;
}

ll brute(string &num, int len){
    int prev = -1;
    ll ans = 0;
    for(int i = 0; i < len; ++i){
        int dig = num[i] - '0';
        if(dig != prev){
            ans += dig*pw10[len - i - 1];
            ans %= MOD;
        }
        prev = dig;
    }
    return ans;
}

ll solve(){
    int nl, nr;
    string l, r;
    cin >> nl >> l >> nr >> r;
    memset(memo, -1, sizeof memo);
    memset(cntmemo, -1, sizeof cntmemo);
	ll ans1 = dp(r, nr, 1, -1);
    memset(memo, -1, sizeof memo);
    memset(cntmemo, -1, sizeof cntmemo);
	ll ans2 = dp(l, nl, 1, -1);
	ll ans3 = brute(l, nl);
	ll ans = ((ans1 - ans2 + ans3) % MOD + MOD) % MOD;
    return ans;
}

int main() {
    pw10[0] = 1;
	for(int i = 1; i <= MAXN; ++i){
	    pw10[i] = (pw10[i - 1]*10ll) % MOD;
	}
    int t;
    cin >> t;
	while(t--){
        cout << solve() << '\n';
    }
}
