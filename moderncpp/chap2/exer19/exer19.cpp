//
// Created by natu on 2021/06/22.
//
//19 任意個数の要素をコンテナに追加
//push_back(T&& value)メ ソッドを備えたコンテナの末尾に任意個数の要素を追加で
//きる汎用の関数を書きなさい。

#include <iostream>
#include <numeric>
#include <vector>

template <typename T> void super_pb(std::vector<T> &v, T x);
template<typename T, typename ... Types> void super_pb(std::vector<T> &v, T x, Types... xs);

template <typename T> void super_pb(std::vector<T> &v, T x)
{
    v.push_back(x);
}

template<typename T, typename ... Types> void super_pb(std::vector<T> &v, T x, Types... xs)
{
    v.push_back(x);
    super_pb(v, xs...);
}

template<typename C, typename ... Types> void super_pb2(C &v, Types&&... xs);

template<typename C, typename ... Types> void super_pb2(C &v, Types&&... xs)
{
    (v.push_back(xs), ...);
}


int main(void)
{
    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    super_pb(v, 2);
    super_pb(v, 3, 4, 5);
    super_pb2(v, 6, 7, 8);

    for(auto it=v.begin();it!=v.end();++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}
