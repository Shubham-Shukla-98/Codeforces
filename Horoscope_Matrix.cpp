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
    int n, m;
    cin >> n >> m;
    vvi arr(n, vi(m));
    rep(n){
        forn(j,0,m){
            cin >> arr[i][j];
        }
    }
    unordered_map<int, bool> horo;

    for(int i = 1; i < n; i++)
    {
        int t = i+1;
        int val = arr[i][0];
        bool flag = true;
        for(int j = 2; j < m and t < n and flag; j++, t++)
        {
            if(val != arr[t][j])    flag = false;
        }
        horo[-i] = flag;
    }
    for(int j = 0; j < m; j++)
    {
        int t = j+1;
        int val = arr[0][j];
        bool flag = true;
        for(int i = 1; i < n and t < m and flag; i++, t++)
        {
            if(val != arr[i][t])    flag = false;
        }
        horo[j] = flag;
    }

    int q;
    cin >> q;
    while(q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int pl = x - y;
        x--;
        y--;
        arr[x][y] = z;
        bool flag = true;
        if(x >= y)
        {
            x -= y;
            y = 0;
            x++;
            for(int j = 1; j < m and x < n and flag; j++, x++)
            {
                if(z != arr[x][j])  flag = false;
            }

        }
        else
        {
            y -= x;
            x = 0;
            y++;
            for(int i = 1; i < n and y < m and flag; i++, y++)
            {
                if(z != arr[i][y])  flag = false;
            }
        }
        horo[pl] = flag;
        if(!flag)
        {
            cout << "No" <<endl;
            continue;
        }
        for(auto p : horo)
        {
            if(p.second == false)
            {
                cout << "No" <<endl;
                flag = false;
                break;
            }
        }
        if(flag)
            cout << "Yes" << endl;        
    }
}
// }
// {
//     for(int i = m-2; i >= 0; i--){
//         int t = i + 1, val = arr[i][0];
//         bool safe = true;
//         for(int j = 1; j < n and t < m; j++, t++){
//             if(val != arr[t][j]){
//                 safe = false;
//                 break;
//             }
//         }
//         horo[m - 1 - i] = safe;
//     }
//     for(int i = 1; i < n - 1; i++){
//         int t = i, val = arr[0][i];
//         bool safe = true;
//         for(int j = 1; i < m; j++){
//             if(val != arr[j][t]){
//                 safe = false;
//                 break;
//             }
//         }
//         horo[m + i] = safe;
//     }
//     int q;
//     cin >> q;
//     while(q--)
//     {
//         int x,y,z;
//         cin >> x >> y >> z;
//         x--;
//         y--;
//         arr[x][y] = z;
//         int a = x - y;
//         if(a == 0)
//         {
//             int cal = z;
//             bool done = false;
//             for(int i = 0; i < n; i++)
//             {
//                 for(int j = 0; j < m; j++)
//                 {
//                     if(arr[i][j] != z)
//                     {
//                         done = true;
//                     }
//                 }
//             }
//             if(done)
//             {
//                 cout << "No" << endl;
//                 continue;
//             }
//             else
//             {
//                 cout << "Yes" << endl;
//             }
//         }    
//         else
//         {
            
//         }
            
//     }
// }

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
