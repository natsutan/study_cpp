//
// Created by natu on 2021/06/22.
//
//17 基本演算を備えた2次元配列を作る
//        要素へのアクセス（at()およびdata()）、 容量クエリ 、 イ テレータ、 フィ リ ング、 スワッ
//        プと いったメ ソッドを備えた 2次元配列コンテナを表すクラステンプレート を書き なさ
//い。 この型のオブジェクトをムーブできるよう にしなさい

#include <iostream>
#include <numeric>
#include <vector>
#include <iostream>

template <typename T> class Con2d {
public:
    int width(void) const { return _w;}
    int height(void) const {return _h;}
    int size(void) const { return _w * _h;}
    const T& data(int h, int w) const {
        return _data[h][w];
    }
    T* at(int h, int w) {
        return &_data[h][w];
    }


    Con2d(int h, int w, T ivalue) {
        _w = w;
        _h = h;
        for(int i=0;i<h;++i) {
            std::vector<T> elm(w, ivalue);
            _data.push_back(elm);
        }
    }

private:
    int _w;
    int _h;
    std::vector<std::vector<T>> _data;

    //std::ostream& operator<<(std::ostream& os, const Con2d<T>& m);
};

template <typename T> std::ostream& operator<<(std::ostream& os, const Con2d<T>& m)
{
    os << "size " << m.width() << "," << m.height() << std::endl;
    for(int h=0;h<m.height();++h) {
        for(int w=0;w<m.width();++w) {
            os << m.data(h, w);
            if(w!=(m.width()-1)) {
                os << ", ";
            }
        }
        os << std::endl;
    }
    return os;
}

int main(void)
{
    Con2d<int> mat(2, 3, 0);

    std::cout << mat;

    return 0;
}

