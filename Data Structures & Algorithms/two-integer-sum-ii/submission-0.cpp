class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int a = 0, b = numbers.size()-1;
        int tempSum = 0;
        while(a < b){
            tempSum = numbers[a] + numbers[b];
            if(tempSum == target){
                return {a + 1,b + 1};
            } else if(tempSum < target){
                ++a;
            } else if(tempSum > target){
                --b;
            }
        }
        return {};
    }
};
