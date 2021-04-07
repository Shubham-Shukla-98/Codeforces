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

void ssls(int sdfsa)
{
    string str;
    cin >> str;
    vector<int> cnt(26, 0);
    for(char c : str)   cnt[c - 'a']++;
    vi duets(26, 0), singles(26, 0);
    int td = 0, ts = 0;
    rep(26)  duets[i] = cnt[i] / 2;
    rep(26)     td +=  duets[i];
    rep(26)  singles[i] = cnt[i] % 2;
    rep(26)     ts += singles[i];

    int ans = 0;
    if(td >= ts)
    {
        td -= ts;
        ans = ts;
        ans += (2 * td) / 3;
    }
    else
    {
        ans = td;
    }
    cout << ans << endl;
}

void solve(int case_num)
{
    string str;
    cin >> str;
    vector<int> cnt(26, 0);
    for(char c : str)   cnt[c - 'a']++;
    vi triplets(26, 0), duets(26, 0), singles(26, 0);
    int tt = 0, td = 0, ts = 0;
    for(int i = 0; i < 26; i++)
    {
        triplets[i] = cnt[i] / 3;
        tt += triplets[i];
        duets[i] = (cnt[i] % 3 == 2);
        td += duets[i];
        singles[i] = (cnt[i] % 3 == 1);
        ts += singles[i];
    }
    int ans = 0;
    if(ts > td)
    {
        ans += td;
        td = 0;
        ts -= td;
        if(ts <= 1)
        {
            ans += tt;
            cout << ans << endl;
            return;
        }
        for(int i = 0; i < 26; i++)
        {
            if(singles[i] == 0)
            {
                while(triplets[i] >= 2)
                {
                    tt-=2;
                    triplets[i] -= 2;
                    ans += 2;
                }
            }
        }
        ans += tt;
        cout << ans << endl;
    }
    else
    {
        ans += ts;
        ts = 0;
        td -= ts;
        for(int i = 0; i < 26; i++)
        {

        }
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
        ssls(i);
    }
    return 0;
}
