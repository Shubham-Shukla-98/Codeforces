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

/*
TXT

each element can be from 0 - 36 inclusive
* so we can do one thing find min from the grid and delete from each elem 
if number is greater less than 27 one digit can be zero

*/

bool recurse(int i, int j, int n, vvi &grid, vvi &ans)
{
    if(i == n and j == n)   return true;
    if(i > n or j > n)  return false;
    if(grid[i][j])
    {
        
    }
}

void bt(int)
{
    int n;
    cin >> n;
    vvi arr(n, vi(n,0)), ans(n+1, vi(n+1, 0));
    for(auto &v : arr)
        for(int &a : v) cin >> a;
    
    for(int t = 1; t <= 9; t++)
    {

    }
}



void solve(int case_num)
{
    int n;
    cin >> n;
    vvi arr(n, vi(n,0)), ans(n+1, vi(n+1, 0));
    for(auto &v : arr)
        for(int &a : v) cin >> a;
    
    for(int k = 0; k < 9; k++)
    {
        for(int i = n; i >= 0; i--)
        {
            for(int col = i; col >= 0; col--)
            {
                if(
                        (i < n and col < n and arr[i][col] <= 0) or
                        (i-1 >= 0 and col < n and arr[i-1][col] <= 0) or 
                        (col - 1 >= 0 and i < n and arr[i][col-1] <= 0) or 
                        (i-1 >= 0 and col-1 >= 0 and arr[i-1][col-1] <= 0)
                )
                {
                    continue;
                }
                else
                {
                    ans[i][col]++;
                    if(i < n and col < n)   arr[i][col]--;
                    if(i-1 >= 0 and col < n)    arr[i-1][col]--;
                    if(col-1 >= 0 and i < n)  arr[i][col-1]--;
                    if(i-1 >= 0 and col-1 >= 0) arr[i-1][col-1]--;
                }
            }
            for(int row = i-1; row >= 0; row--)
            {
                if(
                        (i < n and row < n and arr[row][i] <= 0) or
                        (i-1 >= 0 and row < n and arr[row][i-1] <= 0) or 
                        (row - 1 >= 0 and i < n and arr[row - 1][i] <= 0) or 
                        (i-1 >= 0 and row-1 >= 0 and arr[row-1][i-1] <= 0)
                )
                {
                    continue;
                }
                else
                {
                    ans[row][i]++;
                    if(i < n) arr[row][i]--;
                    if(i-1 >= 0)    arr[row][i-1]--;
                    if(row-1 >= 0 and i < n)  arr[row-1][i]--;
                    if(i-1 >= 0 and row-1 >= 0) arr[row-1][i-1]--;
                }
            }
            for(auto &v : ans)
            {
                for(int i : v)
                {
                    cout << i << " ";
                }
                cout<<endl;
            }    
            cout <<"*****************************"<<endl;
            for(auto &v : arr)
            {
                for(int i : v)
                {
                    cout << i << " ";
                }
                cout<<endl;
            }       
            cout <<"-------------------------------"<<endl;
        }
    }
    for(auto &v : ans)
    {
        for(int i : v)
        {
            cout<<i;
        }
        cout<<endl;
    }
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
    // cin>>cases;
    forn(i,0,cases)
    {
        solve(i);
    }
    return 0;
}
