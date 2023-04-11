#include<bits/stdc++.h>

using namespace std;

class A
{
    public:
        void go();
};

class B : public A
{
};

void go(A temp);


int main()
{
    char* str = "aaaaaa";
    cout << strlen(str);
    return 0;
}