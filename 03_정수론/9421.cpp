#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getPrimes(vector<bool> &primes)
{

    // 소수들
    for (int i = 2; i * i <= 1000001; i++)
    {
        if (primes[i] == true)
            for (int j = i * i; j <= 1000001; j += i)
            {
                primes[j] = false;
            }
    }
}

bool getSum(int num, vector<int> &sum_pool)
{

    int sum = 0;
    // 자릿수 합 구하기
    while (num)
    {
        sum += (num % 10) * (num % 10);
        num /= 10;
    }

    if (sum == 1)
    {
        sum_pool.clear();
        return true;
    }

    if (find(sum_pool.begin(), sum_pool.end(), sum) != sum_pool.end())
    {
        sum_pool.clear();
        return false;
    }
    else
    {
        sum_pool.push_back(sum);
        return getSum(sum, sum_pool);
    }
}
int main()
{

    int n;
    cin >> n;
    vector<bool> primes(1000002, true);

    getPrimes(primes);

    for (int i = 2; i <= n; i++)
    {
        if (primes[i] == true)
        {
            vector<int> sum_pool;
            if (getSum(i, sum_pool))
            {
                cout << i << "\n";
            }
        }
    }

    return 0;
}