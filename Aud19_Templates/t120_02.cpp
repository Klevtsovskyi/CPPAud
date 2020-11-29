#include <iostream>
#include <stack>


using namespace std;


class StackError: public logic_error
{
public:

    StackError(const char* message=""): logic_error(message) {}
};


template <class T>
struct Node
{
    T item;
    Node<T>* next;
};


template <class T>
class MyStack
{
private:

    size_t _size;
    Node<T>* head;

public:

    MyStack(): _size(0), head(nullptr) {}

    ~MyStack()
    {
        while (!empty())
            pop();
    }

    bool empty()
    {
        return _size == 0;
    }

    size_t size()
    {
        return _size;
    }

    T top()
    {
        if (empty())
            throw StackError("Stack is empty");
        return head->item;
    }

    void push(T item)
    {
        Node<T>* node = new Node<T>;
        node->item = item;
        node->next = head;
        head = node;
        _size++;
    }

    void pop()
    {
        if (empty())
            throw StackError("Stack is empty");
        Node<T>* node = head;
        // T item = node->item;
        head = node->next;
        delete node;
        _size--;
        // return item;
    }
};


int main()
{
    MyStack<int> myS;
    stack<int> S;

    for (int i = 0; i < 10; i++)
    {
        myS.push(i); S.push(i);
        cout << myS.top() << ' ' << S.top() << endl;
    }

    while (!myS.empty())
    {
        cout << myS.top() << ' ';
        myS.pop();
    }
    cout << endl;

    while (!S.empty())
    {
        cout << S.top() << ' ';
        S.pop();
    }
    cout << endl;

    return 0;
}
