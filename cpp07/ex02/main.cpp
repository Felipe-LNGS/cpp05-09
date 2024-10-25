#include <iostream>
#include <cstdlib>
#include "Array.hpp"


int main() {
    try {
        // Création et test avec int
        Array<int> intArray(5);
        for (std::size_t i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 10;
        }
        std::cout << "Contenu de intArray : ";
        for (std::size_t i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Test de l'exception d'accès hors limites
        try {
            std::cout << "Accès à l'index 10 dans intArray : " << intArray[10] << std::endl;
        } catch (const Array<int>::IndexOutOfBounds& e) {
            std::cerr << e.what();
        }

        // Création et test avec char
        Array<char> charArray(5);
        for (std::size_t i = 0; i < charArray.size(); i++) {
            charArray[i] = 'A' + i;
        }
        std::cout << "Contenu de charArray : ";
        for (std::size_t i = 0; i < charArray.size(); i++) {
            std::cout << charArray[i] << " ";
        }
        std::cout << std::endl;

        // Test de copie profonde
        Array<int> intArrayCopy = intArray;  // Utilisation du constructeur de copie profonde
        intArray[0] = 999; // Modification de intArray sans affecter intArrayCopy
        std::cout << "Contenu de intArray après modification : ";
        for (std::size_t i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Contenu de intArrayCopy (doit être inchangé) : ";
        for (std::size_t i = 0; i < intArrayCopy.size(); i++) {
            std::cout << intArrayCopy[i] << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Erreur inattendue : " << e.what() << std::endl;
    }

    return 0;
}
