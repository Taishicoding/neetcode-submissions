class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> frequencyMap;
        bool overOne = false;
        for(const auto& n : nums){
            frequencyMap[n]++;
            if(frequencyMap[n] > 1){
                overOne = true;
                break;
            }
        }
        return overOne;
    }
};