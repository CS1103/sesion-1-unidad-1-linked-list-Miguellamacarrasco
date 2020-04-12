#include "head.cpp"



using namespace std;

int main() {

    utec::LinkedList<int> ll(0);

    // Probar el metodo push_front;
    for(int i = 0; i < 10; ++i) {
        ll.push_front(i);
    }

    ll.cout_list();
    // Verifico el tamano
    assert(ll.size() == 10);

    string result;
    for (int i = 0; i < 10; ++i) {
        result += to_string(ll.item(i)) + " ";
    }
    assert(result == "9 8 7 6 5 4 3 2 1 0 ");

    // pop_front
    // Probar el metodo push_front;
    for(int i = 0; i < 5; ++i) {
        ll.pop_front();
    }
    // Verifico el tamano
    assert(ll.size() == 5);

    // Probar el metodo push_front;
    for(int i = 0; i < 5; ++i) {
        ll.pop_front();
    }
    // Verifico el tamano
    assert(ll.size() == 0);



    std::cout << "Ejecucion exitosa!!" << std::endl;
    return 0;
}
