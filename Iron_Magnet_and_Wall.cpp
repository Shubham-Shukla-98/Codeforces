/*
Chef loves to play with iron (Fe) and magnets (Ma). He took a row of N cells (numbered 1 through N) and placed some objects in some of these cells. You are given a string S with length N describing them; for each valid i, the i-th character of S is one of the following:

'I' if the i-th cell contains a piece of iron
'M' if the i-th cell contains a magnet
'_' if the i-th cell is empty
':' if the i-th cell contains a conducting sheet
'X' if the i-th cell is blocked
If there is a magnet in a cell i and iron in a cell j, the attraction power between these cells is Pi,j=K+1−|j−i|−Si,j, where Si,j is the number of cells containing sheets between cells i and j. This magnet can only attract this iron if Pi,j>0 and there are no blocked cells between the cells i and j.

Chef wants to choose some magnets (possibly none) and to each of these magnets, assign a piece of iron which this magnet should attract. Each piece of iron may only be attracted by at most one magnet and only if the attraction power between them is positive and there are no blocked cells between them. Find the maximum number of magnets Chef can choose.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains a single string S with length N.
Output
For each test case, print a single line containing one integer ― the maximum number of magnets that can attract iron.

Constraints
1≤T≤2,000
1≤N≤105
0≤K≤105
S contains only characters 'I', 'M', '_', ':' and 'X'
the sum of N over all test cases does not exceed 5⋅106
Subtasks
Subtask #1 (30 points): there are no sheets, i.e. S does not contain the character ':'

Subtask #2 (70 points): original constraints

Example Input
2
4 5
I::M
9 10
MIM_XII:M
Example Output
1
2
Explanation
Example case 1: The attraction power between the only magnet and the only piece of iron is 5+1−3−2=1. Note that it decreases with distance and the number of sheets.

Example case 2: The magnets in cells 1 and 3 can attract the piece of iron in cell 2, since the attraction power is 10 in both cases. They cannot attract iron in cells 6 or 7 because there is a wall between them.

The magnet in cell 9 can attract the pieces of iron in cells 7 and 6; the attraction power is 8 and 7 respectively.
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
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
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    vb visited(n, false);

    // rep(n)  if(str[i] == 'X')   visited[i] = true;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(str[i] == 'M')
        {
            bool skip = false;
            int l = i-1, r = i+1, pl, pr;
            pl = pr = k;
            vector<int> irons_in_my_way;
            bool breakl = false, breakr = false;
            while(l >= 0 and pl > 0)
            {
                if(str[l] == 'I')
                {
                    if(visited[l] == true)
                    {
                        skip = true;
                        break;
                    }
                    else
                    {
                        irons_in_my_way.push_back(l);
                    }
                    pl--;
                }
                if(str[l] == 'X')
                {
                    break;
                }
                if(str[l] == '_')   pl--;
                if(str[l] == ':')   pl-=2;
                l--;
            }
            while(r < n and pr > 0 and !skip)
            {
                if(str[r] == 'I')
                {
                    if(visited[r] == true)
                    {
                        skip = true;
                        break;
                    }
                    else
                    {
                        irons_in_my_way.push_back(r);
                    }
                    pr--;
                }
                if(str[r] == 'X')
                {
                    break;
                }
                if(str[r] == ':')   pr-=2;
                else    pr--;
                r++;
            }
            if(skip)    continue;
            for(int index : irons_in_my_way)    visited[index] = true;
            ans++;
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
