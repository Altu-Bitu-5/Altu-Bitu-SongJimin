#include <iostream>
#include <string>
#include <vector>
using namespace std;

int moveTarget(string &target, string direction)
{
    vector<int> next(2, 0);
    if (direction.find('R') != string::npos)
    {
        next[0] = 1;
    }
    if (direction.find('L') != string::npos)
    {
        next[0] = -1;
    }
    if (direction.find('B') != string::npos)
    {
        next[1] = -1;
    }
    if (direction.find('T') != string::npos)
    {
        next[1] = 1;
    }

    if (char((int)target[0] + next[0]) >= 'A' && char((int)target[0] + next[0]) <= 'H' && char((int)target[1] + next[1]) >= '1' && char((int)target[1] + next[1]) <= '8')
    {
        target[0] = char((int)target[0] + next[0]);
        target[1] = char((int)target[1] + next[1]);
        return 1;
    }

    return 0;
}
int main()
{
    string king, stone, direction;
    int cnt;
    string prev;

    // 입력
    cin >> king >> stone >> cnt;

    for (int i = 0; i < cnt; i++)
    {
        cin >> direction;

        string prev = king;
        // 킹 이동 & 돌과 같은 위치가 되면 돌이동
        if (moveTarget(king, direction) && king.compare(stone) == 0)
        {
            if (!moveTarget(stone, direction))
            {
                // 돌이 범위 밖으로 이동된다면 킹 위치도 원래대로 돌리기.
                king = prev;
            }
        }
    }

    // 출력
    cout << king << '\n';
    cout << stone << "\n";
    return 0;
}