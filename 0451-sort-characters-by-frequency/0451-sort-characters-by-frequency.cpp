class Solution {
public:
    string frequencySort(string s) {
        vector<int>freq(256,0);
        for(char c:s){
            freq[c]++;
        }
        string ans;
        while(true){
            int mx = 0;
            char ch;

            for(int i=0;i<256;i++){ 
                if(freq[i]>mx){
                    mx=freq[i];
                    ch = char(i);
                }
            }
            if (mx==0) break;
            ans.append(mx,ch);
            freq[ch]=0;

        }
        return ans;
    }
};