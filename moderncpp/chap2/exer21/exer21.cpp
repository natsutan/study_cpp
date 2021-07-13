//
// Created by natu on 2021/06/22.
//
//21 システムハンドルラッパー
//        ファ イ ルハンドルのよう な OSのハンドルを考えま す。 ハンドルの取得と 解放、 ハン
//        ドルの正当性検証、 あるオブジェクト から別のオブジェクト へのハンドルの所有権の移
//        動などの演算を行う ラッ パーを書きなさい。

#include <iostream>
#include <numeric>

int main(void)
{
    auto lcm_ret = std::lcm(80, 60);

    std::cout << lcm_ret << std::endl;

    return 0;
}
