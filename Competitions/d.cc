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

int find_parent(int a, vi &parent)
{
    if(parent[a] < 0)   return a;
    else return parent[a] = find_parent(parent[a], parent);
}

int unify(int a, int b, vi &parent)
{
    int pa = find_parent(a, parent);
    int pb = find_parent(b, parent);
    if(pa == pb)    return -1;
    if(parent[pa] <= parent[pb])
    {
        parent[pa] += parent[pb];
        parent[pb] = pa;
    }
    else
    {
        parent[pb] += parent[pa];
        parent[pa] = pb;
    }
    return 0;
}

void solve(int case_num)
{
    int n,m,a,b,c;
    cin>>n>>m;
    vector<pair<int, pair<int, int>>> w(m);
    vi parent(n+1, -1);

    rep(m)
    {
        cin>>a>>b>>c;
        w[i] = {c,{a,n+b}};
    }
    sort(w.begin(), w.end());
    int cnt = n, ans = 0;
    for(int i = 0; i < m && cnt; i++)
    {
        if(unify(w[i].second.first, w[i].second.second, parent) == 0)
        {
            cnt--;
            ans = max(ans, w[i].first);
        }
    }
    cout<<ans<<endl;
}

int main() 
{
    #ifdef LOCAL_PROJECT
    freopen("/home/shubham/CodingPractice/vsCode/input.txt", "r", stdin);
    freopen("/home/shubham/CodingPractice/vsCode/output.txt", "w", stdout);
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
