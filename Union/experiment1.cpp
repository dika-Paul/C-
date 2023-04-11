#include<bits/stdc++.h>
#include"Union.h"

using namespace std;

template <class Type>
class UFSet
{
public:
    void Init(vector<Type>& temp);
    int Find(Type temp);
    void Union_set(Type temp1, Type temp2);
    bool Is_Connect(Type temp1, Type temp2);

    UFSet()
        :_elem(1),
        _ufset(1)
    {}
    UFSet(size_t n)
        :_elem(n),
        _ufset(n)
    {}

private:
    vector<Type> _elem;
    Union _ufset;

    int _find(Type elem);
};

template <class Type>
void UFSet<Type>::Init(vector<Type> &temp)
{
    _elem = temp;
    _ufset = Union(temp.size());
}

template <class Type>
int UFSet<Type>::Find(Type temp)
{
    int ptr = _find(temp);
    return _ufset.find(ptr);
}

template <class Type>
void UFSet<Type>::Union_set(Type temp1, Type temp2)
{
    int ptr1 = _find(temp1);
    int ptr2 = _find(temp2);
    _ufset.union_build(ptr1, ptr2);
}

template <class Type>
bool UFSet<Type>::Is_Connect(Type temp1, Type temp2)
{
    int ptr1 = _find(temp1);
    int ptr2 = _find(temp2);
    return _ufset.is_connect(ptr1, ptr2);
}

template <class Type>
int UFSet<Type>::_find(Type elem)
{
    for(int i = 0; i < _elem.size(); i++)
        if(_elem[i] == elem)
            return i;
    return -1;
}

int main()
{
    return 0;
}