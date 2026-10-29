#include "generator.h"

Tools::CardGenerator::CardGenerator(){
    int choice = 0;

    do {
        // Affichage du menu
        cout << "\n=====================\n";
        cout << "Card Generator Tool\n";
        cout << "=====================\n";
        cout << "1. Create a card.\n";
        cout << "2. Delete a card.\n";
        cout << "3. Show cards from pile.\n";
        cout << "4. Exit.\n"
        cout << "Type the number of your choice : ";

        cin >> choice;

        if (cin.fail()){
            cin.clear();
            choice = 0;
        }

    } while (choice != 4);
}