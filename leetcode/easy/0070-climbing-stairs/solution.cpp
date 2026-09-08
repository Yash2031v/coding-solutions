class Solution {
public:
     int helper(int n,vector<int>&dat){
        if(n==-1){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(dat[n]==0){
            dat[n]= helper(n-1,dat) + helper(n-2,dat);
        }
        return dat[n];
     }
    int climbStairs(int n) {
        vector<int>dat(n+1);
        return helper(n,dat);

    }
};