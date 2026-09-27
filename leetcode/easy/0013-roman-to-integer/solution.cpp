class Solution {
public:
    int ToNumsF(char ch){
        if(ch=='I'){
            return 4;
        }
        if(ch=='X'){
            return 40;
        }
        if(ch=='C'){
            return 400;
        }
        return 0;
    }
    int ToNums(char ch){
        if(ch=='I'){
            return 9;
        }
        if(ch=='C'){
            return 900;
        }
        if(ch=='X'){
            return 90;
        }
        return 0;
    }
    int ToNum(char ch){
        if(ch=='I'){
            return 1;
        }
        if(ch=='V'){
            return 5;
        }
        if(ch=='X'){
            return 10;
        }
        if(ch=='L'){
            return 50;
        }
        if(ch=='C'){
            return 100;
        }
        if(ch=='D'){
            return 500;
        }
        if(ch=='M'){
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            if(ToNum(s[i])<ToNum(s[i+1])){
                if(ToNum(s[i+1])==5||ToNum(s[i+1])==50||ToNum(s[i+1])==500){
                    sum = sum + ToNumsF(s[i]);
                    i++;
                }
                else{
                    sum = sum + ToNums(s[i]);
                    i++;
                }
            }
            else{
                sum = sum + ToNum(s[i]);
            }
        }
        return sum;
    }
};