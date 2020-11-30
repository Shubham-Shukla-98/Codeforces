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

template<typename...T>void input(T &...args) {((cin >> args), ...);}
template<typename...T>void print(T &&...args) {((cout << args << endl), ...);}
template<typename...T>void deb(T &&...args) {cout << "~~ "; ((cout << args << " "), ...); cout << endl;}


void solve(int case_num)
{
    string sa, sb;
    cin >> sa >> sb;
    if(sa == sb)
    {
        cout<<0<<endl;
        return;
    }
    int sc = sa.size();
    int st = 0, end = sc - 1;
    // for(int i = 0; i < sc; i++)
    while(st < sc and sa[st] == sb[st])        st++;
    while(end >= 0 and sa[end] == sb[end])      end--;

    int ans = 0;
    // while(sa != sb)
    // {
    //     for(int i = st, j = 1; i <= end; i++, j++)
    //     {
    //         if(sa[i] == sb[i])  break;
    //         else
    //         {
    //             if(j&1) sa[i] = (sa[i] == '1') ? '0' : '1'; 
    //         }
    //         while(st < sc and sa[st] == sb[st])        st++;
    //     }
    //     cout<<sa<<endl;
    //     ans++;
    // }
    while(sa != sb and st < sc)
    {
        ans++;
        // int odd = 0;
        // if( (end - st)%2 == 1)  odd = 1;
        for(int i = st, j = 1; i < sc; i++, j++)
        {
            if(j&1)
            {
                if(sa[i] == sb[i])  break;
                sa[i] = (sa[i] == '1') ? '0' : '1';
            }
        }
        while(st < sc and sa[st] == sb[st])        st++;
        // while(end >= 0 and sa[end] == sb[end])      end--;
        // cout<<sa<<endl;
    }
    cout<<ans<<endl;
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
