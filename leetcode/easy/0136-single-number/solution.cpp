class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sing = 0;
        for(int i=0;i<nums.size();i++){
            sing = sing^nums[i];
        }
        return sing;
    }
};