#include "bits/stdc++.h"
using namespace std;

// Template from https://usaco.guide/general/generic-code?lang=cpp#templates 

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

#define sum(v) (accumulate(v.begin(), v.end(), 0ll))
#define sort(v) (sort(v.begin(), v.end()))


constexpr ll INF = 1e9;
constexpr int MOD = 1e9 + 7;

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

const int MAX_A = 70;
const int TOTAL_PRIMES = 19;
const int N = 1e5 + 5;
const int LOG_A = TOTAL_PRIMES;

ll powers[N];
int base[LOG_A], sz;
const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int mask[MAX_A + 1];

bool checkXor(int mask) {
	for (int i = 0; i < LOG_A; i++) {
		if ((mask & 1 << i) == 0) continue;
 
		if (!base[i]) return false;
 
		mask ^= base[i];
	}
 
	return true;
}

void insertVector(int mask) {
	for (int i = 0; i < LOG_A; i++) {
		if ((mask & 1 << i) == 0) continue;
 
		if (!base[i]) {
			base[i] = mask;
			sz++;
 
			return;
		}
		mask ^= base[i];
	}
}
 
int main() {
    int n;
	cin >> n;
	vector<int> a(n);
    cin >> a;
    for (int i = 1; i <= MAX_A; i++) {
		for (int p = 0; p < TOTAL_PRIMES; p++) {
			int cnt = 0;
			int at = i;
 
			while (at % primes[p] == 0) {
				at /= primes[p];
				cnt++;
			}
			if (cnt & 1) mask[i] |= (1 << p);
		}
	}

    for(int i = 0; i < n; ++i)
        insertVector(mask[a[i]]);
    
	powers[0] = 1;
	for (int i = 1; i < N; i++)
		powers[i] = powers[i - 1] * 2LL % MOD;

    if(checkXor(0)) cout << powers[n - sz] - 1;
	return 0;
}