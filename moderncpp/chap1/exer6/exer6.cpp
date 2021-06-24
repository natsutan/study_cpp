//
// Created by natu on 2021/06/22.
//
//与えられた上弦までの過剰数
#include <iostream>
#include <set>
#include <vector>
#include <cmath>

std::vector<int> get_divisors(int x);
void print_abundant(int x);

int main(void)
{
    print_abundant(20);


    return 0;
}

void print_abundant(int x)
{
    auto divs = get_divisors(x);

    for(auto it=divs.begin();it!=divs.end();++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

std::vector<int> get_divisors(int x)
{
    std::vector<int> divisors;

    return divisors;
}
