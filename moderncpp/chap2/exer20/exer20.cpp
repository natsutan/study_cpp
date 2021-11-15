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
#include <vector>
#include <list>
#include <algorithm>
#include <assert.h>


template <typename C, typename T> bool contains_any(C &c, T x);
template <typename C, typename T, typename ... Types> bool contains_any(C &c, T x, Types... xs);
template <typename C, typename T> bool contains_all(C &c, T x);
template <typename C, typename T, typename ... Types> bool contains_all(C &c, T x, Types... xs);
template <typename C, typename T> bool contains_none(C &c, T x);
template <typename C, typename T, typename ... Types> bool contains_none(C &c, T x, Types... xs);


template <typename C, typename T>
bool contains_any(C &c, T x) {
    return std::any_of(c.begin(), c.end(), [&x](T y) { return x == y; });
}

template <typename C, typename T, typename ... Types> bool contains_any(C &c, T x, Types... xs)
{
    if(std::any_of(c.begin(), c.end(), [&x](T y) { return x == y; })) {
        return true;
    }  else {
        return contains_any(c, xs...);
    }
}

template <typename C, typename T>
bool contains_all(C &c, T x) {
    return std::any_of(c.begin(), c.end(), [&x](T y) { return x == y; });
}

template <typename C, typename T, typename ... Types> bool contains_all(C &c, T x, Types... xs)
{
    if(std::any_of(c.begin(), c.end(), [&x](T y) { return x == y; })) {
        return contains_all(c, xs...);
    }  else {
        return false;
    }
}

template <typename C, typename T>
bool contains_none(C &c, T x) {
    return !std::any_of(c.begin(), c.end(), [&x](T y) { return x == y; });
}

template <typename C, typename T, typename ... Types> bool contains_none(C &c, T x, Types... xs)
{
    return !contains_any(c, xs...);
}


int main(void)
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6 };

    assert(std::any_of(v.begin(), v.end(), [](int x) { return x == 3;}));
    assert(contains_any(v, 1));
    assert(contains_any(v, 0, 3, 30));
    std::array<int, 6> a{ { 1, 2, 3, 4, 5, 6 } };
    assert(contains_all(a, 1, 3, 5, 6));
    std::list<int> l{ 1, 2, 3, 4, 5, 6 };
    assert(contains_none(l, 0, 7));

    return 0;
}
