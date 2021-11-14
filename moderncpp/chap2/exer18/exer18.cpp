//
// Created by natu on 2021/06/22.
//
//18 任意個数の引数を取る最小値関数
//        任意個数の引数を取ること ができ て、 その最小値を返す関数テンプレート を、 比較
//        に operator<演算子を使って書き なさい。 operator<の代わり に、 引数として与えられ
//        た 2項比較関数を使う 、 この関数テンプレートの修正版も 書きなさい。

#include <iostream>
#include <numeric>

template <typename T> auto min_t(T x);
template<typename T, typename ... Types> auto min_t(T x, Types... xs);

template <typename T> auto min_t(T x)
{
    return x;
}

template<typename T, typename ... Types>
auto min_t(T x, Types... xs) {
    T tmp = min_t(xs...);
    return (x < tmp) ? x : tmp;
}


int main(void)
{
    std::cout << min_t(3.0, 5.0, 2.0 , 6.0) << std::endl;
    std::cout << min_t('c', 'a', 'd') << std::endl;

    return 0;
}
