// 与えられた 2個の正の整数の最大公約数を計算して出力するプログラムを書きなさい

#include <iostream>
#include <numeric>

int main(void)
{
    auto gcd_ret = std::gcd(80, 60);

    std::cout << gcd_ret << std::endl;

    return 0;
}
