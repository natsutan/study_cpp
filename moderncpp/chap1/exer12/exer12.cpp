
//12 最長コラッツ数列
//100万までの数で、 最長コラッツ数列になる数とその数列の長さを求めるプログラムを書きなさい。
#include <iostream>
#include <unordered_map>


long collatz_length (long x);
long collatz(long x, int len);
std::unordered_map<long, int> memo;

int main(void)
{
    memo.clear();

    int max_x = 0;
    int max_len = 0;

    for(long i=1;i<1000000;++i) {
        auto len = collatz_length(i);
        if (len > max_len) {
            max_x = i;
            max_len = len;
        }
    }

    std::cout << max_x << ":" << max_len << std::endl;

    return 0;
}

long collatz_length (long x)
{
    auto len = collatz(x, 0);
    memo[x] = len;
    return len;
}

long collatz(long x, int len)
{
    auto cashed = memo[x];
    if(cashed != 0) {
        return len + cashed;
    }

    if(x == 1) {
        return len + 1;
    } else {
        if((x%2) == 0) {
            return collatz(x/2, len+1);
        } else {
            return collatz(3*x+1, len +1);
        }
    }
}
