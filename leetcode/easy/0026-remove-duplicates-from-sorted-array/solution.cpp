class Solution {
public:
    
    int removeDuplicates(vector<int>& nums) {\
        int cur = 0;
        int count = 1;
        int next = 1;
        while(next<=nums.size()-1){
            if(nums[cur]==nums[next]){
                next++;
            }
            else{
                cur++;
                swap(nums[cur],nums[next]);
                count++;
                next++;
            }
            
        }
        return count;
        
    }
};