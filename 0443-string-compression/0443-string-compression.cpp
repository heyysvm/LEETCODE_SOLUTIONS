class Solution {
public:
    int compress(vector<char>& chars) {
        // vector<int>freq(256,0);
        // for(char ch :chars){
        //     freq[ch-'a']++;
        // }
        // int i =0;
        // for(int i=0;i<256;i++){
        //     if(freq[i]==1)chars[i++]=char('a'+i);
        //     else{
        //         chars[i++]=char('a'+i);
        //         chars[i++]=freq[i];
        //     }
        // }
        // return i+1;

        int i = 0 , idx = 0;

        while(i<chars.size()){
            char curr = chars[i];
            int count = 0;

            while(i<chars.size() && curr == chars[i]){
                count++;
                i++;
            }
            
            chars[idx++]=curr;

            if(count>1){
                string cnt =  to_string(count);
                for(char ch:cnt){
                    chars[idx++]=ch;
                }
            }
        }
        return idx;

    }
};