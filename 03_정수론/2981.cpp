// a를 m으로 나누었을때 나머지가 모두 같아야함.
// a_1 = m * 0 + r -> m의 배수= (a_1 - r )
// a_2 = m * 2 + r ...
// -> m의 배수 = ( a_n - r ):  a_n-r들의 최대공약수는 gcd, gcd의 약수들이 가능한 m.
// 나올수 있는 나머지는 가장 작은 수 보다 1작은 수. -> r의 범위 0 ~ r

// 위의 방법 시간포과 다른 방법. 뺄셈으로 r 변수를 줄임.
//  a_2 - a_1 = m의 배수
//  차들의 최대 공약수 gcd의 약수들이 m.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int getGcd(int big, int small)
{
    while (small)
    {
        big %= small;
        swap(big, small);
    }
    return big;
}

void printFactors(int num)
{
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << num;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr;
    while (n--)
    {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    // 아래 코드는 시간초과
    /*
        int max_r = arr[0];
        vector<int> gcd_arr;

        for (int r = 0; r <= max_r; r++)
        {

            int temp_gcd = getGcd(arr[1] - r, arr[0] - r);

            for (int i = 2; i < arr.size(); i++)
            {
                temp_gcd = getGcd(max(temp_gcd, arr[i] - r), min(temp_gcd, arr[i] - r));
            }
            if (temp_gcd != 1 && find(gcd_arr.begin(), gcd_arr.end(), temp_gcd) == gcd_arr.end())
            {
                gcd_arr.push_back(temp_gcd);
            }
        }

        // 출력
        for (int i = 0; i < gcd_arr.size() - 1; i++)
        {
            cout << gcd_arr[i] << " ";
        }
        cout << gcd_arr[gcd_arr.size() - 1];
    */

    // 수정
    vector<int> gcd_arr;
    int temp_gcd = arr[1] - arr[0];
    for (int i = 2; i < arr.size(); i++)
    {
        temp_gcd = getGcd(max(temp_gcd, arr[i] - arr[i - 1]), min(temp_gcd, arr[i] - arr[i - 1]));
    }
    if (temp_gcd != 1)
    {
        // 출력
        printFactors(temp_gcd);
    }

    return 0;
}
