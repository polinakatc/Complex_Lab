#pragma once
#include<iostream>
#include<cmath>
using namespace std;

template<class T>
class TComplex {
public:
    TComplex();
    TComplex(T re, T im);
    TComplex(const TComplex& num);
    ~TComplex();
    T GetRe();
    T GetIm();
    void SetRe(T re);
    void SetIm(T im);
    TComplex operator + (const TComplex& num);
    TComplex operator - (const TComplex& num);
    TComplex operator * (const TComplex& num);
    TComplex operator / (const TComplex& num);
    TComplex& operator += (const TComplex& num);
    TComplex& operator -= (const TComplex& num);
    TComplex& operator *= (const TComplex& num);
    TComplex& operator /= (const TComplex& num);
    TComplex& operator = (const TComplex& num);
    bool operator == (const TComplex& num);
    bool operator != (const TComplex& num);

    template<class D>
    friend ostream& operator << (ostream& out, TComplex<D>& num);
    template<class D>
    friend istream& operator >> (istream& in, TComplex<D>& num);

private:
    T re;
    T im;
};

template<class T>
TComplex<T>::TComplex() : re(0), im(0) {}

template<class T>
TComplex<T>::TComplex(T re_, T im_) : re(re_), im(im_) {}

template<class T>
TComplex<T>::TComplex(const TComplex& num) : re(num.re), im(num.im) {}

template<class T>
TComplex<T>::~TComplex() {}

template<class T>
T TComplex<T>::GetRe()
{
    return re;
}
template<class T>
T TComplex<T>::GetIm()
{
    return im;
}
template<class T>
void TComplex<T>::SetRe(T re)
{
    this->re = re;
}
template<class T>
void TComplex<T>::SetIm(T im)
{
    this->im = im;
}
template<class T>
TComplex<T>& TComplex<T>::operator = (const TComplex<T>& num)
{
    if (this != &num)
    {
        this->re = num.re;
        this->im = num.im;
    }
    return *this;
}
template<class T>
bool TComplex<T>::operator == (const TComplex<T>& num)
{
    return this->re == num.re && this->im == num.im;
}
template<class T>
bool TComplex<T>::operator != (const TComplex<T>& num)
{
    return !(*this == num);
}
template<class T>
TComplex<T> TComplex<T> :: operator + (const TComplex<T>& num)
{
    return TComplex<T>(this->re + num.re, this->im + num.im);
}
template<class T>
TComplex<T> TComplex<T> :: operator - (const TComplex<T>& num)
{
    return TComplex<T>(this->re - num.re, this->im - num.im);
}
template<class T>
TComplex<T> TComplex<T> :: operator * (const TComplex<T>& num)
{
    return TComplex<T>(this->re * num.re - this->im * num.im, this->re * num.im + this->im * num.re);
}
template<class T>
TComplex<T> TComplex<T> :: operator / (const TComplex<T>& num)
{
    T den = num.re * num.re + num.im * num.im;
    if (den == 0) throw "Division by 0";
    else return TComplex<T>((this->re * num.re + this->im * im)/den,(this->im*num.re - this->re*num.im)/den);
}
template<class T>
TComplex<T>& TComplex<T>::operator += (const TComplex<T>& num)
{
    this->re += num.re;
    this->im += num.im;
    return *this;
}
template<class T>
TComplex<T>& TComplex<T>::operator -= (const TComplex<T>& num)
{
    this->re -= num.re;
    this->im -= num.im;
    return *this;
}
template<class T>
TComplex<T>& TComplex<T>::operator *= (const TComplex<T>& num)
{
    T temp_re = this->re * num.re - this->im * num.im;
    T temp_im = this->re * num.im + this->im * num.re;
    this->re = temp_re;
    this->im = temp_im;
    return *this;
}
template<class T>
TComplex<T>& TComplex<T>::operator /= (const TComplex<T>& num)
{
    T den = num.re * num.re + num.im * num.im;
    if (den == 0) throw "Division by 0";
    T temp_re = (this->re * num.re + this->im * num.im) / den;
    T temp_im = (this->im * num.re - this->re * num.im) / den;
    this->re = temp_re;
    this->im = temp_im;
    return *this;
}
template<class D>
std::istream& operator >> (std::istream& in, TComplex<D>& num)
{
    cout << "Enter real part: ";
    in >> num.re;
    cout << "Enter imaginary part: ";
    in >> num.im;
    return in;
}
template<class D>
std::ostream& operator << (std::ostream& out, TComplex<D>& num)
{
    if (num.re == 0 && num.im == 0) {
        out << "0";
        return out;
    }
    out << "(" << num.GetRe() << ", " << num.GetIm()<< "i" << ")";
    return out;
}
