//
// Created by natu on 2021/06/22.
//
//20 コンテナのany, all, none関数
//        与えられた引数がコンテナの要素のどれか（any）、 すべて（all）、 あるいはどれでも
//        ない（none） かをチェックする汎用の関数を書きなさい。 次のよう なコードが書けるよう
//にしなさい＊ 1。
//std::vector<int> v{ 1, 2, 3, 4, 5, 6 };
//assert(contains_any(v, 0, 3, 30));
//std::array<int, 6> a{ { 1, 2, 3, 4, 5, 6 } };
//assert(contains_all(a, 1, 3, 5, 6));
//std::list<int> l{ 1, 2, 3, 4, 5, 6 };
//assert(!contains_none(l, 0, 6));


#include <iostream>
#include <numeric>

int main(void)
{
    auto lcm_ret = std::lcm(80, 60);

    std::cout << lcm_ret << std::endl;

    return 0;
}
