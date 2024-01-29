#include <bits/stdc++.h>
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


int dr[] = { 1, 0, -1, 0};            
int dc[] = { 0, 1, 0, -1};
int area, perimeter, n;
void dfs(int i, int j, vector<vector<char>> &grid){
    area++;
    grid[i][j] = '@';
    for(int d = 0; d < 4; ++d){
        int x = i + dr[d], y = j + dc[d];
        if(x >= 0 && x < n && y >= 0 && y < n) {
            if(grid[x][y] == '#') dfs(x, y, grid);
            else if(grid[x][y] == '.') perimeter++;
        }
        else perimeter++;
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(10) << fixed;
    // IO(""); 

    ifstream fin ("perimeter.in");
    fin >> n;
    vector<vector<char>> grid(n, vector<char> (n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            fin >> grid[i][j];
        }
    }
    int ans_a = 0, ans_p = 1e9;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(grid[i][j] == '#'){
                area = perimeter = 0;
                dfs(i, j, grid);
                if(area > ans_a) {
                    ans_a = area;
                    ans_p = perimeter;
                }
                else if (area == ans_a && perimeter < ans_p) ans_p = perimeter;
            }
        }
    }
    ofstream fout ("perimeter.out");
    fout << ans_a << " " << ans_p << "\n";
}
// when using printf, scanf for long long use %dll
// when using accumulate use 0ll if sum is long long 