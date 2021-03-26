#include <iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node()
    {
        left = right = NULL;
    }
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
    int getData()
    {
        return data;
    }
    void setData(int data)
    {
        this->data = data;
    }
    Node *getLeft()
    {
        return left;
    }
    void setLeft(Node *left)
    {
        this->left = left;
    }
    Node *getRight()
    {
        return right;
    }
    void setRight(Node *right)
    {
        this->right = right;
    }
};
template <class T>
class Queue
{
private:
    int size;
    int rare;
    int front;
    T *store;

public:
    Queue(int size)
    {
        this->size = size;
        front = rare = -1;
        store = new T[size];
    }
    ~Queue()
    {
        delete[] store;
    }
    int isEmpty()
    {
        if (front == rare)
        {
            return 1;
        }
        return 0;
    }
    int isFull()
    {
        if (rare == (size - 1))
        {
            return 1;
        }
        return 0;
    }
    void enqueue(T data)
    {
        rare++;
        store[rare] = data;
    }
    T dequeute()
    {
        front++;
        T data = store[front];
        if (front == rare)
        {
            front = rare = -1;
        }
        return data;
    }
};
class btree
{
    Node *root;

public:
    btree()
    {
        root = NULL;
    }
    void insertion(int data)
    {
        Node *node = new Node(data);
        if (root == NULL)
        {
            root = node;
        }
        else
        {
            Node *temp = root;
            Node *prev = NULL;
            while (temp != NULL)
            {
                prev = temp;
                if (data <= temp->getData())
                {
                    temp = temp->getLeft();
                }
                else
                {
                    temp = temp->getRight();
                }
            }
            if (data <= prev->getData())
            {
                prev->setLeft(node);
            }
            else
            {
                prev->setRight(node);
            }
        }
    }
    Node *findParent(int data)
    {
        Node *temp = root;
        while (temp != NULL)
        {
            if (temp->getLeft() != NULL)
            {
                if (data == temp->getLeft()->getData())
                    return temp;
            }
            if (temp->getRight() != NULL)
            {
                if (data == temp->getRight()->getData())
                    return temp;
            }
            if (data < temp->getData())
                temp = temp->getLeft();
            else
                temp = temp->getRight();
        }
        return NULL;
    }
    Node *search(int data)
    {
        Node *temp = root;
        while (temp != NULL)
        {
            if (temp->getData() == data)
            {
                return temp;
            }
            if (data < temp->getData())
            {
                temp = temp->getLeft();
            }
            else
            {
                temp = temp->getRight();
            }
        }
        return NULL;
    }
    void deletion(int data)
    {
        Node *node = search(data);
        if (node == NULL)
        {
            cout << "Data Does Not Exist" << endl;
        }
        else if (node->getLeft() == NULL && node->getRight() == NULL)
        {
            Node *parent = findParent(data);
            if (parent == NULL)
            {
                root = NULL;
            }
            else
            {
                if (data <= parent->getData())
                    parent->setLeft(NULL);
                else
                    parent->setRight(NULL);
                delete node;
            }
        }
        else
        {

            Node *parent = findParent(data);
            if (parent == NULL)
            {
                if (node->getLeft() != NULL)
                    root = node->getLeft();
                else
                    root = node->getRight();
            }
            else
            {
                if (data <= parent->getData())
                {
                    if (node->getLeft() != NULL)
                        parent->setLeft(node->getLeft());
                    else
                        parent->setLeft(node->getRight());
                }
                else
                {
                    if (node->getLeft() != NULL)
                        parent->setRight(node->getLeft());
                    else
                        parent->setRight(node->getRight());
                }
                delete node;
            }
        }
    }
    int total = 0;
    void CountTotalNumberNode()
    {
        Queue<Node *> store(100);
        store.enqueue(root);
        while (!store.isEmpty())
        {
            Node *node = store.dequeute();
            total++;
            //cout << node->getData() << " ";
            if (node->getLeft() != NULL)
                store.enqueue(node->getLeft());
            if (node->getRight() != NULL)
            {
                store.enqueue(node->getRight());
            }
        }
        cout << "==Total Node===" << total << endl;
    }
    void preorder(Node *root)
    {
        if (root != NULL)
        {
            cout << root->getData() << " ";
            preorder(root->getLeft());
            preorder(root->getRight());
        }
    }
    void preOrder()
    {
        preorder(root);
        cout << "=======";
    }
    int count = 0;
    void inorder(Node *root)
    {

        if (root != NULL)
        {
            inorder(root->getLeft());

            count++;
            if (count == 2)
            {
                cout << "SecondMinnumum() " << root->getData();
            }
            inorder(root->getRight());
        }
    }
    void SecondMinnumum()
    {
        inorder(root);
        cout << "=======";
    }
};
int main()
{

    int n, x;
    btree b;
    cout << "Enter How manny element do you want to insert";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data = 0;
        cin >> data;
        b.insertion(data);
    }
    b.CountTotalNumberNode();
    cout << "Enter element do you want to delete ";
    cin >> x;
    b.deletion(x);
    //b.BFT();
    cout << "Preorder" << endl;
    b.preOrder();
    b.SecondMinnumum();
    return 0;
}