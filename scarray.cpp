#include <scarray.h>

SCArray::SCArray(int s) : size(s)
{
    if (s == 0)
        ptr = nullptr;
    else
        ptr = new int[s];
}
SCArray::SCArray(SCArray & a)
{
    if (!a.ptr) {
        ptr = nullptr;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
}
SCArray::~SCArray()
{
    if (ptr) delete[] ptr;
}
///赋值号的作用是使 = 左边对象中存放的数组的大小和内容都与右边的对象一样
SCArray & SCArray::operator=(const SCArray & a)
{
    if (ptr == a.ptr)  //防止 a=a 这样的赋值导致出错
        return *this;
    if (a.ptr == nullptr) //如果a里面的数组是空的
    {
        if (ptr)
            delete[] ptr;
        ptr = nullptr;
        size = 0;
        return *this;
    }
    if (size < a.size) //如果原有空间够大，就不用分配新的空间
    {
        if (ptr)
            delete[] ptr;
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(int)*a.size);
    size = a.size;
    return *this;
}

