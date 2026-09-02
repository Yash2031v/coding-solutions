class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(x==0){
            return 0;
        }
        if(n<0){
            
            return 1/x * myPow(x,n+1);
        }
        else{
            return x*myPow(x,n-1);
        }
    }
};