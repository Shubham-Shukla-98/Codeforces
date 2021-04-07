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
    int n; cin >> n;
    vvi gr(n+1);
    vvi edges(n+1, vi(2));
    rep(n-1)
    {
        int x, y;
        cin >> x >> y;
        edges[i+1][0] = x;
        edges[i+1][1] = y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    unordered_map<int, int> vals;
    int query;
    cin >> query;
    rep(query)
    {
        int t, e, c;
        cin >> t >> e >> c;
        int avoid = ((t == 1) ? edges[e][1] : edges[e][0]);
        int use = ((t == 2) ? edges[e][1] : edges[e][0]);
        queue<int> q;
        q.push(use);
        vector<bool> visited(n+1, false);
        while(!q.empty())
        {
            int s = q.front();
            q.pop();
            visited[s] = true;
            if(vals.find(s) == vals.end())    vals[s] = c;
            else    vals[s]+=c;
            for(int ne : gr[s])
            {
                if(ne != avoid and !visited[ne]) q.push(ne);
            }
        }
    }
    rep(n)  cout<<vals[i+1]<<endl;
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
