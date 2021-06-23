//
// Created by natu on 2021/06/22.
//
//与えられた 2個以上の正の整数について、 その最小公倍数を計算して出力するプロ
//        グラムを書きなさい。
#include <iostream>
#include <set>
#include <vector>
#include <cmath>

int max_prime(int x);

int main(void)
{
    auto max_prime_ret = max_prime(100);
    std::cout << max_prime_ret << std::endl;

    return 0;
}

int max_prime(int x)
{
    int root_x = (int)ceil(sqrt(x));
    std::vector<int> primes;
    std::set<int> sieve;

    //initialize
    primes.push_back(1);
    for(int i=2;i<x+1;i++) {
        sieve.insert(i);
    }

    while(!sieve.empty()) {
        int prime = *sieve.begin();
        primes.push_back(prime);

        //delete
        for(auto i=sieve.begin(), last=sieve.end(); i != last;) {
            auto t = *i;
            if ((t%prime) == 0) {
                i = sieve.erase(i);
            }else {
                ++i;
            }
        }
    }

    return primes.back();
}
