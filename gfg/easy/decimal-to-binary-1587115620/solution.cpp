class Solution {
  public:
    string decToBinary(int n) {
        // code here
        if(n==0){
            return "";
        }else{
            return decToBinary(n/2)+to_string(n%2);
        }
    }
};