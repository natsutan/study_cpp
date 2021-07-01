//
// Created by natu on 2021/06/22.
//
// 3桁のアームストロング数を出力する。
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>

std::vector<int> prime_factorization(int x);


int main(void)
{
    auto ret = prime_factorization(1000d);

    for(auto it = ret.begin();it!=ret.end();++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}


std::vector<int> prime_factorization(int x){
    std::vector<int> primes;

    int tmp = x;
    for(auto i=2;i<(x/2);++i) {
        while((tmp % i) == 0) {
            primes.push_back(i);
            tmp = tmp / i;
        }
    }

    if(tmp!=1) {
        primes.push_back(x);
    }

    return primes;
}

