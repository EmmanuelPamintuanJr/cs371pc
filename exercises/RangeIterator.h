// ---------------
// RangeIterator.h
// ---------------

#ifndef RangeIterator_h
#define RangeIterator_h

#include <cstddef>  // ptrdiff_t
#include <iterator> // input_iterator_tag

using namespace std;

template <typename T>
class Range_Iterator {
    public:
        using iterator_category = input_iterator_tag;
        using value_type        = T;
        using difference_type   = ptrdiff_t;
        using pointer           = T*;
        using reference         = T&;

    private:
        T _v;

    public:
        Range_Iterator(const T& v) :
                _v (v)
            {}

        bool operator == (const Range_Iterator& rhs) const {
            return (_v == rhs._v);}

        bool operator != (const Range_Iterator& rhs) const {
            return !(*this == rhs);}

        const T& operator * () const {
            return _v;}

        //l-value
        
        Range_Iterator& operator ++ () {
            ++_v;
            return *this;}
        
        //returns const so that user cannot modify the returned value;
        //r-value
        
            const Range_Iterator operator ++ (int) {
            Range_Iterator x = *this;
            ++*this;
            return x;}};

#endif // RangeIterator_h
