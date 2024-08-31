#include <iostream>
#include <stdexcept>
#include <stack>


namespace my {

    template<class T>
    struct Node {
        T item;
        Node<T>* next;
    };

    template<class T>
    class stack {

        Node<T>* head;
        size_t _size;

    public:

        stack(): head(nullptr), _size(0) {}

        ~stack() {
            while (!empty()) {
                pop();
            }
        }

        bool empty() {return _size == 0;}
        size_t size() {return _size;}

        T top() {
            if (empty())
                throw std::logic_error("Stack is empty!");
            return head->item;
        }

        void push(T item) {
            Node<T>* node = new Node<T>;
            node->item = item;
            node->next = head;
            head = node;
            _size++;
        }

        void pop() {
            if (empty())
                throw std::logic_error("Stack is empty!");
            Node<T>* node = head;
            head = head->next;
            delete node;
            _size--;
        }
    };

}


int main() {
    std::stack<int> std_stack;
    my::stack<int> my_stack;

    int n = 10;
    for (int i = 0; i < n; i++) {
        std_stack.push(i);
    }
    while (!std_stack.empty()) {
        std::cout << std_stack.top() << ' ';
        std_stack.pop();
    }
    std::cout << std::endl;

    for (int i = 0; i < n; i++) {
        my_stack.push(i);
    }
    while (!my_stack.empty()) {
        std::cout << my_stack.top() << ' ';
        my_stack.pop();
    }

    return 0;
}
