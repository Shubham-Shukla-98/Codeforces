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


int findNumberOfLIS(vector<int>& arr) 
{
    int ans = 0;
    
    int sz = arr.size();
    
    vector<int> dp(sz, 1), count(sz, 1);
    
    for(int i = sz-1; i >= 0; i--)
    {
        int mx = 0, cnt = 1;
        for(int j = i+1; j < sz; j++)
        {
            if(arr[i] < arr[j])
            {
                dp[i] = max(dp[i], 1 + dp[j]);
                if(mx < dp[j])
                {
                    mx = dp[j];
                    cnt = 0;
                }
                if(mx == dp[j]) cnt+=count[j];
            }
        }
        count[i] = cnt;
    }
    
    return count[ans];
}

void solve(int case_num)
{
    vi arr = {1,3,5,4,7};
    cout<< findNumberOfLIS(arr) << endl;
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
