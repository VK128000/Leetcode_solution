class Solution {
    public:
      int dp[100005];
      int solve(int ind,vector<int>&cost){
          if(ind>=cost.size()) return 0;
          if(dp[ind]!=-1) return dp[ind];
          int a=cost[ind]+solve(ind+1,cost);
          int b=cost[ind]+solve(ind+2,cost);
          
          return dp[ind]=min(a,b);
      }
      int minCostClimbingStairs(vector<int>& cost) {
          // Write your code here
          memset(dp,-1,sizeof(dp));
          return min(solve(0,cost),solve(1,cost));
      }
  };