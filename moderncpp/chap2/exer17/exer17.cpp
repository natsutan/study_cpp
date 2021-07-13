//
// Created by natu on 2021/06/22.
//
//17 基本演算を備えた2次元配列を作る
//        要素へのアクセス（at()およびdata()）、 容量クエリ 、 イ テレータ、 フィ リ ング、 スワッ
//        プと いったメ ソッドを備えた 2次元配列コンテナを表すクラステンプレート を書き なさ
//い。 この型のオブジェクトをムーブできるよう にしなさい

#include <iostream>
#include <numeric>

int main(void)
{
    auto lcm_ret = std::lcm(80, 60);

    std::cout << lcm_ret << std::endl;

    return 0;
}
