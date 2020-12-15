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
text segment
*/

void ss(int c)
{
    int n, x;
    cin >> n >> x;
    vi arr(n);
    rep(n)  cin >> arr[i];
    vector<bool> del(32, false);
    vi cnt(32, 0);
    int i = 0;
    bool safe = false;
    for(; i < n-1 and x > 0; i++)
    {
        for(int j = 31; j >= 0 and x > 0; j--)
        {
            if(arr[i] & (1 << j))
            {
                cnt[j]++;
                arr[i] ^= (1 << j);
                if(del[j])
                {
                    del[j] = false;
                }
                else
                {
                    // if(j > 0)   safe = true;
                    del[j] = true;
                    x--;
                }
            }
        }
    }

    for(int j = 31; j >= 0; j--)
    {
        if(cnt[j] >= 3 and cnt[j] < n)  safe = true;    //IMP: critical condition
        if(del[j])
        {
            int tmp = n-1;
            for(int it = 0; it < n-1; it++)
            {
                if(arr[it] & (1 << j))
                {
                    tmp = it;
                    break;
                }
            }
            arr[tmp] ^= (1<<j);
            del[j] = false;
        }
    }

    if(x % 2 == 0 or safe)
    {
        rep(n)  cout << arr[i] << " ";
        cout << endl;
        return;
    }
    else
    {
        arr[n-2] = 1;
        arr[n-1] ^= 1;
        rep(n)  cout << arr[i] << " ";
        cout << endl;
        return;
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
    cin>>cases;
    forn(i,0,cases)
    {
        ss(i);
    }
    return 0;
}
