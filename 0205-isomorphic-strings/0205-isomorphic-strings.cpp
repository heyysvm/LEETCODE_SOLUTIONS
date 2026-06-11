class Solution {
public:

 bool get (string s1 , string s2){
            
            if(s1.length()!=s2.length())return false;
            unordered_map<char,char>mp;
            int n = s1.length();
            for(int i=0;i<n;i++){
                if(mp.find(s1[i])==mp.end()){
                    mp[s1[i]]=s2[i];
                }
                else if(mp[s1[i]]!=s2[i]){
                    return false;
                }
            }  return true;              
        }


    bool isIsomorphic(string s, string t) {

        return get(s,t) && get(t,s);
       
    }
};