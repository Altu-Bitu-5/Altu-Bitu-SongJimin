#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int numSum(string str)
{
    int sum = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str.at(i)))
        {
            sum += str.at(i) - '0';
        }
    }

    return sum;
}

bool cmp(const string &a, const string &b)
{
    if (a.length() != b.length())
        return a.length() < b.length();
    if (numSum(a) != numSum(b))
        return numSum(a) < numSum(b);

    for (int i = 0; i < a.length(); i++)
    {
        if (a.at(i) != b.at(i))
        {
            return a.at(i) < b.at(i);
        }
    }

    return true;
}

int main()
{
    // 1. 길이 짧은순
    // 2. 숫자 더해서 작은순
    // 3. 사전순

    // 기타 개수
    int num;
    cin >> num;

    vector<string> arr(0);
    while (num--)
    {
        string str;
        cin >> str;
        arr.push_back(str);
    }

    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}