class Solution {
  public:
    int good(int n,int i){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        return good(n-i,i+1);
    }
    int isTriangular(int n) {
        // code here
        int i=1;
        return good(n,i);
    }
};