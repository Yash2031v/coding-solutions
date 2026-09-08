class Solution {
public:
     int helper(int n,vector<int>&dat,int cur){
        if(cur==n+1){
            return 0;
        }
        if(cur==n){
            return 1;
        }
        if(dat[cur]==0){
            dat[cur]= helper(n,dat,cur+1) + helper(n,dat,cur+2);
        }
        return dat[cur];
     }
    int climbStairs(int n) {
        int cur = 0;
        vector<int>dat(n+1);
        return helper(n,dat,cur);

    }
};