#include <iostream>
#include <conio.h>
#ifndef head.h




namespace utec
{
    template<typename T>
    struct Node{
            utec::Node<T>* next = nullptr;
            T value = {};
        public:
            Node();
            Node(Node* next);
            Node(T element);
            Node(T value,Node *next);
    };
    template<typename T>
    class LinkedList{
            Node<T>* head_pointer = nullptr;
            Node<T>* tail_pointer = nullptr;
            size_t longitud = 0;
        public:
            LinkedList<T> ();
            LinkedList<T> (size_t n);
            LinkedList<T>& operator=(const utec::LinkedList<T>& lista);

            void pop_front();
            void pop_back();
            void push_back(T element);
            void push_front(T element);
            void insert(T element, int index);
            void erase(int index);
            void cout_list();
    };

}
#endif // head



