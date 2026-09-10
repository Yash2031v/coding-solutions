class Solution {
  public:
  int count =0;
  void Helper(int n,int s,int m,int d){
      
        
        if(n==1){
            count++;
            
            
        }
        else{
            towerOfHanoi(n-1,s,d,m);
            count++;
            towerOfHanoi(n-1,m,s,d);
        }
      
  }
    int towerOfHanoi(int n, int from, int to, int aux) {
        Helper(n,from,to,aux);
        return count;
    }
};