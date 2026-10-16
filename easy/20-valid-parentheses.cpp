class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> chars;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                chars.push(s[i]);
            else if(!chars.empty() && 
            (s[i] == ')' && chars.top() == '(' ||
             s[i] == '}' && chars.top() == '{' ||
             s[i] == ']' && chars.top() == '['))
                chars.pop();
            else
                return false;
        }
        
        return chars.empty();
    }
};