#include<bits/stdc++.h>

using namespace std;

const int init_size = 10;

template <class T> class Vector;
template <typename T> istream& operator>> (istream& _in, Vector<T>& aim);
template <typename T> ostream& operator<< (ostream& _out, const Vector<T>& aim);

template <class T>
class Vector
{
public:
    friend istream& operator>> <T> (istream&, Vector<T>&);
    friend ostream& operator<< <T> (ostream&, const Vector<T>&);
    int size() const;
    bool empty() const;

    Vector()
        :_vector(new T[init_size]),
        len(0),
        cap(init_size)
    {}
    Vector(size_t n, const T& val)
        :_vector(new T[2*n]),
        len(n),
        cap(2*n)
    {
        for(int i = 0; i < len; i++)
            _vector[i] = val;
    }
    Vector(const T& temp)
    {
        len = temp.len;
        cap = temp.cap;
        _vector = new T[cap];
        for(int i = 0; i < len; i++)
            _vector[i] = temp._vector[i];
    }
    ~Vector()
    {
        if(_vector != nullptr)
            delete [] _vector;
    }

private:
    void expand();

    T* _vector;
    int len;
    int cap;
};