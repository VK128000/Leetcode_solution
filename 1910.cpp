class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        
        while(s.find(part)!=-1){
            int ind=s.find(part);
            string temp="";
            if(ind!=-1 && ind>=0){
                temp+=s.substr(0,ind);
                temp+=s.substr(ind+part.length());
            }
            //cout<<temp<<endl;
            
            s=temp;
            
        }
        cout<<endl;
        return s;
    }
};