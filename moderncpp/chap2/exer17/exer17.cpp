//
// Created by natu on 2021/06/22.
//
//17 基本演算を備えた2次元配列を作る
//        要素へのアクセス（at()およびdata()）、 容量クエリ 、 イテレータ、 フィリング、 スワッ
//        プと いったメソッドを備えた 2次元配列コンテナを表すクラステンプレートを書きなさい。
//        この型のオブジェクトをムーブできるよう にしなさい
// https://ez-net.jp/article/BA/M8FWSt5L/uJoqEhJrMX1i/

#include <iostream>
#include <numeric>
#include <vector>
#include <iostream>
#include <iterator>

template <typename T> class Con2dIterator;

template <typename T> class Con2d {
    friend Con2dIterator<T>;

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

    typedef Con2dIterator<T> iterator;
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


template <typename T>
class Con2dIterator : public std::iterator<std::forward_iterator_tag, T>
{
    friend Con2d<T>;
private:
    size_t _h;
    size_t _w;
    Con2d<T> *_con2d;
    //コンストラクタはプライベートに
    Con2dIterator();
    Con2dIterator(Con2d<T> *p, int index);

public:
    //コピーコンストラクタはpublicに
    Con2dIterator(const Con2dIterator& iterator);
    Con2dIterator& operator++();
    Con2dIterator operator++(Con2d<T>);
    Con2d<T>& operator*();

    bool operator==(const Con2dIterator& iterator);
    bool operator!=(const Con2dIterator& iterator);
};

template<typename T>
Con2dIterator<T>::Con2dIterator() {
    _con2d = nullptr;
    _h = 0;
    _w = 0;
}

template<typename T>
Con2dIterator<T>::Con2dIterator(Con2d<T> *p, int index) {
    _con2d = p;
    _h = (int)(index / (p->width()));
    _w = index % (p->width());
}

template<typename T>
Con2dIterator<T>::Con2dIterator(const Con2dIterator& iterator){
    _con2d = iterator._con2d;
    _w = iterator._w;
    _h = iterator._h;
}


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

    //auto it = mat.begin();

    return 0;
}

