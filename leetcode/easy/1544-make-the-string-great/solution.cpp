class Solution {
public:
    string makeGood(string s) {
        int i = 0;
        stack<char>stk;
        while(i<s.size()){
            char c = s[i];
            i++;
            if(stk.empty()){
                stk.push(c);
            }else{
                char t = stk.top();
                if(abs(c-t)==32){
                    stk.pop();
                }else{
                    stk.push(c);
                }
            }
        }
        string ans;
        while(!stk.empty()){
            ans = ans + stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};