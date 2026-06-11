class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string ans ="";
        vector <string> v;
        while ( ss >> word){
            v.push_back(word);
        }

        int n = v.size()-1;

        for(int i=n ; i>=0; i--){
            ans = ans + v[i] + " ";
        }
        ans.pop_back();
        return ans;
    }
};