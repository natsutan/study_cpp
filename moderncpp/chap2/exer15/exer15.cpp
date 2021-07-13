//
// Created by natu on 2021/06/22.
//
//IPv4データ型
//        IPv4アドレ ス を 表すク ラ ス を 書き なさ い。 IPv4アドレ ス を キ ー ボードから 入力
//       し、 ディ スプレイ に出力する のに必要な関数を書き なさ い。 ユーザは、 127.0.0.1や
//       168.192.0.100のよう にドット 形式で入力でき なければなり ま せん。 これは、 出力に使
//         う 形式でもあり ます。


#include <iostream>
#include <numeric>

int main(void)
{
    auto lcm_ret = std::lcm(80, 60);

    std::cout << lcm_ret << std::endl;

    return 0;
}
