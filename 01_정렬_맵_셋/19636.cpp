#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/* 어려웠던 점
1.
  if (abs(i - (i_n + a)) > t)
        {

            i_n = i_n + floor((i - (i_n + a)) / 2.0);

        }
        여기에서 2.0 이 아닌 2로 나눗셈을 해서 테스트 케이스는 모두 통과했으나 채점시 틀림.
        => division operator(/)는 분모의 자료형을 따라가기 때문.

2. 변수 네이밍 하는게 어렵습니다.


*/
// D일
// 체중W0, 에너지 섭취 I, 활동 대사량 A, 기초대사량 I0
// 에너지 소비량 = I_n(기초대사) + A
// 체중 Wn + I(에너지섭취량 불변) - (I_n(기초대사량) + A(활동대사량 불변))

int main()
{
    int w_0, i_0, t;
    cin >> w_0 >> i_0 >> t;

    int d, i, a;
    cin >> d >> i >> a;

    // 기초대사 변화 고려 X 예상체중, 일일 기초대사량 (사망이 예상되는 경우 체중과 일일 기초 대사량 대신 Danger Diet를 출력한다.)
    int w_first = w_0;
    for (int day = 0; day < d; day++)
    {
        w_first = w_first + i - (i_0 + a);
    }
    // 사망하는 경우
    if (w_first <= 0 || i_0 <= 0)
    {
        cout << "Danger Diet"
             << "\n";
    }
    else
    {
        cout << w_first << " " << i_0 << "\n";
    }

    // 기초대사 변화 고려 O 예상체중, 일일 기초대사량
    int w_second = w_0;
    int i_n = i_0; // 기초대사량
    for (int day = 0; day < d; day++)
    {
        w_second = w_second + i - (i_n + a);
        // 기초대사량 변화하는 경우
        if (abs(i - (i_n + a)) > t)
        {

            i_n = i_n + floor((i - (i_n + a)) / 2.0);
        }
    }

    // 사망하는 경우
    if (w_second <= 0 || i_n <= 0)
    {
        cout << "Danger Diet"
             << "\n";
    }
    else
    {
        string is_yoyo = "NO";
        // 이전으로 돌아갔을때 체중이 증가하는 경우 = i0 - (i_n + a_0)가 양수인 경우 , a_0 =0
        if (i_0 - i_n > 0)
        {
            is_yoyo = "YOYO";
        }
        cout << w_second << " " << i_n << " " << is_yoyo;
    }

    return 0;
}