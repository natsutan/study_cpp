
// 2進表記で5ビット のすべての数について、 2進表現、 グレイコード表現、 グレイコード復号値を出力するプログラムを書きなさい。
#include <iostream>
#include <bitset>

void print_graycode(int x);


int main(void)
{
    for(int i=0;i<31;++i) {
        print_graycode(i);
    }


    return 0;
}

void print_graycode(int x)
{
    int tmp = (x << 1) & 0x1F;
    tmp = tmp ^ x;

    std::cout << std::bitset<5>(tmp) << std::endl;

}

