#ifndef VEC_HPP
#define VEC_HPP

#include <iostream>
#include <memory>

template <class T> class Vec
{
    public:
        typedef T* iterator;
        typedef const T* const_interator;
        typedef size_t size_type;
        typedef T value_type;

    private:
        iterator data;
        iterator avail;
        iterator limit;

        std::allocator<T> alloc;

        void create();
        void create(size_type, const T&);
        void create(const_interator, const_interator);

        void uncreate();

        void grow();
        void unchecked_append(const T&);

    public:
        Vec()
        {
            create();
        }

        Vec(size_type n, const T& val = T());
        Vec(const Vec& v);
        ~Vec();
        Vec& operator=(const Vec&);

        void push_back(const T&);
        iterator pop_at(iterator);
        void clear();

        size_type size() const
        {
            return avail - data;
        }

        T& operator[] (size_type i)
        {
            return data[i];
        }

        const T& operator[] (size_type i) const
        {
            return data[i];
        }

        iterator begin()
        {
            return data;
        }

        const iterator begin() const
        {
            return data;
        }

        iterator end()
        {
            return avail;
        }

        const iterator end() const
        {
            return avail;
        }

};

#endif