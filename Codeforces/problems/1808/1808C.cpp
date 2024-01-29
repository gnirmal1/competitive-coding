#include "bits/stdc++.h"
using namespace std;

// Template modified from https://usaco.guide/general/generic-code?lang=cpp#templates 

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvpii = vector<vpii>;

#define Sum(v) (accumulate(v.begin(), v.end(), 0ll))
#define Sort(v) (sort(v.begin(), v.end()))


constexpr ll INF = 1e9;
constexpr int MOD = 998244353;

// #define IO(NAME) \
//     cin.tie(0)->sync_with_stdio(0); \
//     if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
//     freopen(NAME ".out","w",stdout);

template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
}
 
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}
 
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
        cout << it << " ";
    return ostream;
}


// bitwise ops
// j is 0 based indexing 
// __builtin_ctzll() for long long and __ builtin_popcount()
#define LSB(S) ((S) & -(S))


ll LCM(int a, int b)
{
    return ((ll)a * b) / __gcd(a, b);
}

bool nCr_Parity(int n, int r){
    int i = 0;
    while(i <= 30){ // for 32 bit integers
        int x = 1<<i;
        if((x&r) > (x&n)) return 0;
        ++i;
    }
    return 1; // 1 is odd 
}

ll solve(){
    ll l, r;
    cin >> l >> r;
    if(l == r) return l;
    string num1 = to_string(l), 
           num2 = to_string(r);
    if(num1.length() != num2.length()){
        for(auto &i : num1) i = '9';
        ll ans1 = stoll(num1);
        return ans1;
    }
    int s = 0, mn = 10, mx = -1;
    string pref = "";
    while(num1[s] == num2[s]) {
        mn = min(mn, num1[s] - '0');
        mx = max(mx, num1[s] - '0');
        pref += num1[s];
        s++;
    }
    string temp = "", comp1 = "", comp2 = "";
    for(int i = s + 1; i < num1.length(); ++i) {
        temp += '1';
        comp1 += num1[i];
        comp2 += num2[i];
    }

    ll x, t1, t2;
    int n = temp.length();
    if(n == 0){
        x = t1 = t2 = 0;
    }
    else{
        x = stoll(temp);
        t1 = stoll(comp1);
        t2 = stoll(comp2);
    }
    ll ans_v;
    string ans = "";
    int d1 = num1[s] - '0', d2 = num2[s] - '0';
    int mx1 = max(mx, d1), mn1 = min(mn, d1);
    int j = mx1;
    while(j <= 9){
        ll y = j*x;
        if(y >= t1){
            ans = pref + num1[s];
            if(y != 0) ans += to_string(y);
            ans_v = j - mn1;
            break;
        }
        j++;
    }
    for(int i = d1 + 1; i < d2; ++i){
        mx1 = max(mx, i), mn1 = min(mn, i);
        if(mx1 - mn1 < ans_v){
            ll y = x*mx1;
            ans = pref + char(i + 48);
            if(y != 0) ans += to_string(y);
            ans_v = mx1 - mn1;
        }
    }
    mx1 = max(mx, d2), mn1 = min(mn, d2);
    j = mn1;
    while(j >= 0){
        ll y = j*x;
        if(y <= t2){
            if(mx1 - j < ans_v){
                ans = pref + num2[s];
                if(x != 0){
                    if(j == 0){
                        for(auto &c : temp) c = '0';
                        ans += temp;
                    } 
                    else ans += to_string(y);
                }
                ans_v = mx1 - j;
            }
            break;
        }
        j--;
    }
    ll ans1 = stoll(ans);
    return ans1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    int t;
    cin >> t;
    while(t--){
        cout << solve() << '\n';
    }
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 