#include<bits/stdc++.h>

using namespace std;

class String
{
public:
    friend istream& operator>> (istream& _in, String& temp);
    friend ostream& operator<< (ostream& _out, const String& temp);
    String& operator= (const String& temp);
    String& operator+= (const String temp);
    String operator+ (const String& temp);
    char& operator[] (const int& ptr);
    String& tolower();
    String& toupper();
    bool empty() const;
    int size() const;

    String()
        :str(nullptr),
        len(0)
    {}
    String(size_t n, const char val = 0)
        :str(new char[n]),
        len(n)
    {
        for(int i = 0; i < n; i++)
            str[i] = val;
    }
    String(const String& temp)
    {
        str = new char[temp.size()];
        len = temp.size();
        for(int i = 0; i < len; i++)
            str[i] = temp.str[i];
    }
    ~String()
    {
        if(str != nullptr)
            delete [] str;
    }

private:
    char* str;
    int len;
};

String &String::operator=(const String &temp)
{
    if(str != nullptr)
        delete [] str;
    str = new char[temp.size()];
    len = temp.size();
    for(int i = 0; i < len; i++)
        str[i] = temp.str[i];
    return *this;
}

String &String::operator+=(const String temp)
{
    char* ptr_temp = new char[len+temp.size()];
    for(int i = 0; i < len; i++)
        ptr_temp[i] = str[i];
    len += temp.size();
    for(int i = len-temp.size(); i < len; i++)
        ptr_temp[i] = temp.str[i-(len-temp.size())];
    if(str != nullptr)
        delete [] str;
    str = ptr_temp;
    return *this;
}

String String::operator+(const String &temp)
{
    String S(*this);
    S += temp;
    return S;
}

String &String::tolower()
{
    for(int i = 0; i < len; i++)
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a'-'A';
    return *this;
}

String &String::toupper()
{
    for(int i = 0; i < len; i++)
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] += 'A'-'a';
    return *this;
}

bool String::empty() const
{
    return len == 0;
}

int String::size() const
{
    return len;
}

int main()
{
    String S;
    cin >> S;
    cout << S << " " <<S.size() << endl;
    cout << S.tolower() << S.toupper() << endl;
    S += S;
    cout << S << endl;
    String U = S;
    cout << U.tolower() << endl;
    cout << (S=U+S) << endl;
    return 0;
}

istream &operator>>(istream &_in, String &temp)
{
    string s;
    cin >> s;
    temp.len = s.size();
    if(temp.str != nullptr)
        delete [] temp.str;
    temp.str = new char[temp.len];
    for(int i = 0; i < temp.len; i++)
        temp.str[i] = s[i];
    return _in;
}

ostream &operator<<(ostream &_out, const String &temp)
{
    for(int i = 0; i < temp.len; i++)
        _out << temp.str[i];
    return _out;
}
