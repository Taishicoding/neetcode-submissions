class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        char tempI,tempJ;
        while(i < j){
            tempI = tolower(s[i]);
            while(!isalnum(tempI) && i < s.size()){
                ++i;
                tempI = tolower(s[i]);
            }
            if(i == s.size()){
                return true;
            }
            tempJ = tolower(s[j]); 
            while(!isalnum(tempJ) && j > 0){
                --j;
                tempJ = tolower(s[j]);
            }
            if(tempI != tempJ){
                return false;
            }else{
                ++i;
                --j;
            }
        }
        return true;
    }
};
