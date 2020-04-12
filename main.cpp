#include "head.cpp"

int main()
{
    utec::LinkedList<int> lista(10);
    lista.insert(5,5);
    lista.erase(6);
    lista.push_back(5);
    lista.pop_front();
    lista.pop_back();
    lista.push_front(2);

    lista.cout_list();

    std::cout << "\n" << "Ejecucion completada precione cualquier tecla para salir";
    getch();
    return 0;
}
