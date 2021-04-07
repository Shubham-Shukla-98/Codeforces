#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<pair<int,int>> vpi;
#define sortn(a) sort(a.begin(), a.end())
#define sortr(a) sort(a.begin(), a.end(), greater<>())
#define all(a) a.begin(), a.end()
#define rep(n) for (int i = 0; i < n; i++)
#define forn(i,a,b) for (int i = a; i < b; i++)
#define isBitSet(S, i) ((S >> i) & 1)
#define clear(a) memset(a, 0, sizeof(a))
#define mset(a, b) memset(a, b, sizeof(a))
#define cin(arr)    for(int &a : arr)   cin>>a;

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;
// int 2 * 1e9
// long long 9 * 1e18

#define mad(a,b)    (int)((((ll)a%mod) + ((ll)b%mod))%mod);

//template<typename...T>void input(T &...args) {((cin >> args), ...);}
//template<typename...T>void print(T &&...args) {((cout << args << endl), ...);}
//template<typename...T>void deb(T &&...args) {cout << "~~ "; ((cout << args << " "), ...); cout << endl;}

vi arr, odd, even;
vector<vector<int>> dp;

int game(int i, int j, bool alice)
{
    if(i <= 0 and j <= 0)   return 0;
    if(alice)
    {
        return max(
            game(i-1, j, false),
            (j > 0) ? game(i, j-1, false) + even[j-1] : INT_MIN
        );
    }
    else
    {
        return min(
            game(i, j-1, true),
            (i > 0) ? game(i-1, j, true) + odd[i-1] : INT_MAX
        );
    }
}

void solve(int case_num)
{
    int n;
    cin >> n;
    rep(n)  cin >> arr[i];
    arr.resize(n);
    odd.resize(n);
    even.resize(n);

    for(int i : arr)
    {
        if(i&1) odd.push_back(i);
        else    even.push_back(i);
    }
    sortn(odd);
    sortn(even);
    dp.resize(odd.size() + 1, vi(even.size() + 1, INT_MIN));
    int res = game(odd.size(), even.size(), true);
    if(res > 0) cout <<"Alice" << endl;
    else if(res == 0)   cout << "Tie" <<endl;
    else cout << "Bob" << endl;
}

int main() 
{
    #ifdef LOCAL_PROJECT
    freopen("/home/shubham/CodingPractice/vsCode/input.txt", "r", stdin);
    freopen("/home/shubham/CodingPractice/vsCode/output.txt", "w", stdout);
    #endif
    #ifdef LOCAL_PROJECT_CC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cases = 1;
    cin>>cases;
    forn(i,0,cases)
    {
        solve(i);
    }
    return 0;
}
