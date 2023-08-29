#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
int main()
{
    int n, m, count = 0;
    cin >> n >> m;
    set<string> s;

    while (n--)
    {
        string str;
        cin >> str;
        s.insert(str);
    }

    while (m--)
    {
        string str;
        cin >> str;
        if (s.find(str) != s.end())
        {
            count++;
        }
    }

    cout << count;
    return 0;
}