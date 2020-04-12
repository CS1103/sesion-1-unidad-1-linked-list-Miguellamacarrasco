#include "head.h"

/* Definiciones de nodo */


template<typename T>
utec::Node<T>::Node() //Constructor por defecto
{
}


template<typename T>
utec::Node<T>::Node(Node* Next) //Constructor conectado al siguiente nodo
{
    next = Next;
}


template <typename T>
utec::Node<T>::Node(T element, Node* Next) //Constructor con elemento y conectado al siguiente nodo
{
    value = element;
    next = Next;
}


template <typename T>
utec::Node<T>::Node(T element) //Constructor con elemento
{
    value = element;
}

/* Definiciones Linkedlist */


template <typename T>
utec::LinkedList<T>::LinkedList(size_t n) //Constructor con la longitud de la lista
{
    longitud = n;
    utec::Node<T>* prev_point = new utec::Node<T>{}; //Declaro el ultimo nodo apuntando a nullptr y vacio como nodo anterior
    tail_pointer = prev_point; //le informo a la clase cual es el ultimo elemento de la lista
    for(size_t counter = 0; counter < n; counter++)
    {
        utec::Node<T> * nodo = new Node<T>{prev_point}; //Declaro un Nodo dinamico apuntando al nodo anterior
        prev_point = nodo; //Declaro el nodo anterior a el nodo que acabo de crear
    }
    head_pointer = prev_point; //Declaro donde empieza la lista

}

template<typename T>
utec::LinkedList<T>::LinkedList(const utec::LinkedList<T>& lista) //Constructor copia
{
    utec::Node<T>* flying_pointer = lista.head_pointer;
    for (int n = lista.longitud; n!=1; n--)
    {
        utec::Node<T> nodo = new utec::Node<T>{flying_pointer->value, flying_pointer->next};
        flying_pointer = flying_pointer->next;
    }
}


template<typename T>
utec::LinkedList<T>& utec::LinkedList<T>::operator=(const utec::LinkedList<T> &lista) //Constructor asignacion
{
    utec::Node<T>* flying_pointer = lista.head_pointer;
    for (int n = lista.longitud; n!=1; n--)
    {
        utec::Node<T> nodo = new utec::Node<T>{flying_pointer->value, flying_pointer->next};
        flying_pointer = flying_pointer->next;
    }
    return *this;
}


template<typename T>
utec::LinkedList<T>::LinkedList(utec::LinkedList<T> &&lista) noexcept //Constructor Move
{
    utec::Node<T>* flying_pointer = lista.head_pointer;
    for (int n = lista.size(); n!=1; n--)
    {
        utec::Node<T> nodo = new utec::Node<T>{std::move(flying_pointer->value), std::move(flying_pointer->next)};
        flying_pointer = flying_pointer->next;
    }
}

template<typename T>
utec::LinkedList<T>& utec::LinkedList<T>::operator=(utec::LinkedList<T> && lista) noexcept //Constructor Move asign
{
    utec::Node<T>* flying_pointer = lista.head_pointer;
    for (int n = lista.longitud; n!=1; n--)
    {
        utec::Node<T> nodo = new utec::Node<T>{std::move(lista->value), std::move(lista->next)};
        flying_pointer = flying_pointer->next;
    }
    return *this;
}




template<typename T>
void utec::LinkedList<T>::pop_back() //Quitar ultimo elemento
{
    if (head_pointer == tail_pointer) //Si la lista tiene un solo elemento
    {
        delete head_pointer; //Eliminar y apuntar a null
        head_pointer = nullptr;
        tail_pointer = nullptr;
        longitud = 0;
    }
    else
    {
        longitud--;
        utec::Node<T>* flying_pointer = head_pointer; //declaro un puntero "volando" sobre los demas punteros (me gusto el nombre)
        while(flying_pointer->next != tail_pointer)
        {

            flying_pointer = flying_pointer->next; //Recorrer atravez de los punteros hasta la penultima posicion
        }
        delete flying_pointer->next; //Libera la memoria
        flying_pointer->next = nullptr; //Asignar el ultimo puntero a nulo
        tail_pointer = flying_pointer; //Asignar el ultimo puntero como el ultimo puntero
    }
}


