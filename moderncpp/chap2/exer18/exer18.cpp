//
// Created by natu on 2021/06/22.
//
//18 任意個数の引数を取る最小値関数
//        任意個数の引数を取ること ができ て、 その最小値を返す関数テンプレート を、 比較
//        に operator<演算子を使って書き なさい。 operator<の代わり に、 引数として与えられ
//        た 2項比較関数を使う 、 この関数テンプレートの修正版も 書きなさい。

#include <iostream>
#include <numeric>

int main(void)
{
    auto lcm_ret = std::lcm(80, 60);

    std::cout << lcm_ret << std::endl;

    return 0;
}
