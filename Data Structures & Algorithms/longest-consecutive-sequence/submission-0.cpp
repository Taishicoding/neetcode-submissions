
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_map<int,int> numbers;
        for(const auto& n : nums){
            numbers[n] = 0;
        }
        int maxLength = 1;
        int temp;
        int tempVal;
        for(const auto& n : nums){
            temp = 1;
            tempVal = n;
            if(numbers.find(tempVal-1) == numbers.end()){  
                ++tempVal;
                while(numbers.find(tempVal) != numbers.end()){
                    ++temp;
                    ++tempVal;
                }
                if(temp > maxLength){
                    maxLength = temp;
                }
            }

        }
        return maxLength;
    }
};
