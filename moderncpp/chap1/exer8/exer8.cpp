//
// Created by natu on 2021/06/22.
//
// 3桁のアームストロング数を出力する。
#include <iostream>
#include <sstream>
#include <cmath>

void print_narcissistic();


int main(void)
{
    print_narcissistic();


    return 0;
}

void print_narcissistic(){
    std::ostringstream oss;
    for(int x=100;x<1000;x++) {
        int a = x % 10;
        int b = (x / 10) % 10;
        int c = (x / 100) % 10;

        for(int n=1;n<4;++n) {
            auto narc = std::pow(a, n) + std::pow(b, n) + std::pow(c, n);
            if(narc == x) {
                std::cout << "narcissistic:" << x << std::endl;
                break;
            }
        }
    }
}

