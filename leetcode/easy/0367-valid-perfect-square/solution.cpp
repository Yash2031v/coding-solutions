class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;
        while(low<=high){
            long long mid = (low+high)/2;
            if((1ll*mid*mid)==num){
                return true;
            }
            if((1ll*mid*mid)<num){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return false;
    }
};