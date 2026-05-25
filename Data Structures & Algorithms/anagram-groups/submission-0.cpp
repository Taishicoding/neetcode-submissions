class Solution {
public:
    bool wordMap(const string& word1,const string& word2){
        unordered_map<char, int> wordMap;
        if(word1.size() != word2.size()){
            return false;
        }
        for(int i = 0; i < word1.size(); ++i){
            wordMap[word1[i]]++;
            wordMap[word2[i]]--;
        }
        for(const auto& [key, val] : wordMap){
            if(wordMap[key] != 0){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> finalVector; //creating vector of vectors filled with strings
        string tempWord;
        bool wordExists;
        for(int i = 0; i < strs.size();++i){
        wordExists = false;
            tempWord = strs[i];
            for(int j = 0; j < finalVector.size(); ++j){
                if(wordMap(tempWord, finalVector[j][0])){
                    finalVector[j].push_back(tempWord);
                    wordExists = true;
                    //If the words are anagram, add the word
                    break;
                }
            }
            if(wordExists == false){
            finalVector.push_back({tempWord});
            }
            
        }
        return finalVector;
    }
};
