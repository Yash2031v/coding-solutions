class Solution {
public:
    bool check(char a, char b){
        if(a=='(' && b==')'){
            return true; 
        }
        if(a=='{' && b=='}'){
            return true; 
        }
        if(a=='[' && b==']'){
            return true; 
        }
        return false;
    }
    bool isValid(string s) {
        stack<char>item;
        int n = 0;
        if(s.size()%2!=0){
            return false;
        }
        while(n<s.size()){
            if(s[n]=='(' || s[n]=='[' || s[n]=='{'){
                item.push(s[n]);
            }
            
            else{
                if(check(item.top(),s[n])){
                    item.pop();
                }
                else{
                    return false;
                }
            
            }
            n++;
            
        }
        return true;
    }

};