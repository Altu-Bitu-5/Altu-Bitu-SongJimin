#include <iostream>
#include <string>
#include <stack>
using namespace std;
// 여는 괄호 나오면 스택에 푸시. 닫는 괄호 나오고 스택 맨 위의 여는 괄호가 같은 모양이면 팝.
bool isBalanced(string str)
{
    stack<char> arr;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[')
        {
            arr.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (arr.empty() || arr.top() != '(')
            {
                return false;
            }
            arr.pop();
        }
        else if (str[i] == ']')
        {
            if (arr.empty() || arr.top() != '[')
            {
                return false;
            }
            arr.pop();
        }
    }

    return arr.empty();
}
int main()
{
    string str;
    while (1)
    {
        getline(cin, str);
        if (str == ".")
        {
            break;
        }

        if (isBalanced(str))
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }

    return 0;
}