#include <iostream>
#include <conio.h>
#include <cassert>
#include <string>
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
            LinkedList<T> (size_t n); //La razon por la que no paso por referencia es para cubrir en el caso de que n no sea una variable
            LinkedList<T>(const LinkedList& lista);
            LinkedList<T>& operator=(const utec::LinkedList<T>& lista);
            LinkedList<T>(LinkedList&& lista) noexcept;
            LinkedList<T>& operator=(LinkedList&& lista) noexcept;

            ~LinkedList<T>();

            void pop_front();
            void pop_back();
            void push_back(T element);
            void push_front(T element);
            void insert(T element, size_t index);
            void erase(size_t index);
            T item(size_t index) const;
            size_t size() const;
            void cout_list();
            utec::Node<T>* head() const;
    };

}
#endif // head



