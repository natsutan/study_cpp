//
// Created by natu on 2021/06/22.
//
//与えられた上弦までのセクシー素数を求める。
#include <iostream>
#include <set>
#include <vector>
#include <cmath>

std::set<int> get_primes(int x);
int print_sexy_primes(int x);

int main(void)
{
    print_sexy_primes(3000);


    return 0;
}

int print_sexy_primes(int x)
{
    auto primes = get_primes(x);
    for(int i=2;i<x+1;++i) {
        if(primes.find(i)!=primes.end()) {
            if(primes.find(i+6)!=primes.end()) {
                //find
                std::cout << i << " " << i+6 << std::endl;
            }
        }
    }

    return 0;
}



std::set<int> get_primes(int x)
{
    int root_x = (int)ceil(sqrt(x));
    std::set<int> primes;
    std::set<int> sieve;

    //initialize
    primes.insert(1);
    for(int i=2;i<x+1;i++) {
        sieve.insert(i);
    }

    while(!sieve.empty()) {
        int prime = *sieve.begin();
        primes.insert(prime);

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

    return primes;
}
