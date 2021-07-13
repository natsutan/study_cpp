//
// Created by natu on 2021/06/22.
//
//19 任意個数の要素をコンテナに追加
//push_back(T&& value)メ ソッドを備えたコンテナの末尾に任意個数の要素を追加で
//きる汎用の関数を書きなさい。

#include <iostream>
#include <numeric>

int main(void)
{
    auto lcm_ret = std::lcm(80, 60);

    std::cout << lcm_ret << std::endl;

    return 0;
}
