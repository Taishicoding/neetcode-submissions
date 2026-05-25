class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int count = 0;
        vector<int> sum;
        int targetVal;
        int targetInt;
        unordered_map<int, int> findTarget;
        for(const auto& v : nums){
                targetVal = target - v;
                if(findTarget.find(targetVal) != findTarget.end()){
                    targetInt = findTarget[targetVal];
                    if(count > targetInt){
                        sum = {targetInt, count};
                        return sum;
                    } else {
                        sum = {count, targetInt};
                        return sum;
                    }
                }
                findTarget[v] = count;
                ++count; 
    }
    return sum;
    }
};
