#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vll;
typedef pair<int,int> pi;
typedef vector<vector<ll>> vvi;
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
    int n,m;
    cin>>n>>m;
    vvi mat(n,vi(m));
    rep(n)
    {
        forn(j,0,m)
        {
            cin>>mat[i][j];
        }
    }
    ll inc = 0;
    
    forn(i, 0 , n/2)
    {
        forn(j, 0, m/2)
        {
            vi tmp = { mat[i][j], mat[i][m-1-j], mat[n-1-i][j], mat[n-1-i][m-1-j] };
            sortn(tmp);
            inc += (tmp[2] - tmp[0]) + (tmp[2] - tmp[1]) + (tmp[3] - tmp[2]);
        }
    }
    if(n&1)
    {
        int i = 0, j = m - 1,mid = n/2;
        while(i<j)
            inc+=abs(mat[mid][i++] - mat[mid][j--]);
    }

    if(m&1)
    {
        int i = 0, j = n - 1, mid = m/2;
        while(i<j)
            inc+=abs(mat[i++][mid] - mat[j--][mid]);
    }

    cout<<inc<<endl;
}

int main() 
{
    #ifdef LOCAL_PROJECT
    freopen("/home/shubham/CodingPractice/vsCode/input.txt", "r", stdin);
    freopen("/home/shubham/CodingPractice/vsCode/output.txt", "w", stdout);
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
