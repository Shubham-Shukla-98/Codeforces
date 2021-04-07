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


int getTime()
{
    string time, m;
    cin >> time >> m;
    string hr = time.substr(0,2);
    string min = time.substr(3);
    int ret = stoi(hr);
    if(hr == "12")
    {
        if(m == "AM")   ret = 0;
        else    ret = 12;
    }
    else if(m == "PM")   ret += 12;
    // }
    // if(m == "AM" and hr == "12")    ret = 0;
    // if(m == "PM" and hr == "12")    ret = 12;
    ret*=60;
    ret += stoi(min);
    // cerr << ret << endl;
    return ret;
}

void solve(int case_num)
{
    int meet = getTime();
    int n;  cin >> n;
    rep(n)
    {
        int l = getTime();
        int r = getTime();
        if(l <= meet and meet <= r)
        {
            cout << "1";
        }
        else{
            cout << "0";
        }
    }
    cout << endl;
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
        solve(i);
    }
    return 0;
}
