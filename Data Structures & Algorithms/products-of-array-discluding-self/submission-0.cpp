
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftVector;
        vector<int> rightVector;
        int runningVal = 1;
        for(const auto& n : nums){
            leftVector.push_back(n * runningVal);
            runningVal *= n;
        }
        for(const auto& a : leftVector){
            cout<<a<<endl;
        }
        // Make the first left to right vector 
        runningVal = 1;
        for(auto it = nums.rbegin(); it != nums.rend(); ++it){
            rightVector.push_back(*it * runningVal);
            runningVal *= *it;
        }
        cout<<endl;
        int i = 0;
        cout<<"Size: "<<rightVector.size()<<endl;
        cout<<"Size: "<<rightVector.size() - 2 - 1<<endl;
        for(const auto& a : rightVector){
            cout<<i<<": "<<a<<endl;
            ++i;
        }
        vector<int> finalVector;
        finalVector.push_back(rightVector[rightVector.size()-2]); // Push the inital value which is right vector second to last val
        for(size_t i = 1; i <= leftVector.size()-2; ++i){
            int sum;
            
            sum = leftVector[i-1] * rightVector[rightVector.size()-2-i]; // Find the product from both sides
            finalVector.push_back(sum);
        }
        finalVector.push_back(leftVector[leftVector.size()-2]); //Push the final value which is the left vector second to last val
        return finalVector;

    }
};
