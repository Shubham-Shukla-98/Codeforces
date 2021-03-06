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
#define rep(n) for (int i = 0; i < n; i++)
#define forn(i,a,b) for (int i = a; i < b; i++)
#define deb(x) cout << #x << " : " << x << endl;
#define isBitSet(S, i) ((S >> i) & 1)
#define cin(arr)    for(int &a : arr)   cin>>a;

const int INF = 1e6 + 5;
const int mod = 1e9 + 7;
// int 2 * 1e9
// long long 9 * 1e18

#define mad(a,b)    (int)((((ll)a%mod) + ((ll)b%mod))%mod);

void solve(int case_num)
{
    int n, m;
    cin>>n>>m;
    vi a(n),b(n);
    rep(n)  cin>>a[i];
    rep(n)  cin>>b[i];
    sortn(a);
    sort(b.begin(), b.end(), greater<>());
    rep(n)
    {
        if(a[i]+b[i] > m)
        {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main() 
{
    // #ifdef LOCAL_PROJECT
    // freopen("/home/shubham/CodingPractice/vsCode/input.txt", "r", stdin);
    // freopen("/home/shubham/CodingPractice/vsCode/output.txt", "w", stdout);
    // #endif
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
