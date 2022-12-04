#ifndef UNION_H
#define UNION_H

#include<vector>

enum ret_val{
    OPER_SUCCESS, OPER_FAIL
};

class Union
{
public:
    int find(int ptr);
    void union_build(int ptr1, int ptr2);
    bool is_connect(int ptr1, int ptr2);

    Union();
    Union(size_t n);
    ~Union();

private:
    std::vector<int> _father;
    std::vector<int> _rank;
};

#endif