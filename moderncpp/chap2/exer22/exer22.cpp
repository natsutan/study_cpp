//
// Created by natu on 2021/06/22.
//
//22 さまざまな温度単位のリテラル
//        温度をよく 使われる 3つの単位、 摂氏、 華氏、 ケルビンで表示できて、 相互に単位変
//        換ができる小さなライ ブラリ を書きなさい。 このライ ブラリ では、 温度リ テラルを摂氏
//は 36.5_deg、 華氏は 97.7_f、 ケルビンは 309.65_Kと書き 、 これらの値で演算が行えて、
//相互に変換できるよう にしなさい。

#include <iostream>
#include <numeric>

int main(void)
{
    auto lcm_ret = std::lcm(80, 60);

    std::cout << lcm_ret << std::endl;

    return 0;
}
