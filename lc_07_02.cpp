class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp1; // To keep track of ball colors
        unordered_map<int, int> mp2; // To keep track of color counts
        vector<int> res;
        
        for (const auto& q : queries) {
            int b = q[0];
            int nC = q[1];
            
            if (mp1.find(b) != mp1.end()) {
                int oC = mp1[b];
                mp2[oC]--;
                if (mp2[oC] == 0) {
                    mp2.erase(oC);
                }
            }
            
            mp1[b] = nC;
            mp2[nC]++;
            
            res.push_back(mp2.size());
        }
        
        return res;
    }
};
