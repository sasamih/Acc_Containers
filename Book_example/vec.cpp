#include "vec.hpp"

template <class T>
Vec<T>::Vec(size_type n, const T& val)
{
    create (n, val);
}

template <class T>
Vec<T>::Vec(const Vec& v)
{
    create(v.begin(), v.end());
}

template <class T>
Vec<T>::~Vec()
{
    uncreate();
}

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
    if (&rhs != this)
    {
        uncreate();
        create(rhs.begin(), rhs.end());
    }

    return *this;
}

template <class T>
void Vec<T>::create()
{
    data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val)
{
    data = alloc.allocate(n);
    limit = avail = data + n;
    uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_interator b, const_interator e)
{
    data = alloc.allocate(e - b);
    limit = avail = uninitialized_copy(b, e, data);
}

template <class T>
void Vec<T>::uncreate()
{
    if (data)
    {
        iterator it = avail;
        while (it != data)
            alloc.destroy(--it);
        
        alloc.deallocate(data, limit - data);
    }
    create();
}

template <class T>
void Vec<T>::grow()
{
    size_type newSize = (limit - data) ? 2 * (limit - data) : ptrdiff_t(1);
    iterator newData = alloc.allocate(newSize);
    iterator newAvail = std::uninitialized_copy(data, avail, newData);

    uncreate();
    data = newData;
    avail = newAvail;
    limit = newData + newSize;
}

template <class T>
void Vec<T>::unchecked_append(const T& val)
{
    alloc.construct(avail++, val);
}

template <class T>
void Vec<T>::push_back(const T& val)
{
    if (avail == limit)
    {
        grow();
    }
    unchecked_append(val);
}

template <class T>
typename Vec<T>::iterator Vec<T>::pop_at(iterator it)
{
    iterator newAvail;
    iterator newData;
    size_type retDiff;

    if ((it >= data) && (it < avail))
    {
        retDiff = it - data;
        newData = alloc.allocate(size() - 1);
        newAvail = std::uninitialized_copy(data, it, newData);
        for (auto tmpIt = it + 1; tmpIt != avail; tmpIt++)
        {
            alloc.construct(newAvail++, tmpIt[0]);
        }
    }

    data = newData;
    avail = newAvail;
    limit = data + (size() - 1);
    
    return (data + retDiff);
}

template <class T>
void Vec<T>::clear()
{
    uncreate();
}

int main()
{
    Vec<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    std::cout << "Value: " << v[2] << std::endl;  
    Vec<int>::iterator it = v.begin() + 2;
    std::cout << "Iter: " << *it << std::endl;
    it = v.pop_at(it);
    std::cout << "Iter after pop: " << *it << std::endl;

    return 0;
}