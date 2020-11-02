#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
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
    int n;
    cin>>n;
    vi arr(n, 0);
    int first, second, third;
    cout<<"? 1 2"<<endl;
    cin>>first;
    cout<<"? 2 3"<<endl;
    cin>>second;
    cout<<"? 1 3"<<endl;
    cin>>third;
    arr[0] = third - second;
    arr[2] = third - first;
    arr[1] = first - arr[0];
    int sum = third;
    for(int i = 4; i <= n; i++)
    {
        cout<<"? 1 "<<i<<endl;
        cin>>arr[i-1];
        arr[i-1] -= sum;
        sum += arr[i-1];
    }
    cout<<"! ";
    for(int i : arr)    cout<<i<<" ";
    cout<<endl;
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
    // cin>>cases;
    forn(i,0,cases)
    {
        solve(i);
    }
    return 0;
}
