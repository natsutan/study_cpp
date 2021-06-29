//
// Created by natu on 2021/06/22.
//
// 1000000より小さい全ての友愛数のペアを表示する。
#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

std::vector<int> get_divisors(int x);
int sum_of_divisors(int x);
void print_amicable(int x);

std::unordered_map<int, int> memo;

int main(void)
{
    memo.clear();
    print_amicable(1000000);


    return 0;
}

void print_amicable(int x)
{
    for(int i=0;i<x;++i) {
        int sum0 = sum_of_divisors(i);
        int sum1 = sum_of_divisors(sum0);
        //std::cout << i << "," << sum0 << "," << sum1 << std::endl;

        if((i == sum1) && (i != sum0) && (sum0 > sum1)) {
            std::cout << "amicable! " << i << "," << sum0 << std::endl;
        }
    }

    std::cout << std::endl;
}

int sum_of_divisors(int x)
{
    if (memo[x] != 0) {
        return memo[x];
    }
    auto divisors = get_divisors(x);
    int sum = std::accumulate(divisors.begin(), divisors.end(), 0);

    memo[x] = sum;

    return sum;
}


std::vector<int> get_divisors(int x)
{
    std::vector<int> divisors;

    for(int i=1;i<x;i++) {
        if ((x % i) == 0) {
            divisors.push_back(i);
        }
    }

    return divisors;
}
