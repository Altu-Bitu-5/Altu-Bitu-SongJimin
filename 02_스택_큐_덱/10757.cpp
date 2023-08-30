#include <iostream>
#include <string>
#include <deque>
#include <string.h>
using namespace std;

void sum(string A, string B)
{

    deque<int> arr;
    string sum;

    // 둘중 자릿수가 더 적은 숫자의 자릿수 저장
    int length = A.length();
    string longer = B;

    if (length > B.length())
    {
        length = B.length();
        longer = A;
    }

    int up = 0;
    for (int i = 0; i < length; i++)
    {

        int temp = (A[A.length() - 1 - i] - '0') + (B[B.length() - 1 - i] - '0') + up;
        arr.push_front(temp % 10);
        if (temp >= 10)
        {
            up = 1;
        }
        else
        {
            up = 0;
        }
    }

    // A와 B 중 자릿수가 더 긴 숫자의 남은 수들을 스택에 넣어줌.
    for (int i = 0; i < longer.length() - length; i++)
    {
        int temp = ((longer[longer.length() - length - 1 - i] - '0') + up);
        arr.push_front(temp % 10);
        if (temp >= 10)
        {
            up = 1;
        }
        else
        {
            up = 0;
        }
    }
    // 마지막 합이 10이상이라 자릿수가 달라지는 경우.
    if (up)
    {
        arr.push_front(1);
    }
    // 출력
    while (!arr.empty())
    {
        cout << arr.front();
        arr.pop_front();
    }
}
int main()
{
    string A, B;
    cin >> A >> B;

    sum(A, B);

    return 0;
}