class Solution {
public:
    double myFun(double x,long long n){
        if(n==0){
            return 1;
        }else{
            double temp = myFun(x,n/2);
            if(n%2==0){
                return temp*temp;
            }
            else{
                return x*temp*temp;
            }
        }
    }
    double myPow(double x, long long n) {
        if(n>=0){
            return myFun(x,n);
        }
        else{
            double temp = myFun(x,-1*n);
            return 1/temp;
        }
    }
};