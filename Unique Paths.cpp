#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        const int N=105;
        m=m-1;
        n=n-1;
        int dp[N][N];
        dp[0][0] =1;
        for(int i=1; i<=m; i++)dp[i][0]=1;
        for(int i=1; i<=n; i++)dp[0][i]=1;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};
const int N =101;
int dp[N][N];
int solve(int row,int coll);
int main()
{
    memset(dp, -1, sizeof(dp));
    int r,c;
    cin>>r>>c;
    //cout<<solve(r-1,c-1);
    Solution a;
    cout<<a.uniquePaths(r,c);
    return 0;
}
int solve(int row,int coll)
{
//base case
    if(row ==0 && coll ==0)return 1;

// if the current state already solved then return it
    if(dp[row][coll] !=-1)return dp[row][coll];
// solve the current state
    int ans = 0;
    if(row!=0)
        ans += solve(row-1,coll);//upper cell
    if(coll!=0)
        ans += solve(row,coll-1);//left cell
    return ans;
}
