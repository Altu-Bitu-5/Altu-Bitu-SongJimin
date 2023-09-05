#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
// 합을 이루는 두 소수 출력. a+b 형태. b-a가 가장 큰 경우 출력.
// n보다 작은 모든 소수를 찾아서 조합이 가능한 경우를 찾기

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr(1000000, 0);

    // n보다 작은 수들의 소수여부 저장 배열
    for (int i = 2; i * i < 1000000; i++)
    {
        if (arr[i] == 0)
            for (int j = i * i; j < 1000000; j += i)
            {
                arr[j] = 1;
            }
    }
    while (1)
    {
        int n;
        cin >> n;
        int a;
        if (n == 0)
        {
            return 0;
        }

        bool is_wrong = false;
        // 홀수만 생각하니까 3부터 2씩 증가
        for (int a = 3; a <= n; a += 2)
        {
            if (arr[a] == 0 && arr[n - a] == 0)
            {
                cout << n << " = " << a << " + " << n - a << "\n";
                is_wrong = false;
                break;
            }
        }
        if (is_wrong)
        {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}