#ifndef HANDLE_HPP
#define HANDLE_HPP

#include <iostream>
#include <cstdio>

template <class T>
class Handle
{
    private:
        T* p;
        std::size_t* refptr;

    public:
        Handle(): p(0), refptr(new std::size_t(1)) { }
        Handle(T* t) : refptr(new std::size_t(1)), p(t) { }
        Handle(const Handle& h) : p(h.p), refptr(h.refptr) { ++*refptr;}
        // Handle(const Handle& s): p(0) { if (s.p) p = s.p->clone(); }
        Handle& operator=(const Handle&);
        ~Handle() {
                    if (--*refptr == 0)
                    {
                        delete p;
                        delete refptr;
                    } }

        operator bool() const { return p; }
        T& operator*() const;
        T* operator->() const;

        void make_unique();
};

template <class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs)
{
    ++*rhs.refptr;

    if (--*refptr == 0)
    {
        delete p;
        delete refptr;
    }

    refptr = rhs.refptr;
    p = rhs.p;
    ++*refptr;

    return *this;
}

template <class T>
T& Handle<T>::operator*() const
{
    if (p)
        return *p;
    return 0;
}

template <class T>
T* Handle<T>::operator->() const
{
    if (p)
        return p;
    return nullptr;
}

template <class T>
void Handle<T>::make_unique()
{
    if (*refptr != 1)
    {
        --*refptr;
        refptr = new std::size_t(1);
        p = p ? p->clone() : 0;
    }
}

#endif