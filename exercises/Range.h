// ---------
// Range.c++
// ---------

#ifndef Range_h
#define Range_h

template <typename T>
class Range {
    private:
        T _b;
        T _e;

    public:
        class iterator {
            private:
                T _v;

            public:
                iterator(const T& v) :
                        _v (v)
                    {}

                bool operator == (const iterator& rhs) const {
                    return (_v == rhs._v);}

                bool operator != (const iterator& rhs) const {
                    return !(*this == rhs);}

                T operator * () {
                    return _v;}

                iterator& operator ++ () {
                    ++_v;
                    return *this;}

                const iterator operator ++ (int) {
                    iterator x = *this;
                    ++*this;
                    return x;}};

        Range (const T& b, const T& e) :
                _b (b),
                _e (e)
            {}

        const iterator begin () const {
            return iterator(_b);}

        const iterator end () const {
            return iterator(_e);}};

#endif // Range_h
