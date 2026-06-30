class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        if(s.empty()){
            return "";
        }
        string prefix = s[0];
        for(int i = 1;i<s.size();i++){
            while(s[i].find(prefix) != 0){
                prefix.pop_back();
                if(prefix.empty()){
                    return "";
                }
            }
        }
        return prefix;
    }
};
