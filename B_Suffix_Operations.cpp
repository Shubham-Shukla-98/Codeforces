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


void solve(int c)
{
    int n;
    cin >> n;
    vi arr(n);
    rep(n)  cin >> arr[i];
    vi cost(n, 0), savings(n, 0);
    for(int i = n-1; i > 0; i--)
    {
        cost[i] = abs(arr[i] - arr[i-1]);
    }

}

void solve1(int case_num)
{
    int n;
    cin >> n;
    vi arr(n);
    rep(n)  cin >> arr[i];
    ll diff = 0, change = n;
    vl cost(n, 0);
    // cost[0] = abs(arr[0] - arr[1]);
    for(int i = 0; i < n-1; i++)
    {
        cost[i] = /*abs(arr[i] - arr[i-1]) + */abs(arr[i] - arr[i+1]);
    }
    // cost[n-1] = abs(arr[n-1] - arr[n-2]);
    
    for(int i = 0; i < n-1; i++)
    {
        // cerr << cost[i] << " ";
        if(diff < cost[i])
        {
            diff = cost[i];
            change = abs(arr[i+1] - arr[i-1]);
        }
    }
    // cerr << endl;
    // // int prev = (change > 0) ? abs(arr[change] - arr[change-1]): INT_MAX;
    // // int next = (change < n-1) ? abs(arr[change] - arr[change+1]): INT_MAX;
    // // if(change == n); 
    // // else if(prev > next) arr[change] = arr[change + 1];
    // // else if(prev < next)   arr[change] = arr[change - 1];
    // arr[change] = arr[change+1];
    // cerr << "changed " << change << " to " << arr[change] << endl;
    ll ans = 0;
    for(int i = n-1; i > 0; i--)
    {
        ans += abs(arr[i] - arr[i-1]);
    }
    ans -= diff;
    cout << ans << endl;
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
