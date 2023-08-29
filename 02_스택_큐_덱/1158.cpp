#include <iostream>
#include <queue>
using namespace std;

// 앞에서부터 k-1은 맨 뒤로 보내고 그 k번째는 pop을 반복.
// 질문: 출력을 더 편리하게 하는 방법은 없을까요?
// ex. 마지막 원소인지 검사하여 ", "를 안붙이도록했는데 이과정을 줄이는 방법..등
int main()
{
    int N, K;
    queue<int> arr;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        arr.push(i);
    }

    cout << "<";
    while (!arr.empty())
    {
        for (int i = 0; i < K - 1; i++)
        {
            int temp = arr.front();
            arr.pop();
            arr.push(temp);
        }
        if (arr.size() == 1)
        {
            cout << arr.front();
            arr.pop();
        }
        else
        {
            cout << arr.front() << ", ";
            arr.pop();
        }
    }

    cout << ">";
    return 0;
}