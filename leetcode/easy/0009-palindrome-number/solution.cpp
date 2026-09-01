class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        }
        int temp = x;
        long long sum = 0;
        while(temp>0){
            sum = sum*10 + temp%10;
            temp = temp/10;   
        }
        if(x==sum){
            return true;
        }
        else{
            return false;
        }
    }
};