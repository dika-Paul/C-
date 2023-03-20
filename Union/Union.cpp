#include"Union.h"
#include<vector>

Union::Union()
{}

Union::Union(size_t n)
    :_father(std::vector<int>(n)),
    _rank(std::vector<int>(n))
{
    for(int i = 0; i < n; i++)
    {
        this->_father[i] = i;
        this->_rank[i] = 1;
    }
}

Union::~Union()
{}


int Union::find(int ptr)
{
    if(ptr>=_father.size() || ptr<0)    return -1;
    if(this->_father[ptr] == ptr)   return ptr;
    return this->_father[ptr] = find(this->_father[ptr]);
}

void Union::union_build(int ptr1, int ptr2)
{
    int father1 = this->find(ptr1);
    int father2 = this->find(ptr2);
    if(father1 == father2)  return;
    if(this->_rank[father1] == this->_rank[father2])
    {
        this->_rank[father1]++;
        this->_father[father2] = father1;
    }
    else if(this->_rank[father1] > this->_rank[father2])
        this->_father[father2] = father1;
    else
        this->_father[father1] = father2;
    return;
}

bool Union::is_connect(int ptr1, int ptr2)
{
    return this->find(ptr1) == this->find(ptr2);
}
