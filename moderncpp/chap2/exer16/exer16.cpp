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
    IPAddress(unsigned char a0, unsigned char a1, unsigned char a2, unsigned char a3) {
        adr[0] = a0;
        adr[1] = a1;
        adr[2] = a2;
        adr[3] = a3;
    }

    friend std::istream& operator>>(std::istream &os, IPAddress &ipa);
    friend std::ostream& operator<<(std::ostream &os, const IPAddress &ipa);
    bool operator==(const IPAddress& rhs) const;
    bool operator!=(const IPAddress& rhs) const;
    bool operator<(const IPAddress& rhs) const;
    bool operator>(const IPAddress& rhs) const;
    bool operator<=(const IPAddress& rhs) const;
    bool operator>=(const IPAddress& rhs) const;
    void operator++();
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



bool IPAddress::operator==(const IPAddress& rhs) const
{
    return (adr[0] == rhs.adr[0]) && (adr[1] == rhs.adr[1]) && (adr[2] == rhs.adr[2]) && (adr[3] == rhs.adr[3]);
}

bool IPAddress::operator!=(const IPAddress& rhs) const
{
    return !(*this == rhs);
}

bool IPAddress::operator<(const IPAddress& rhs) const
{
    if(adr[0] != rhs.adr[0]) {
        return adr[0] < rhs.adr[0];
    }
    if(adr[1] != rhs.adr[1]) {
        return adr[1] < rhs.adr[1];
    }
    if(adr[2] != rhs.adr[2]) {
        return adr[2] < rhs.adr[2];
    }
    return adr[3] < rhs.adr[3];

}

bool IPAddress::operator>(const IPAddress& rhs) const {
    if (*this == rhs) {
        return false;
    }
    if(*this < rhs) {
        return false;
    }
    return true;
}

bool IPAddress::operator>=(const IPAddress& rhs) const {
    return (*this == rhs) || (*this > rhs);
}

bool IPAddress::operator<=(const IPAddress& rhs) const {
    return (*this == rhs) || (*this < rhs);
}

void IPAddress::operator++()  {
    if(adr[3]!=255) {
        ++adr[3];
        return;
    }
    adr[3] = 0;
    if(adr[2]!=0) {
        ++adr[2];
        return;
    }
    adr[2] = 0;
    if(adr[1]!=0) {
        ++adr[1];
        return;
    }
    adr[1] = 0;
    ++adr[0];


}

void op_test(void);

int main(void)
{

    IPAddress ipa = IPAddress(192, 168, 20, 3);
    IPAddress ipb = IPAddress(192, 168, 22, 1);

    //op_test();
    for(auto adr=ipa;adr<ipb;++adr) {
        std::cout << adr << std::endl;
    }

    return 0;
}

void op_test(void)
{
    IPAddress ipa = IPAddress(192, 168, 20, 3);
    IPAddress ipb = IPAddress(192, 168, 22, 1);
    IPAddress ipc = IPAddress(192, 168, 20, 3);


    std::cout << "ipa " << ipa << std::endl;
    std::cout << "ipb " << ipb << std::endl;

    std::cout << "ipa == ipb:" << (ipa == ipb) << std::endl;
    std::cout << "ipa == ipc:" << (ipa == ipc) << std::endl;

    std::cout << "ipa < ipb:" << (ipa < ipb) << std::endl;
    std::cout << "ipb < ipa:" << (ipb < ipa) << std::endl;
    std::cout << "ipa < ipc:" << (ipa < ipc) << std::endl;

    std::cout << "ipa > ipb:" << (ipa > ipb) << std::endl;
    std::cout << "ipb > ipa:" << (ipb > ipa) << std::endl;
    std::cout << "ipa > ipc:" << (ipa > ipc) << std::endl;

    std::cout << "ipa >= ipb:" << (ipa >= ipb) << std::endl;
    std::cout << "ipb >= ipa:" << (ipb >= ipa) << std::endl;
    std::cout << "ipa >= ipc:" << (ipa >= ipc) << std::endl;

    std::cout << "ipa <= ipb:" << (ipa <= ipb) << std::endl;
    std::cout << "ipb <= ipa:" << (ipb <= ipa) << std::endl;
    std::cout << "ipa <= ipc:" << (ipa <= ipc) << std::endl;


}