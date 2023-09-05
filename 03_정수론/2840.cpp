#include <iostream>
#include <vector>

using namespace std;
// 칸 0번 ~ n-1번
// k번 돌리는데, 한번 돌릴때 s칸 이동 (원이니까 s = s % n). s칸 증가시킨 곳에 해당 알파벳 추가하기
// ? 가 아닌 칸에 기존 알파벳과 다른 알파벳 추가하려하면 ! 출력, 이미 있는 알파벳 넣으면 !.

int main()
{
    int n, k;
    cin >> n >> k;

    vector<char> arr(n, '?');

    int current_index = 0;
    while (k--)
    {
        int s;
        char alphabet;
        cin >> s >> alphabet;

        int index = (current_index + s) % n;

        if (arr[index] == '?')
        {
            arr[index] = alphabet;
        }
        else if (arr[index] != alphabet)
        {
            cout << "!";
            return 0;
        }
        current_index = index;
    }
    // 중복 저장된 알파벳 있으면 !
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] != '?' && arr[i] == arr[j])
            {
                cout << "!";
                return 0;
            }
        }
    }

    int temp = n;

    while (n--)
    {
        cout << arr[current_index];
        current_index = (current_index - 1 + temp) % temp;
    }

    return 0;
}