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


void solve(int case_num)
{
    int n;  cin >> n;
    vector<string> grid(n);
    rep(n)  cin >> grid[i];
    vi left(10, n), right(10, -1), up(10, n), down(10, -1);
    vi lefty(10, n), righty(10, -1), upy(10, n), downy(10, -1);
    
    for(char c = '0'; c <= '9'; c++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == c)
                {
                    if(left[c-'0'] > i){
                        left[c-'0'] = i;
                        lefty[c-'0'] = j;
                    }
                    if(right[c-'0'] < i){
                        right[c-'0'] = i;
                        righty[c-'0'] = j;
                    }
                    if(up[c-'0'] > j){
                        up[c-'0'] = j;
                        upy[c-'0'] = i;
                    }
                    if(down[c-'0'] < j){
                        down[c-'0'] = j;
                        downy[c-'0'] = i;
                    }
                }
            }
        }
    }
    n--;
    for(int i = 0; i < 10; i++)
    {
        int ans = 0;
        if(right[i] == -1)
        {
            cout << "0 ";
            continue;
        }
        ans = max((right[i] - left[i]) * max(max(n - righty[i], righty[i]), max(n - lefty[i], lefty[i])),
         (down[i] - up[i]) * max(max(n - upy[i], upy[i]), max(n-downy[i], downy[i])));
        cout << ans << " ";
    }
    cout << endl;
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
