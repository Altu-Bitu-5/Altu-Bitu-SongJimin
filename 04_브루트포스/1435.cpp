// n <= 10,000 가장큰숫자 10,000,666 보다는 작을것임 -> int
#include <iostream>

using namespace std;
int getResult(int n)
{
    int num = 665;

    while (n)
    {
        string str_num = to_string(++num);
        if (str_num.find("666") != string::npos)
        {
            n--;
        }
    }
    return num;
}
int main()
{
    int n;
    cin >> n;

    cout << getResult(n);

    return 0;
}