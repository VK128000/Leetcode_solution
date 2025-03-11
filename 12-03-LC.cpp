class Solution {
    public:
        int numberOfSubstrings(string s) {
            int n=s.length();
            vector<int>v(3,0);
            int i=0,j=0,ans=0;
            while(j<n){
                v[s[j]-'a']++;
                while(v[0] && v[1] && v[2]){
                    ans+=(n-j);
                    v[s[i]-'a']--;
                    i++;
                }
                j++;
            }
            return ans;
        }
    };