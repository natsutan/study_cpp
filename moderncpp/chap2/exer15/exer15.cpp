//
// Created by natu on 2021/06/22.
//
//IPv4データ型
//        IPv4アドレスを表すクラス を 書き なさ い。 IPv4アドレスをキーボードから 入力
//       し、 ディスプレイ に出力する のに必要な関数を書き なさ い。 ユーザは、 127.0.0.1や
//       168.192.0.100のよう にドット形式で入力できなければなりません。 これは、 出力に使
//       う形式でもあります。


#include <iostream>
#include <array>
#include <string>

class IPAddress {
    std::array<unsigned char, 4>adr = {0,0,0,0};

public:
    friend std::istream& operator>>(std::istream &os, IPAddress &ipa);
    friend std::ostream& operator<<(std::ostream &os, const IPAddress &ipa);
};

std::istream& operator>>(std::istream &is, IPAddress &ipa) {
    char d1, d2, d3;
    int b1, b2, b3, b4;
    is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;
    if((d1=='.') && (d2=='.') && (d3=='.')) {
        ipa.adr[0] = b1;
        ipa.adr[1] = b2;
        ipa.adr[2] = b3;
        ipa.adr[3] = b4;

    } else {
        is.setstate(std::ios_base::failbit);
    }


    return is;
}


std::ostream& operator<<(std::ostream& os, const IPAddress &ipa) {
    os << static_cast<int>(ipa.adr[0]) << "."
       << static_cast<int>(ipa.adr[1]) << "."
       << static_cast<int>(ipa.adr[2]) << "."
       << static_cast<int>(ipa.adr[3]);
    return os;

}


int main(void)
{
    IPAddress ipa;

    std::cout << "input ip address"  << std::endl;
    std::cin >> ipa;

    std::cout << "IP Address " << ipa << std::endl;

    return 0;
}
