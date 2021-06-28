//
// Created by natu on 2021/06/22.
//
// 1000000より小さい全ての友愛数のペアを表示する。
#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> get_divisors(int x);
void print_abundant(int x);

int main(void)
{
    print_abundant(22);


    return 0;
}

void print_abundant(int x)
{
    for(int i=x;i>0;--i) {
        auto divs = get_divisors(i);
        int sum = std::accumulate(divs.begin(), divs.end(), 0);

        if (sum > (i * 2)) {
            std::cout << i;
            break;
        }
    }

    std::cout << std::endl;
}

std::vector<int> get_divisors(int x)
{
    std::vector<int> divisors;

    for(int i=1;i<x+1;i++) {
        if ((x % i) == 0) {
            divisors.push_back(i);
        }
    }

    return divisors;
}
