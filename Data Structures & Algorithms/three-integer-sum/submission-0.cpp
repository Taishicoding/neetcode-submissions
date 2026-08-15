class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        if(nums.size() < 3){
            return {};
        }
        sort(nums.begin(),nums.end());
        /* Insertion Sort
        int j = 0;
        int key = 0;
        for(int i = 1; i < nums.size(); ++i){
            j = i - 1;
            key = nums[i];
            while(j >= 0 && nums[j] > key){
                nums[j+1] = nums[j];
                --j;
            }
            nums[j+1] = key;
        }
        */
        int target = 0;
        int sum = 0;
        for(int i = 0; i + 2 < nums.size(); ++i){
            int x = i + 1, y = nums.size()-1;
            target = nums[i];
            if(target > 0){
                return answer;
            }
            if(i > 0 && target == nums[i-1]){
                continue;
            }
            while(x < y){
                sum = nums[x] + nums[y] + target;
                if(sum == 0){
                    answer.insert(answer.end(),{target,nums[x],nums[y]});
                    while(x < y && nums[x] == nums[x+1]){++x;}
                    while(x < y && nums[y] == nums[y-1]){--y;}
                    ++x;
                    --y;
                }
                if(sum < 0){
                    ++x;
                } else if(sum > 0){
                    --y;
                }
            }

        }
        return answer;
    }
};
