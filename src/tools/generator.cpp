#include "generator.h"
#include "card.h"
#include <iostream>
#include <cstdio>
using namespace std;

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
        cout << "4. Exit.\n";
        cout << "Type the number of your choice : ";

        cin >> choice;

        while (choice != 1 && choice != 2 && choice != 3 && choice != 4){
            // Valeur invalide
            cin.clear();
            cin.ignore(100000, '\n');
            choice = 0;

            cout << "!! Invalid choice. Type the number of your choice : ";
            cin >> choice;
        }

        switch (choice){
            case 1:
                break;
            case 2: {
                string choice_delete;
                
                Loader::CardDatabase* database = Loader::CardDatabase::getInstance();
                int i = 1;
                for(auto c : database->getCardsRessources()){
                    qInfo() << (int)c->getDomaine() << " | " << "Nom : " << c->getName();
                }

                cout << "\nTapez le nom de la carte à supprimer : ";
                cin >> choice_delete;

                string path = "../assets/ressources/" + choice_delete + ".json";

                int returnCode = remove(path.c_str());
                if (returnCode != 0) {
                    fprintf( stderr, "Error: cannot remove the file.\n" );
                }
                else{
                    cout << "Card successfully deleted!\n";
                }
                break; // Problème, la carte est toujours visible dans la base de données
            }
            case 3:
                break;
            case 4:
                cout << "Closing Card Generator Tool...";
                break;
        }

    } while (choice != 4);
}