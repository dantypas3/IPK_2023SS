#include <iostream>

int main() {
    int value = 5;
    //int& ref_int;         // error: ‘ref_int’ declared as reference but not initialized
    int& ref_int = value;   // referenzen müssen direkt initialisiert werden

    std::cout << "un-initialisierter Pointer" << std::endl;
    int* point_int;         // pointer müssen nicht direkt initialisiert werden
    std::cout << "Zeigt auf Adresse " << point_int << std::endl;
    std::cout << "mit dem Wert " << *point_int << std::endl;
    // sie zeigen dann aber auf irgendeine Adresse

    std::cout << "\nnull Pointer" << std::endl;
    point_int = nullptr;    // besser man weißt ihnen direkt eine Adresse zu oder den nullpointer auf die Adresse 0
    std::cout << "Zeigt auf Adresse " << point_int << std::endl;
    //std::cout << "mit dem Wert " << *point_int << std::endl;        // wir können aber nicht den Wert abfragen
    // und segmentation faults kann (sollte) man nicht mit einer try-catch behandeln        https://stackoverflow.com/a/53436496
    
    // wir können aber die Adresse abfragen und dementsprechend handeln
    if(point_int != nullptr) {
        std::cout << "mit dem Wert " << *point_int << std::endl;
    }
    else {
        std::cout << "nullptr, kein Wert" << std::endl;
    }

    std::cout << "\nPointer auf value" << std::endl;
    // um den Pointer auf eine andere Adresse zeigen zu lassen, benötigen wir & vor der Variable
    point_int = &value;
    std::cout << "Zeigt auf Adresse " << point_int << std::endl;
    std::cout << "mit dem Wert " << *point_int << std::endl;

    std::cout << "\nPointer in den Heap" << std::endl;
    // wir können auch eine Variable im Heap anlegen und darauf Zeigen
    point_int = new int;
    std::cout << "Zeigt auf Adresse " << point_int << std::endl;
    // um der Variable einen Neuen Wert zuzuweisen müssen wir mit *<ptr_name> sagen, das wir nicht die Adresse sondern den Wert bearbeiten wollen
    // wir dereferenzeiren den Pointer
    *point_int = 5;
    std::cout << "mit dem Wert " << *point_int << std::endl;

    std::cout << "\nPointer in den Heap 2" << std::endl;
    // und anlegen eines neuen ints im Heap
    point_int = new int;
    std::cout << "Zeigt auf Adresse " << point_int << std::endl;
    std::cout << "mit dem Wert " << *point_int << std::endl;
}