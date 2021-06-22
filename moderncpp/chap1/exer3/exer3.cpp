//
// Created by natu on 2021/06/22.
//
//与えられた 2個以上の正の整数について、 その最小公倍数を計算して出力するプロ
//        グラムを書きなさい。
#include <iostream>
#include <numeric>

int main(void)
{
    auto lcm_ret = std::lcm(80, 60);

    std::cout << lcm_ret << std::endl;

    return 0;
}
