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
    int n, c;
    cin >> n >> c;
    if(c < n-1 or c > (n*(n-1)/2))  
    {
        cout << "IMPOSSIBLE" ;
        return ;
    }

    vi ans(n, 0);
    rep(n)  ans[i] = i+1;

    int start = 0, end = 0;
    c -= (n-1);

    while(c)
    {
        if(c >= n-1-start)
        {
            reverse(ans.begin() + start, ans.end() - end);
            c -= ((n-1)-start);
            end++;
        }
        else
        {
            reverse(ans.begin() + start, ans.begin() + start + c + 1);
            c = 0;
            start++;
        }
    }
    rep(n)  cout << ans[i] << " ";
}

void ss()
{
    int n,c;
    cin >> n >> c;
    
    if(c < n-1 or c >= (n*(n+1)/2))  
    {
        cout << "IMPOSSIBLE" ;
        return ;
    }
 
    vi ans(n, 0);

    int left = 0, right = n-1, num = 1;

    c -= right;
    bool inverted = true;

    while(c >= 0)
    {
        // cout << "Looped " << endl;
        if(c >= right - left)
        {
            c -= (right - left);
            if(inverted)
            {
                ans[right--] = num++;
            }
            else
            {
                ans[left++] = num++;
            }
            inverted = !inverted;
        }
        if(c < right - left)
        {
            if(inverted)
            {
                ans[left+c] = num++;
                for(int v = left; v < left + c; v++)
                {
                    ans[v] = num++;
                }
                for(int v = left + c + 1; v <= right; v++)
                {
                    ans[v] = num++;-*87
                }
            }
            else
            {
                ans[right-c] = num++;
                for(int v = right; v > right - c; v--)
                {
                    ans[v] = num++;
                }
                for(int v = right - c - 1; v >= left; v--)
                {
                    ans[v] = num++;
                }
            }
            c = -1;
        }
    }
    rep(n)  cout << ans[i] << " ";
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
        cout << "Case #"<<i+1<<": ";
        // solve(i);
        ss();
        cout << endl;
    }
    return 0;
}
