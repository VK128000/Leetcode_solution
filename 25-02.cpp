class Solution {
    public:
        typedef long long ll;
        int mod=1e9+7;
        int numOfSubarrays(vector<int>& arr) {
            int cnt1=0,cnt2=0;
            int ans=0,n=arr.size();
            vector<ll>pre(n,0);
            pre[0]=arr[0];
            for(int i=1;i<n;i++){
                pre[i]=pre[i-1]+arr[i];
            }
    
            for(int i=0;i<n;i++){
                if(pre[i]&1){
                    //yadi odd hai to ek subarray already + no of even prefix
                    ans=(ans%mod+1%mod)%mod;
                    ans=(ans%mod+cnt2%mod)%mod;
                    cnt1++;
                }else{
                    //yadi even hai to number of odd prefix;
                    ans=(ans%mod+cnt1%mod)%mod;
                    cnt2++;
                }
            }
            return ans;
    
        }
    };