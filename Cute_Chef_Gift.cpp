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
#define mad(a,b)    (int)((((ll)a%mod) + ((ll)b%mod))%mod);

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;

template<typename...T>void input(T &...args) {((cin >> args), ...);}
template<typename...T>void print(T &&...args) {((cout << args << endl), ...);}
template<typename...T>void deb(T &&...args) {cout << "~~ "; ((cout << args << " "), ...); cout << endl;}

const int limit = 1e5+1;
bool primes[limit];

void seive()
{
    mset(primes, true);
    for(int i = 4; i <= limit; i+=2) primes[i] = false;
    for(int i = 3; i*i < limit; i+=2)
    {
        if(primes[i])
        {
            for(int j = i*i; j < limit; j+=i)   primes[j] = false;
        }
    }
}

vi getfactors(int x)
{
    vi ret;
    if(primes[x])   return {x};
    for(int i = 2; i <= x; i++)
    {
        if(primes[i] and x%i == 0)
        {
            x = x / i;
            ret.push_back(i);
        }
    }
    return ret;
}

int solve(int case_num)
{
    int n;
    cin>>n;
    vi arr(n);
    rep(n)  cin>>arr[i];
    seive();
    // for(int i = 2; i <= 30; i++)    cout<<primes[i]<<" ";
    cout<<endl;
    vvi factors(n);
    rep(n)
    {
        factors[i] = getfactors(arr[i]);
    }
    unordered_map<int, int> st, end;
    for(int i = 0; i < n; i++)
    {
        for(int x : factors[i])
        {
            if(st[x] == 0)  st[x] = i+1;
            end[x] = i+1;
        }
    }
    vi diff(n+1, 0);
    for(auto p : st)
    {
        diff[p.second]++;
    }
    for(auto p : end)
    {
        diff[p.second]--;
    }
    for(int i = 2; i <= n; i++)
    {
        diff[i] += diff[i-1];
        if(diff[i] == 0)    return i;
    }
    for(int i : diff)   cout<<i<<" ";
    return 0;
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
        cout<<solve(i)<<endl;
    }
    return 0;
}
