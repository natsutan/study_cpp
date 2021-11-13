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
    void swap(Con2d<T> &x);

private:
    int _w;
    int _h;
    std::vector<std::vector<T>> _data;

    //std::ostream& operator<<(std::ostream& os, const Con2d<T>& m);
};


template<typename T>
typename Con2d<T>::iterator Con2d<T>::begin() {
    return Con2dIterator(this, 0);
}

template<typename T>
typename Con2d<T>::iterator Con2d<T>::end() {
    int last = this->_w * this->_h;
    return Con2dIterator(this, last);
}

template<typename T>
void Con2d<T>::swap(Con2d<T> &x) {
    if((_h != x._h) || (_w != x._w)) {
        std::cerr << "size not matched" << std::endl;
        return;
    }

    Con2d<T> tmp(_h, _w, _data[0][0]);
    std::copy(this->begin(),this->end(), tmp.begin());
    std::copy(x.begin(),x.end(), this->begin());
    std::copy(tmp.begin(),tmp.end(), x.begin());

    return;
}


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
    size_t _hi;
    size_t _wi;
    Con2d<T> *_con2d;
    //コンストラクタはプライベートに
    Con2dIterator();
    Con2dIterator(Con2d<T> *p, int index);

public:
    //コピーコンストラクタはpublicに
    Con2dIterator(const Con2dIterator& iterator);
    Con2dIterator& operator++();
    Con2dIterator operator++(int);
    T& operator*();

    bool operator==(const Con2dIterator& iterator);
    bool operator!=(const Con2dIterator& iterator);
};

template<typename T>
Con2dIterator<T>::Con2dIterator() {
    _con2d = nullptr;
    _hi = 0;
    _wi = 0;
}

template<typename T>
Con2dIterator<T>::Con2dIterator(Con2d<T> *p, int index) {
    _con2d = p;
    _hi = (int)(index / ((*p)._w));
    _wi = index % ((*p)._h);
}

template<typename T>
Con2dIterator<T>::Con2dIterator(const Con2dIterator& iterator){
    _con2d = iterator._con2d;
    _wi = iterator._wi;
    _hi = iterator._hi;
}

template<typename T>
bool Con2dIterator<T>::operator==(const Con2dIterator &iterator) {
    if ((this->_hi == iterator._hi) && (this->_wi == iterator._wi)) {
        return true;
    }
    return false;
}

template<typename T>
bool Con2dIterator<T>::operator!=(const Con2dIterator &iterator) {
    return !(*this == iterator);
}

template<typename T>
Con2dIterator<T>& Con2dIterator<T>::operator++() {
    auto w_max = (*_con2d)._w;
    _wi = _wi + 1;
    if(_wi == w_max) {
        _hi++;
        _wi = 0;
    }
    
    return *this;
}

template<typename T>
Con2dIterator<T> Con2dIterator<T>::operator++(int) {
    Con2dIterator<T> result = *this;
    ++result;

    return result;
}

template<typename T>
T &Con2dIterator<T>::operator*() {
    return _con2d->_data[_hi][_wi];
}


int main(void)
{
    Con2d<int> mat(2, 3, 0);

    mat.fill(2);
    mat(0, 0) = -1;
    mat(0, 1) = 5;
    mat(0, 2) = 3;
    std::cout << mat << std::endl;


    Con2d<int> b(2, 3, 0);
    mat.swap(b);
    std::cout << "SWAP" << std::endl;
    std::cout << mat << std::endl;
    std::cout << b << std::endl;

    Con2d<int> c(std::move(b));
    std::cout << "move" << std::endl;
    std::cout << c << std::endl;
//    std::cout << b << std::endl;


    return 0;
}

