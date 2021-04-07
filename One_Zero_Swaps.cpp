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


int solve(int case_num)
{
    int n;
    cin >> n;
    string str1, str2;
    cin >> str1 >> str2;
    int z = 0, o = 0;
    vi zeroesSoFar(n+1, 0), z2(n+1, 0);
    int i = 1;
    for(char c : str2){
        if(c == '1')
        {
            o--;
            z2[i] = z2[i-1];
        }
        else
        {
            z--;
            z2[i] = z2[i-1] + 1;
        }
        i++;
    }
    i = 1;
    for(char c : str1){
        if(c == '1')
        {
            o++;
            zeroesSoFar[i] = zeroesSoFar[i-1];
        }
        else
        {
            z++;
            zeroesSoFar[i] = zeroesSoFar[i-1] + 1;
        }
        if(zeroesSoFar[i] > z2[i])  return 0;
        i++;
    }
    if(o != 0 or z != 0)    return 0;
    return 1;
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
        if(solve(i))    cout << "Yes" << endl;
        else    cout << "No" << endl;
    }
    return 0;
}
