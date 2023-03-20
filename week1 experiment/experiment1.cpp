/*实验要求：用孩子兄弟法表示树并求高度与度*/

#include<bits/stdc++.h>

using namespace std;

struct Node
{
    char data;
    Node* Fchild;
    Node* Fbrother;
    Node()
        :data(0),
        Fchild(nullptr),
        Fbrother(nullptr)
    {}
    Node(Node* Fc, Node* Fb, char Data)
        :data(Data),
        Fchild(Fc),
        Fbrother(Fb)
    {}
    ~Node()
    {}
};

class Tree
{
public:
    void Init_Tree();
    void Build_TreeNode(Node*& ptr);
    int Hight();
    int Width();

    Tree()
        :root(nullptr)
    {}
    ~Tree()
    {
        queue<Node*> del_que;
        del_que.push(root);
        while(!del_que.empty())
        {
            Node* del_aim = del_que.front();
            del_que.pop();
            if(del_aim == nullptr)
                continue;
            if(del_aim->Fchild != nullptr)
                del_que.push(del_aim->Fchild);
            if(del_aim->Fbrother != nullptr)
                del_que.push(del_aim->Fbrother);
            delete del_aim;
            
        }
    }

private:
    Node* root;
};

void Tree::Init_Tree()
{
    Build_TreeNode(root);
}

void Tree::Build_TreeNode(Node*& ptr)
{
    char c;
    cin >> c;
    if(c != '#')
    {
        ptr = new Node(nullptr, nullptr, c);
        Build_TreeNode(ptr->Fchild);
        Build_TreeNode(ptr->Fbrother);
    }
    else
        ptr = nullptr;
}

int Tree::Hight()
{
    if(root == nullptr)
        return 0;
    int hight = 1;
    int temp_hight = 1;
    stack<Node*> sta1;
    stack<int> sta2;
    sta1.push(root);
    sta2.push(0);
    while(!sta1.empty())
    {
        Node* temp = sta1.top();
        if(sta2.top() == 0)
        {
            sta2.pop();
            sta2.push(1);
            if(temp->Fchild != nullptr)
            {
                temp_hight++;
                sta1.push(temp->Fchild);
                sta2.push(0);
            }
            else
                hight = max(hight, temp_hight);
        }
        else if(sta2.top() == 1)
        {
            sta2.pop();
            sta2.push(2);
            if(temp->Fbrother != nullptr)
            {
                sta1.push(temp->Fbrother);
                sta2.push(0);
            }
        }
        else
        {
            if(sta1.top() == root)
                break;
            sta2.pop();
            sta1.pop();
            if(sta2.top() == 1)
                temp_hight--;
        }
    }
    return hight;
}

int Tree::Width()
{
    if(root == nullptr)
        return 0;
    int width = 0;
    queue<Node*> que;
    que.push(root);
    while (!que.empty())
    {
        Node* temp = que.front();
        que.pop();
        int temp_width = 0;
        while(temp != nullptr)
        {
            temp_width++;
            if(temp->Fchild != nullptr)
                que.push(temp->Fchild);
            temp = temp->Fbrother;
        }
        width = max(width, temp_width);
    }
    return width;
}
/*
int main()
{
    Tree T;
    T.Init_Tree();
    cout << T.Width() << " " << T.Hight();
    return 0;
}*/