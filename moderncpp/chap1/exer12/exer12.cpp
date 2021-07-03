
//12 最長コラッツ数列
//100万までの数で、 最長コラッツ数列になる数とその数列の長さを求めるプログラムを書きなさい。
#include <iostream>
#include <vector>

struct roman_pair {
        int v;
        std::string s;
};



void print_roma(int x);
std::vector<roman_pair> create_roman_table();


int main(void)
{
    for(int i=0;i<110;++i) {
        print_roma(i);
    }


    return 0;
}

void print_roma(int x)
{
    auto roman_table = create_roman_table();
    std::string s="";
    auto roman_num = x;

    for(auto it = roman_table.begin();it!=roman_table.end();++it) {
        auto v = it->v;
        int div = roman_num / v;
        if (div > 0) {
            for(int j=0;j<div;j++) {
                s = s + it->s;
            }
            roman_num -= v * div;
        }
    }

    std::cout << s << std::endl;
}

std::vector<roman_pair> create_roman_table()
{
    std::vector<roman_pair> table;
    table.push_back({1000, "M"});
    table.push_back({900, "CM"});
    table.push_back({500, "D"});
    table.push_back({400, "CD"});
    table.push_back({100, "C"});
    table.push_back({90, "XC"});
    table.push_back({50, "L"});
    table.push_back({40, "XL"});
    table.push_back({10, "X"});
    table.push_back({9, "IX"});
    table.push_back({5, "V"});
    table.push_back({4, "IV"});
    table.push_back({1, "I"});

    return table;
}

