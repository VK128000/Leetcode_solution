class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int currsum=0,maxi=0,mini=0,ans=0;
    
            for(auto i:nums){
                currsum+=i;
                ans=max(ans,max(abs(currsum-mini),abs(currsum-maxi)));
                maxi=max(maxi,currsum);
                mini=min(mini,currsum);
            }
            return ans;
    
        }
    };