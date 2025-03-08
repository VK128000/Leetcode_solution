class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int n=blocks.length();
            int i=0;
            int j=0;
            int count=0;
            int mini=INT_MAX;
    
            while(j<n){
                if(blocks[j]=='W'){
                    count++;
                }
                if(j-i+1==k){
                    mini=min(count,mini);
                    if(blocks[i]=='W') count--;
                    i++;
                }
                j++;
            }
            return mini;
        }
    };