class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> anagramMap;
        bool anagram = true;
        if(s.size() != t.size()){
            return false;
        }
        for(int i = 0; i < s.size(); ++i){
            anagramMap[s[i]]++;
            anagramMap[t[i]]--;
        }
        for(int i = 0; i < s.size(); ++i){
            if(anagramMap[s[i]] != 0){
                anagram = false;
            } 
        }
        return anagram;
    }
};
