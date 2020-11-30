#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<pair<int,int>> vpi;
#define sortn(a) sort(a.begin(), a.end())
#define sortr(a) sort(a.begin(), a.end(), greater<>())
#define all(a) a.begin(), a.end()
#define rep(n) for (int i = 0; i < n; i++)
#define forn(i,a,b) for (int i = a; i < b; i++)
#define isBitSet(S, i) ((S >> i) & 1)
#define cin(arr)    for(int &a : arr)   cin>>a;

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;
// int 2 * 1e9
// long long 9 * 1e18

#define mad(a,b)    (int)((((ll)a%mod) + ((ll)b%mod))%mod);

void solve(int case_num)
{
    int n,q;
    cin>>n>>q;
    vi arr(n);
    rep(n)  cin>>arr[i];
    int ans = 1;
    forn(i,1,n) if(arr[i] != arr[i-1])  ans++;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        if(arr[x] != y)
        {
            // check if updating value increases length of subsequence
            if(x - 1 >= 0 and arr[x] == arr[x-1])   ans++;
            if(x + 1 < n and arr[x] == arr[x+1])    ans++;
            // update value
            arr[x] = y;
            // check if updating value decreases length of subsequence
            if(x - 1 >= 0 and arr[x] == arr[x-1])   ans--;
            if(x + 1 < n and arr[x] == arr[x+1])    ans--;
        }
        cout<<ans<<endl;
    }
}

int main() 
{
    #ifdef LOCAL_PROJECT
    freopen("/home/shubham/CodingPractice/vsCode/input.txt", "r", stdin);
    freopen("/home/shubham/CodingPractice/vsCode/output.txt", "w", stdout);
    #endif
    #ifdef LOCAL_PROJECT_WIN
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
