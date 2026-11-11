#include "generator.h"
#include "card.h"
#include "json.h"
#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

Tools::CardGenerator::CardGenerator(){
    int choice = 0;

    do {
        // Menu
        cout << "\n=====================\n";
        cout << "Card Generator Tool\n";
        cout << "=====================\n";
        cout << "1. Create a card.\n";
        cout << "2. Show cards from pile.\n";
        cout << "3. Exit.\n";
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
            case 1: {
                int type = 0;
                string name = "default_name";

                // Ask for the name
                cout << "\nWhat is the name of your Card?\n";
                cout << "Name (in string) : ";
                cin >> name;

                // Ask for the type
                cout << "\nWhat is the type of your card?";
                cout << "\n1 | doree";
                cout << "\n2 | objective";
                cout << "\n3 | ressource";
                cout << "\nType (in INT) : ";
                cin >> type;

                while (type != 1 && type != 2 && type != 3){
                    // Valeur invalide
                    cin.clear();
                    cin.ignore(100000, '\n');
                    type = 0;

                    cout << "!! Invalid choice. Type (in int) : ";
                    cin >> type;
                }

                // Different cases in relation to the type of the card
                switch (type){
                    // Case of an Doree Card
                    case 1:{
                
                        break;
                    }

                    // Case of an Objective Card
                    case 2:{
                        // Ask for the ressource needed for the score
                        int ressource = 1;
                        cout << "\nWhat is the ressource needed for the card to give a score?";
                        cout << "\n1 | Empty";
                        cout << "\n2 | Mushroom";
                        cout << "\n3 | Insect";
                        cout << "\n4 | Plant";
                        cout << "\n5 | Ink";
                        cout << "\n6 | Feather";
                        cout << "\n7 | Tome";
                        cout << "\nRessource (in int) (Empty by default) : ";
                        cin >> ressource;

                        while (ressource != 1 && ressource != 2 && ressource != 3 & ressource != 4 && ressource != 5 & ressource != 6 && ressource != 7){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            ressource = 0;

                            cout << "!! Invalid choice. Ressource (in int) (Empty by default) : ";
                            cin >> ressource;
                        }

                        // Ask for the score
                        int score = 0;
                        cout << "\nFor each ressource on the board, how many score does the card give?";
                        cout << "\nScore (in int) : ";
                        cin >> score;

                        while (!(cin >> score)){
                            // Valeur invalide
                            cin.clear();
                            cin.ignore(100000, '\n');
                            score = 0;

                            cout << "!! Invalid choice. Score (in int) : ";
                        }

                        // Creation of the object card and the Json

                        Core::ObjectiveCard new_card(QString::fromStdString(name),
                                                    Core::ScoreConditionWithObject(score,static_cast<Utils::Ressource>(ressource)));

                        Json::JsonHandler::getInstance()->WriteCard(new_card,QString::fromStdString(name), "objectives");

                        cout << "\nCard "<<name<<" created successfully! Returning to menu...\n";

                        break;
                    }
                    case 3:{
                        break;
                    }
                }

                break;
            }
            case 2:
                break;
            case 3:
                cout << "Closing Card Generator Tool...";
                break;
        }

    } while (choice != 3);
}