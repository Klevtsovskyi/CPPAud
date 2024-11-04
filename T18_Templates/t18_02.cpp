#include <iostream>
#include <stack>

namespace my {
    template<class T>
    struct Node {
        T item;
        Node<T>* next;
    };

    template<class T>
    class stack {
    private:
        Node<T>* _top;
    public:
        stack(): _top(nullptr) {}

        ~stack() {
            while (!empty())
                pop();
        }

        bool empty() {return _top == nullptr;}

        T top() {
            if (empty())
                throw std::logic_error("Method 'top' applied to empty container");
            return _top->item;
        }

        void push(T item) {
            Node<T>* node = new Node<T>();
            node->item = item;
            node->next = _top;
            _top = node;
        }

        T pop() {
            if (empty())
                throw std::logic_error("Method 'pop' applied to empty container");
            Node<T>* node = _top;
            _top = _top->next;
            T item = node->item;
            delete node;
            return item;
        }
    };

}


int main() {
    std::stack<char> std_stack;
    my::stack<char> my_stack;

    for (char c = 'a'; c < 'z' + 1; c++) {
        std_stack.push(c);
        my_stack.push(c);
    }

    while (!std_stack.empty()) {
        std::cout << std_stack.top() << ' ';
        std_stack.pop();
    }
    std::cout << std::endl;

    while (!my_stack.empty()) {
        std::cout << my_stack.top() << ' ';
        my_stack.pop();
    }
    std::cout << std::endl;

    return 0;
}
