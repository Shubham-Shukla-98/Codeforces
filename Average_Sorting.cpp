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
    int n;
    cin >> n;
    vi arr(n);
    rep(n)  cin >> arr[i];
    vi left(n,0), right(n,0);
    left[0] = arr[0];
    right[n-1] = arr[n-1];
    int minimum = left[0];
    int maximum = left[0];
    int gx = 0;
    int gm = 0;
    for(int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1], arr[i]);
        if(minimum >= left[i])
        {
            minimum = left[i];
            gm = i;
        }
        if(maximum <= left[i])
        {
            maximum = left[i];
            gx = i;
        }
    }
    for(int j = n-2; j>=0; j--)
    {
        right[j] = max(right[j+1], arr[j]);
    }
    for(int i = 0; i < n; i++)
    {
        if(left[i] > right[i])
        {
            cout << "No" << endl;
            return;
        }
    }

    if(gx < gm || minimum == maximum)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;

    // for(int i = 0; i < n; i++)
    // {

    // }


    // int minimum = arr[0];
    // int maximum = arr[0];
    // for(int i = 1; i < n; i++)
    // {
    //     minimum = min(minimum, arr[i]);
    //     maximum = max(maximum, arr[i]);
    // }
    // if(arr[n-1] < maximum || minimum == maximum)
    //     cout << "No" << endl;
    // else
    //     cout << "Yes" << endl;
}

// 8 6 7 5 4 3 2 1

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
