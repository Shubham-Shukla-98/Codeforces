#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
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

template<typename...T>void input(T &...args) {((cin >> args), ...);}
template<typename...T>void print(T &&...args) {((cout << args << endl), ...);}
template<typename...T>void deb(T &&...args) {cout << "~~ "; ((cout << args << " "), ...); cout << endl;}

const int limit = 1e8+1;
bool primes[limit];

void seive()
{
    mset(primes, true);
    for(int i = 4; i < limit; i+=2) primes[i] = false;
    for(int i = 3; i*i < limit; i+=2)
    {
        if(primes[i])
        {
            for(int j = i*i; j < limit; j+=i)   primes[j] = false;
        }
    }
}

void solve(int case_num)
{
    int n;
    cin >> n;
    vi pos(n+1),ans(n+1, 1);
    rep(n)  cin >> pos[i+1];
    // no seive needed if we move in reverse direction while increasing val
    // seive();
    int cp = 2, val = 2;
    for(int i = n; i > 0; i--)
    {
        if(pos[i] == i) ans[i] = val++;
        else    ans[i] = ans[pos[i]];        
    }
    // vi prime(val+1);
    // for(int i = 1; i <= val; i++)
    // {
    //     prime[i] = cp;
    //     while(!primes[++cp]){};
    // }
    // rep(n)  ans[i+1] = prime[ans[i+1]];
    rep(n)  cout<<ans[i+1]<<" ";
    cout<<endl;
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
