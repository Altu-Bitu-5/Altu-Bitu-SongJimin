#include <iostream>
#include <cmath>
using namespace std;
int updateSet(int &set, string op, int target)
{
    if (op == "add")
    {
        set |= 1 << (target - 1);
    }
    else if (op == "remove")
    {
        set &= ~(1 << (target - 1));
    }
    else if (op == "check")
    {
        if (set & (1 << (target - 1)))
        {
            return 1;
        }
        return 0;
    }
    else if (op == "toggle")
    {
        set ^= (1 << (target - 1));
    }
    else if (op == "all")
    {
        set = (1 << 20) - 1;
    }
    else if (op == "empty")
    {
        set = 0;
    }

    return 2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int set = 0;
    int cnt, target;
    string op;

    cin >> cnt;
    while (cnt--)
    {
        cin >> op;
        // 질문: 입력과 출력을 updateSet 함수안에서 하면 더 간단하게 표현 가능할것 같은데, 코드가 좀 길어지더라도 메인안에서 하는게 나은가요?
        if (op != "empty" && op != "all")
        {
            cin >> target;
        }
        int check = updateSet(set, op, target);
        if (check != 2)
        {
            cout << check << "\n";
        };
    }
    return 0;
}