template<typename T>
void utec::LinkedList<T>::pop_front() //Quitar el primer elemento
{
    if (head_pointer == tail_pointer) //Si la lista tiene un elemento
    {
        head_pointer = nullptr; //eliminar y apuntar a nullptr
        tail_pointer = nullptr;
        longitud = 0;
    }
    else
    {
        longitud--;
        utec::Node<T>* flying_pointer = head_pointer;
        head_pointer = head_pointer->next; //Asignar el segundo elemento como el primero
        delete flying_pointer; //Libera la memoria
    }
}


template<typename T>
void utec::LinkedList<T>::push_back(T element) //Insertar elemento al final
{
    longitud++;
    tail_pointer->next = new Node<T>{element}; //Apuntar el elemento en el final a un nuevo elemento
    tail_pointer = tail_pointer->next; //Asignar ese elemento como el final
}


template<typename T>
void utec::LinkedList<T>::push_front(T element) //Insertar elemento al principio
{
    longitud++;
    utec::Node<T>* bridge = head_pointer;
    head_pointer = new Node<T>{element, bridge}; //Asignar el elemento del principio a un nuevo elemento que este apuntando al que era el del inicio
}


template<typename T>
void utec::LinkedList<T>::insert(T element, size_t index) //Insertar elemento
{
    if (index >= 0 && index < longitud)
    {
        longitud++;
        utec::Node<T>* flying_pointer = head_pointer; //Crear un puntero volando sobre la lista
        for (size_t counter = 0;counter < index; counter++)
        {
            flying_pointer = flying_pointer->next; //recorrer hasta llegar al indice
        }
        flying_pointer->next =  new utec::Node<T>{element, flying_pointer->next}; //Apuntar el indice a un nuevo nodo que apunta al elemento que estaba en su lugar
    }
}


template<typename T>
void utec::LinkedList<T>::erase(size_t index) //Eliminar un elemento
{
    if (index >= 0 && index < longitud)
    {
        longitud--;
        if (head_pointer == tail_pointer) //Si la lista tiene un solo elemento
        {
            delete head_pointer; //Eliminar y apuntar a null
            head_pointer = nullptr;
            tail_pointer = nullptr;
            longitud = 0;
        }
        else
        {
            utec::Node<T>* flying_pointer = head_pointer;

            for (size_t counter = 0;counter < index; counter++)
            {
                flying_pointer = flying_pointer->next; //recorrer hasta llegar al indice
            }
            utec::Node<T>* puente = flying_pointer->next->next; //Construye un puente que salte a travez de lo que vaz a borrar
            delete flying_pointer->next; //Borralo
            flying_pointer->next = puente; //Usa el puente para conectarlos de nuevo
        }
    }
}


template<typename T>
void utec::LinkedList<T>::cout_list() //Imprime los elementos en la lista (para debugear)
{
    utec::Node<T>* flying_pointer = head_pointer; //Asgina un puntero que flote sobre la lista
    while(flying_pointer != nullptr) //mientras que el puntero no sea el final
    {
        std::cout << flying_pointer->value << " "; //Imprime el valor del puntero
        flying_pointer = flying_pointer->next; //asigna el puntero al siguiente en la lista
    }
}

template<typename T>
T utec::LinkedList<T>::item(size_t index) //Retornar el item en el index
{
    utec::Node<T>* flying_pointer = head_pointer;
    for (size_t counter = 0;counter < index; counter++)
    {
        flying_pointer = flying_pointer->next; //recorrer hasta llegar al indice
    }
    return flying_pointer->value;
}

template<typename T>
size_t utec::LinkedList<T>::size() const
{
    return longitud;
}



