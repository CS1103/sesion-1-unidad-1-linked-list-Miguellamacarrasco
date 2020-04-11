#include "head.h"

template<typename T>
utec::Node<T>::Node()
{
}

template<typename T>
utec::Node<T>::Node(Node* Next)
{
    next = Next;
}

template<typename T>
utec::Node<T>::~Node()
{
}

template <typename T>
utec::LinkedList<T>::LinkedList(size_t n)
{
    longitud = n;
    utec::Node<T> nodo_final;
    utec::Node<T>* prev_point = &nodo_final;
    tail_pointer = prev_point;
    while(--n)
    {
        utec::Node<T> nodo(prev_point);
        prev_point = &nodo;
    }
    head_pointer = prev_point;

}

template<typename T>
void utec::LinkedList<T>::pop_back()
{
    if (head_pointer == tail_pointer)
    {
        delete head_pointer;
        head_pointer = nullptr;
        tail_pointer = nullptr;
    }
    else
    {
        longitud--;
        utec::Node<T>* flying_pointer = head_pointer;
        for (size_t index = longitud;index==0;index--)
        {
            flying_pointer = flying_pointer->next;
        }
        flying_pointer->next = nullptr;
        delete tail_pointer;
        tail_pointer = flying_pointer;
    }
}

