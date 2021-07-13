//
// Created by natu on 2021/06/22.
//
//16 範囲内のIPv4アドレスを列挙する
//        IPv4アドレスの範囲を表すために 2つの IPv4アドレスをユーザが入力し、 その範囲
//        内の全アドレスを列挙するプログラムを書きなさい。 問題15で定義したクラスを拡張し
//d        て、 要求された機能を実装しなさい。

#include <iostream>
#include <numeric>

int main(void)
{
    auto lcm_ret = std::lcm(80, 60);

    std::cout << lcm_ret << std::endl;

    return 0;
}
