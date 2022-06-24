// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int n = A.size();
        int sum1=0;
        for(int i=0;i<A.size();i++){
            sum1+=A[i];
        }
        if((sum1 + target) % 2 != 0)
            return 0;
        int sum=(sum1+target)/2;
        
        int t[A.size()+1][sum+1];
        for(int i=1;i<sum+1;i++){
            t[0][i]=0;
        }
        for(int i=0;i<n+1;i++){
            t[i][0]=1;
        }
	    for(int i=1;i<=n;i++){
	        for(int j=0;j<=sum;j++){
	            if(A[i-1]<=j){
	                t[i][j] = t[i-1][j-A[i-1]] + t[i-1][j];
	            }
	            else{
	                t[i][j] = t[i-1][j];
	            }
	        }
	    }
	    return t[n][sum];
	    /*int count=0;
	    for(int i=0;i<=sum;i++){
	        if(t[n][i] && sum-2*i == target)
	            count++;
	    }
	    return count;*/
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends