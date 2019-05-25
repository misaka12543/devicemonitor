#ifndef SCARRAY_H
#define SCARRAY_H
#pragma once
/**
  Forget this file .... It make lots of error
*/
#include <iostream>
#include <cstring>
#pragma once
///variable array,
///int value
class SCArray
{
    int size;  //数组元素的个数
    int* ptr;  //指向动态分配的数组
public:
    ///s代表数组元素的个数
    SCArray(int s = 0);
    SCArray(SCArray & a);
    ~SCArray();

    ///用于在数组尾部添加一个int元素 v
    void push_back(int v);

    ///用于数组对象间的赋值
    SCArray & operator = (const SCArray & a);

    ///返回数组元素个数
    int length() const
    { return size; }

    ///用以支持根据下标访问数组元素，如“a[i]=4;”和“n=a[i];”这样的语句
    int & operator[](int i)
    {
        return ptr[i];
    }
};

#endif // SCARRAY_H
