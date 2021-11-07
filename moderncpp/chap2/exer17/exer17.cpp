//
// Created by natu on 2021/06/22.
//
//17 基本演算を備えた2次元配列を作る
//        要素へのアクセス（at()およびdata()）、 容量クエリ 、 イ テレータ、 フィ リ ング、 スワッ
//        プと いったメ ソッドを備えた 2次元配列コンテナを表すクラステンプレート を書き なさ
//い。 この型のオブジェクトをムーブできるよう にしなさい
// https://ez-net.jp/article/BA/M8FWSt5L/uJoqEhJrMX1i/

#include <iostream>
#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>

template <typename T> class Cond2dIterator;

template <typename T> class Con2d {
    friend Cond2dIterator<T>;

public:
    int width(void) const { return _w;}
    int height(void) const {return _h;}
    size_t size(void) const { return _w * _h;}
    const T& data(int h, int w) const {
        return _data[h][w];
    }
    T* at(int h, int w) {
        return &_data[h][w];
    }

    void fill(T f) {
        for(int i=0;i<_h;++i) {
            for(int j=0;j<_w;++j) {
                this->operator()(i, j) = f;
            }
        }
    }

    Con2d(int h, int w, T ivalue) {
        _w = w;
        _h = h;
        for(int i=0;i<h;++i) {
            std::vector<T> elm(w, ivalue);
            _data.push_back(elm);
        }
    }

    T& operator() (int h, int w) {
        return _data[h][w];
    }
    T const & operator() (int h, int w) const {
        return _data[h][w];
    }

    typedef Cond2dIterator<T> iterator;
    Con2d::iterator begin();
    Con2d::iterator end();


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


template <typename T> class Cond2dIterator : public std::iterator<std::forward_iterator_tag, T> {
    friend Con2d<T>;

            private:
                size_t _h;
                size_t _w;
                Con2d<T> *_con2d;
            };


int main(void)
{
    Con2d<int> mat(2, 3, 0);

    std::cout << mat;
    std::cout << mat.size() << std::endl;

    mat.fill(2);
    std::cout << mat;

    mat(0, 1) = 5;
    std::cout << mat;

    std::cout << mat(0, 1) << std::endl;

    return 0;
}

