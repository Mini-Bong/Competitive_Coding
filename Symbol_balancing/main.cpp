// this program is checking the whether the parenthesis is balanced or not,
// We are using the stack when a opening brackets is encountered and push into the stack
// when ever a closing parenthesis is encountered we are comparing the top symbol of the stack to it.


#include <bits/stdc++.h>

using namespace std;

bool isBalanced(string str)
{
    stack<char> s;
    char x;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
            {
               s.push(str[i]);
               continue;
            }
        if(s.empty())
        {
            return false;
        }
        switch(str[i])
        {
        case ')':
            x=s.top();
            s.pop();
            if(x=='{' || x=='[')
                return false;
            break;
        case '}':
            x=s.top();
            s.pop();
            if(x=='[' || x == '(')
                return false;
            break;
        case ']':
            x=s.top();
            s.pop();
            if(x=='{' || x == '(')
                return false;
            break;
        }
    }
    return (s.empty());
}

int main()
{
    string str;
    cout <<"Enter any pattern containing only brackets:";
    cin>>str;
    if(isBalanced(str))
    {
        cout<<"Balanced";
    }
    else
    {
        cout<<"Expression is not balanced";
    }
}
