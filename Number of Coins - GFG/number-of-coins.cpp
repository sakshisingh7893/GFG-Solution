// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    /*int t[M+1][V+1];
	    for(int i=0;i<=M;i++){
	        for(int j=0;j<=V;j++){
	            t[i][j]=INT_MAX;
	        }
	    }
	    for(int i=0;i<=V;i++){
	        t[0][i]=-1;
	    }
	    for(int i=0;i<=M;i++){
	        t[i][0]=0;
	    }*/
	    int W=V;
    int n=M;
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
     dp[i][0]=0;
    for(int j=0;j<=W;j++)
     dp[0][j]=INT_MAX-1;
    for(int j=1;j<=W;j++){
     if(j%coins[0]==0)
      dp[1][j]=j/coins[0];
     else
      dp[1][j]=INT_MAX-1;
    }
    for(int i=2;i<=n;i++){
     for(int j=1;j<=W;j++){
      if(coins[i-1]<=j)
       dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
      else
       dp[i][j]=dp[i-1][j];
     }
    }
    if(dp[n][W]==INT_MAX || dp[n][W]==INT_MAX-1)
        return -1;
    return dp[n][W];
	    
	    
	}
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends