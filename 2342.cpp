class Solution {
public:
    typedef long long ll;
    ll solve(int n){
        ll sum=0;
        while(n>0){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<ll,int>mp;
        ll maxi=0;
        for(int i=0;i<nums.size();i++){
            ll x=solve(nums[i]);
            if(mp.find(x)!=mp.end()){
                maxi=max(maxi,nums[i]+0LL+mp[x]);
            }
            mp[x]=nums[i];
        }
        if(maxi==0) return -1;
        return maxi;

    }
};