class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequentMap;
        for(const auto& n: nums){
            frequentMap[n]++;
        }
        // Frequency Map of all vectors is now created
        vector<vector<int>> v(nums.size()+1);
        for(const auto& [key,value]: frequentMap){
            v[value].push_back(key);
        }
        // Goes through Map and inserts the values in their size position
        vector<int> finalVal;
        int count = 0;
        for(int i = nums.size(); i >= 0; --i){
            if(v[i].empty() == 0){ //if the iterated vector is not 0
                for(int j = 0; j < v[i].size(); ++j){
                    if(count == k){
                        return finalVal;
                    } else {
                        finalVal.push_back(v[i][j]);
                        ++count;
                    }

                }
            }
        }
        return finalVal;
    }
};
