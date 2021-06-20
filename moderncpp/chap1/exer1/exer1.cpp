// 与えられた上限までの3または5で割り切れる正の整数の総和を計算して出力するプ
//ログラムを書きなさい。
#include <iostream>

unsigned long long func(unsigned int max_v);

unsigned long long func(unsigned int max_v){

    unsigned long long sum = 0;
    for(auto i=1;i<max_v+1;i++) {
        if((i%3==0) || (i%5==0)) {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    auto result = func(10);

    std::cout << "result = " << result << std::endl;

    return 0;
}