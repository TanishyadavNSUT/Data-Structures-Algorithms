bool isValidParenthesis(string s)
{
    stack<char> x;
    
    for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(ch=='[' || ch=='{' || ch=='('){
            x.push(ch);
        }
        else{
            if(x.empty()){
                return false;
            }
            else{
                char a=x.top();
                if ((a == '{' &&ch == '}') || (a=='[' && ch==']') || (a=='(' && ch==')')) {
                    x.pop();
                }
                else{
                    return false;
                }
            }
            
        }
    }

    if(x.empty()){
        return true;
    }
    return false;
};