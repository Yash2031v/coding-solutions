class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(int x:prices){
            if(x<min1){
                min2=min1;
                min1=x;
            }
            else if(x<min2){
                min2=x;
            } 
        }
        int cost = min1+min2;
        if(cost<=money){
            return money-cost;
        }
        else{
            return money;
        }
    }
};