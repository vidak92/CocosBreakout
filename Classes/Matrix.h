//
//  Matrix.hpp
//  Breakout-desktop
//
//  Created by Vidak Mijanovikj on 11/15/17.
//

#ifndef Matrix_h
#define Matrix_h

#include "cocos2d.h"
#include <vector>
#include <initializer_list>

template <typename T, int R, int C>
class Matrix
{
private:
    std::vector<T> _v;
    int _r, _c;

public:
    Matrix() : _v(R * C)
    {
        _r = R;
        _c = C;
//        _v = std::vector<T>(R * C);
    }
    
    Matrix(std::initializer_list<std::initializer_list<T>> il)
    {
        int r = il.size();
        int c = (*il.begin()).size();
        CCASSERT(r == R && c == C, "Matrix initializer list has an invalid number of elements!");
        _r = R;
        _c = C;
        _v.reserve(R * C);
        for (auto list : il)
        {
            for (const T& i : list)
            {
                _v.push_back(i);
            }
        }
    }
    
    ~Matrix(){};
    
    T& at(int i, int j)
    {
        CCASSERT(i >= 0 && i < _r && j >= 0 && j < _c, "Matrix index out of range!");
        int index = i * _c + j;
        return _v.at(index);
    }
    
    typename std::vector<T>::iterator begin() { return _v.begin(); }
    
    typename std::vector<T>::iterator end() { return _v.end(); }
};

#endif /* Matrix_h */
