#include <iostream>
using namespace std;

// 분수의 합 : 분모 = 분모끼리의 곱, 분자 = 상대분모를 곱한값을 더하기.
// 통분시에 분모를 두 분모의 최소공배수로 하지 않고 그냥 둘을 곱한 배수로 함. 어차피 기약분수로 바꾸는 과정을 거치기때문에 불필요하다고 생각함.
// 기약분수 표현: 계산된 분모와 분자의 최대공약수를 구해 각각을 나누어 표현

void getSum(int a_1, int b_1, int a_2, int b_2, int &a, int &b)
{

    // 분모
    b = b_1 * b_2;
    // 분자
    a = a_1 * b_2 + a_2 * b_1;
}
void getPrime(int &a, int &b)
{
    // 분모와 분자의 최대공약수 구하기: a>b, gcd(a,b)=gcd(a%b,b), swap,b=0일때 종료
    int big = max(a, b);
    int small = min(a, b);
    while (small)
    {
        big %= small;
        swap(big, small);
    }
    int gcd = big;

    a /= gcd;
    b /= gcd;
}
void getResult(int a_1, int b_1, int a_2, int b_2)
{
    int a, b;
    getSum(a_1, b_1, a_2, b_2, a, b);
    getPrime(a, b);

    cout << a << " " << b;
}
int main()
{
    int a_1 = 0, b_1 = 0, a_2 = 0, b_2 = 0;
    cin >> a_1 >> b_1;
    cin >> a_2 >> b_2;

    getResult(a_1, b_1, a_2, b_2);

    return 0;
}
