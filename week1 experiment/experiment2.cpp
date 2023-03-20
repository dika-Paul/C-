/*实验要求：用高度进行比较来完成并查集*/

#include<bits/stdc++.h>

using namespace std;

class UFSet
{
public:
    int find(int ptr);
    void Union(int ptr1, int ptr2);
    bool is_connect(int ptr1, int ptr2);

    UFSet()
        :parent(10),
        rank(10, 1)
    {
        for(int i = 0; i < 10; i++)
            parent[i] = i;
    }
    UFSet(size_t n)
        :parent(n),
        rank(n, 1)
    {
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    ~UFSet()
    {}

private:
    vector<int> parent;
    vector<int> rank;
};

int UFSet::find(int ptr)
{
    if(ptr >= parent.size() || ptr < 0) return -1;
    if(ptr == parent[ptr])  return ptr;
    return parent[ptr] = find(parent[ptr]);
}

void UFSet::Union(int ptr1, int ptr2)
{
    int parent1 = find(ptr1);
    int parent2 = find(ptr2);
    if(parent1 != parent2)
    {
        if(rank[parent1] == rank[parent2])
        {
            rank[parent1]++;
            parent[parent2] = parent1;
        }
        else if(rank[parent1] > rank[parent2])
            parent[parent2] = parent1;
        else
            parent[parent1] = parent2;
    }
}

bool UFSet::is_connect(int ptr1, int ptr2)
{
    return find(ptr1) == find(ptr2);
}

int main()
{
    UFSet U(15);
    U.Union(0,1);
    U.Union(1,9);
    cout << U.is_connect(0, 9);
    return 0;
}