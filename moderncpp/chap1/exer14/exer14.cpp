
//14 ISBNの検証
//文字列として与えられた 10桁の値が、 10桁の ISBN-10番号として正しいかどうか検証するプログラムを書
#include <iostream>

bool is_valid_isbn10(const std::string s);


int main(void)
{
    std::string num0 = "4101092052";
    std::string num1 = "316148410X";


    auto ret = is_valid_isbn10(num1);
    auto ret_s = ret ? "valid" : "invalid";


    std::cout << num1 << ":" << ret_s << std::endl;

    return 0;
}

bool is_valid_isbn10(const std::string s)
{
    if(s.size()!=10) {
        return false;
    }

    auto digit = 0;
    auto weight = 10;
    for(auto i=0;i<9;i++) {
        auto c = s[i];

        if((c < '0') && ('9' < c)) {
            return false;
        }
        int n = int(c - '0');

        digit += n * weight;

        weight--;
    }

    auto checkdigit = 11 - (digit % 11);
    auto cs = s[9];

    if(checkdigit==10) {
        return cs == 'X';
    }
    if(checkdigit==11) {
        return cs == '0';
    }

    return (cs - '0') == checkdigit;

}
