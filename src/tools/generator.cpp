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
        cout << "2. Show cards from pile. (*not implemented yet*)\n";
        cout << "3. Exit.\n";
        cout << "Type the number of your choice : ";

        while (!(cin >> choice) || choice != 1 && choice != 2 && choice != 3){
            // Invalid value
            cin.clear();
            cin.ignore(100000, '\n');
            choice = 0;

            cout << "!! Invalid choice. Type the number of your choice : ";
        }

        switch (choice){
            case 1: {
                int type = 0;
                string name = "default_name";

                // Ask for the name
                cout << "\n=====================\n";
                cout << "What is the name of your Card?\n";
                cout << "Name (in string) : ";
                cin >> name;

                // Ask for the type
                cout << "\nWhat is the type of your card?";
                cout << "\n1 | Gold";
                cout << "\n2 | Objective (not fully implemented yet)";
                cout << "\n3 | Resource";
                cout << "\nType (in int) : ";

                while (!(cin >> type) || type != 1 && type != 2 && type != 3){
                    // Invalid value
                    cin.clear();
                    cin.ignore(100000, '\n');
                    type = 0;

                    cout << "!! Invalid choice. Type (in int) : ";
                }

                // Different cases in relation to the type of the card
                switch (type){
                    // Case of a Gold Card
                    case 1:{
                        // Ask for the kingdom
                        int kingdom = 0;
                        cout << "\nWhat is the kingdom of the card (Ressource at the back of the card)?";
                        cout << "\n0 | Fungi";
                        cout << "\n1 | Animal";
                        cout << "\n2 | Insect";
                        cout << "\n3 | Plant";
                        cout << "\nKingdom (in int) : ";
                        
                        while (!(cin >> kingdom) || kingdom != 1 && kingdom != 2 && kingdom != 3 && kingdom != 0){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            kingdom = 0;

                            cout << "!! Invalid choice. Kingdom (in int) : ";
                        }

                        // Ask for the corner, creation of the front part of the card
                        int topleft = 0;
                        int topright = 0;
                        int bottomleft = 0;
                        int bottomright = 0;

                        cout << "\n0 | Empty";
                        cout << "\n1 | Fungi";
                        cout << "\n2 | Animal";
                        cout << "\n3 | Insect";
                        cout << "\n4 | Plant";
                        cout << "\n5 | Inkwell";
                        cout << "\n6 | Quill";
                        cout << "\n7 | Manuscript";
                        cout << "\n8 | Hidden (the corner is 'filled')";

                        cout << "\nWhat is the Ressource at the TopLeft of the card? Type here (in int) : ";

                        while (!(cin >> topleft) || topleft != 0 && topleft != 1 && topleft != 2 && topleft != 3 && topleft != 4 && topleft != 5 && topleft != 6 && topleft != 7 && topleft != 8){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            topleft = 0;

                            cout << "!! Invalid choice. TopLeft : ";
                        }

                        cout << "\nWhat is the Ressource at the TopRight of the card? Type here (in int) : ";

                        while (!(cin >> topright) || topright != 0 && topright != 1 && topright != 2 && topright != 3 & topright != 4 && topright != 5 & topright != 6 && topright != 7 && topright != 8){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            topright = 0;

                            cout << "!! Invalid choice. TopRight : ";
                        }

                        cout << "\nWhat is the Ressource at the BottomLeft of the card? Type here (in int) : ";

                        while (!(cin >> bottomleft) || bottomleft != 0 && bottomleft != 1 && bottomleft != 2 && bottomleft != 3 & bottomleft != 4 && bottomleft != 5 & bottomleft != 6 && bottomleft != 7 && bottomleft != 8){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            bottomleft = 0;

                            cout << "!! Invalid choice. BottomLeft : ";
                        }

                        cout << "\nWhat is the Ressource at the BottomRight of the card? Type here (in int) : ";

                        while (!(cin >> bottomright) || bottomright != 0 && bottomright != 1 && bottomright != 2 && bottomright != 3 & bottomright != 4 && bottomright != 5 & bottomright != 6 && bottomright != 7 && bottomright != 8){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            bottomright = 0;

                            cout << "!! Invalid choice. BottomRight : ";
                        }

                        // Ask for the number of Ressources needed for each type

                        int fungi = 0;
                        int animal = 0;
                        int insect = 0;
                        int plant = 0;
                        int inkwell = 0;
                        int quill = 0;
                        int manuscript = 0;
                        int resource = 0;
                        
                        cout << "\nEach gold card needs a certain number of Ressources for each type to be played.";
                        cout << "\nFor each type, enter the right requirement (0 if the Ressource type is not needed) :";
                        
                        cout << "\nFungi : ";
                        while (!(cin >> fungi) || fungi < 0){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            fungi = 0;

                            cout << "!! Invalid choice. Fungi : ";
                        }

                        cout << "Animal : ";
                        while (!(cin >> animal) || animal < 0){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            animal = 0;

                            cout << "!! Invalid choice. Animal : ";
                        }

                        cout << "Insect : ";
                        while (!(cin >> insect) || insect < 0){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            insect = 0;

                            cout << "!! Invalid choice. Insect : ";
                        }

                        cout << "Plant : ";
                        while (!(cin >> plant) || plant < 0){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            plant = 0;

                            cout << "!! Invalid choice. Plant : ";
                        }

                        cout << "Inkwell : ";
                        while (!(cin >> inkwell) || inkwell < 0){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            inkwell = 0;

                            cout << "!! Invalid choice. Inkwell : ";
                        }

                        cout << "Quill : ";
                        while (!(cin >> quill) || quill < 0){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            quill = 0;

                            cout << "!! Invalid choice. Quill : ";
                        }

                        cout << "Manuscript : ";
                        while (!(cin >> manuscript) || manuscript < 0){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            manuscript = 0;

                            cout << "!! Invalid choice. Manuscript : ";
                        }

                        // Ask for the Score Condition
                        int scoreCondition = 0;
                        cout << "The number of points given can be linked to a certain condition. What is the condition you want for your card?";
                        cout << "\n0 : No condition. It just gives the score when played on the board.";
                        cout << "\n1 : For each resource of my choice, it gives score.";
                        cout << "\n2 : For each corner covered by my card, it gives score.";
                        cout << "\nCondition (in int) : ";
                        while (!(cin >> scoreCondition) || scoreCondition != 0 && scoreCondition != 1 && scoreCondition != 2){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            scoreCondition = 0;

                            cout << "!! Invalid choice. Retry : ";
                        }
                        
                        // Asking for the score
                        
                        int score = 0;
                        cout << "\nHow many points does the card give when the condition is met (or when just played)?";
                        cout << "\nNumber of points (in int) : ";

                        while (!(cin >> score) || score <= 0){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            score = 0;

                            cout << "!! Invalid choice. Number of points (in int) : ";
                        }

                        // Creating the front of the card

                        Core::FaceWithCondition front;

                    
                        // Case 0 : No condition for the score
                        if (scoreCondition == 0){
                            front = Core::FaceWithCondition(score);
                        }

                        // Case 1 : Gives score for each ressource
                        if (scoreCondition == 1){
                            
                            cout << "For each resource on the board, the card gives score. What resource?";
                            cout << "\n5 | Inkwell";
                            cout << "\n6 | Quill";
                            cout << "\n7 | Manuscript";
                            cout << "\nResource (in int) :";

                            while (!(cin >> resource) || resource != 5 && resource != 6 && resource != 7){
                                // Invalid value
                                cin.clear();
                                cin.ignore(100000, '\n');
                                resource = 0;

                                cout << "!! Invalid choice. Resource (in int) : ";
                            }

                            front.ModifyScoreCondition<Core::ScoreConditionWithObject>(Core::ScoreConditionWithObject(score,static_cast<Utils::Ressource>(resource)));
                        }

                        // Case 2 : Gives score for each corner covered
                        if (scoreCondition == 2){
                            front.ModifyScoreCondition<Core::ScoreConditionWithBorder>(score);

                        }

                        // Il manque à faire en fonction du pattern
                        
                        // Requirements for the cards to be played

                        if (fungi != 0){
                            front.AddCondition(fungi, Utils::Ressource::Champignon);
                        }

                        if (animal != 0){
                            front.AddCondition(animal, Utils::Ressource::Animal);
                        }

                        if (insect != 0){
                            front.AddCondition(insect, Utils::Ressource::Insecte);
                        }

                        if (plant != 0){
                            front.AddCondition(plant, Utils::Ressource::Vegetal);
                        }

                        if (inkwell != 0){
                            front.AddCondition(inkwell, Utils::Ressource::Ink);
                        }

                        if (quill != 0){
                            front.AddCondition(quill, Utils::Ressource::Feather);
                        }

                        if (manuscript != 0){
                            front.AddCondition(manuscript, Utils::Ressource::Tome);
                        }

                        // Creation of the corners
                        
                        if (topleft != 8){
                            front.AddSlot(Utils::SlotPosition::TopLeft,static_cast<Utils::Ressource>(topleft));
                        }

                        if (topright != 8){
                            front.AddSlot(Utils::SlotPosition::TopRight,static_cast<Utils::Ressource>(topright));
                        }

                        if (bottomleft != 8){
                            front.AddSlot(Utils::SlotPosition::BottomLeft,static_cast<Utils::Ressource>(bottomleft));
                        }

                        if (bottomright != 8){
                            front.AddSlot(Utils::SlotPosition::BottomRight,static_cast<Utils::Ressource>(bottomright));
                        }

                        // Creates the card
                        Core::GoldenCard new_card(QString::fromStdString(name),
                                                      static_cast<Utils::Domaine>(kingdom),front);
            
                        Json::JsonHandler::getInstance()->WriteCard(new_card,QString::fromStdString(name), "doree");

                        cout << "\nCard "<<name<<" created successfully! Returning to menu...\n";
                        
                        break;
                    }

                    // Case of an Objective Card
                    case 2:{
                        // Ask for the kingdom/object needed for the score
                        int Ressource = 0;
                        cout << "\nWhat is the kingdom/object needed for the card to give points?";
                        cout << "\n1 | Fungi";
                        cout << "\n2 | Animal";
                        cout << "\n3 | Insect";
                        cout << "\n4 | Plant";
                        cout << "\n5 | Inkwell";
                        cout << "\n6 | Quill";
                        cout << "\n7 | Manuscript";
                        cout << "\nKingdom/Object (in int) : ";

                        while (!(cin >> Ressource) || Ressource != 1 && Ressource != 2 && Ressource != 3 && Ressource != 4 && Ressource != 5 && Ressource != 6 && Ressource != 7){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            Ressource = 0;

                            cout << "!! Invalid choice. Kingdom/Object (in int) : ";
                        }

                        // Ask for the score
                        int score = 0;
                        cout << "\nHow many points does the card give for each of this kingdom/object on the board?";
                        cout << "\nNumber of points (in int) : ";

                        while (!(cin >> score) || score <= 0){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');

                            cout << "!! Invalid choice. Number of points (in int) : ";
                        }

                        // Create the object card and the Json

                        Core::ObjectiveCard new_card(QString::fromStdString(name),
                                                    Core::ScoreConditionWithObject(score,static_cast<Utils::Ressource>(Ressource)));

                        Json::JsonHandler::getInstance()->WriteCard(new_card,QString::fromStdString(name), "objectives");

                        cout << "\nCard "<<name<<" created successfully! Returning to menu...\n";

                        break;
                    }

                    // Case of a Resource Card
                    case 3:{
                        // Ask for the kingdom
                        int kingdom = 0;
                        cout << "\nWhat is the kingdom of the card (Ressource at the back of the card)?";
                        cout << "\n0 | Fungi";
                        cout << "\n1 | Animal";
                        cout << "\n2 | Insect";
                        cout << "\n3 | Plant";
                        cout << "\nKingdom (in int) (Empty by default) : ";
                        
                        while (!(cin >> kingdom) || kingdom != 1 && kingdom != 2 && kingdom != 3 && kingdom != 0){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            kingdom = 0;

                            cout << "!! Invalid choice. Kingdom (in int) (Empty by default) : ";
                        }

                        // Ask for the corner, creation of the front part of the card
                        int topleft = 0;
                        int topright = 0;
                        int bottomleft = 0;
                        int bottomright = 0;

                        cout << "\n0 | Empty";
                        cout << "\n1 | Fungi";
                        cout << "\n2 | Animal";
                        cout << "\n3 | Insect";
                        cout << "\n4 | Plant";
                        cout << "\n5 | Inkwell";
                        cout << "\n6 | Quill";
                        cout << "\n7 | Manuscript";
                        cout << "\n8 | Hidden (the corner is 'filled')";

                        cout << "\nReminder : for the resource card, at least one of the corner must have the same Ressource as the kingdom of the card.\n";
                        cout << "\nWhat is the resource at the TopLeft of the card? Type here (in int) : ";

                        while (!(cin >> topleft) || topleft != 0 && topleft != 1 && topleft != 2 && topleft != 3 && topleft != 4 && topleft != 5 && topleft != 6 && topleft != 7 && topleft != 8){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            topleft = 0;

                            cout << "!! Invalid choice. TopLeft : ";
                        }

                        cout << "\nWhat is the resource at the TopRight of the card? Type here (in int) : ";

                        while (!(cin >> topright) || topright != 0 && topright != 1 && topright != 2 && topright != 3 && topright != 4 && topright != 5 && topright != 6 && topright != 7 && topright != 8){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            topright = 0;

                            cout << "!! Invalid choice. TopRight : ";
                        }

                        cout << "\nWhat is the resource at the BottomLeft of the card? Type here (in int) : ";

                        while (!(cin >> bottomleft) || bottomleft != 0 && bottomleft != 1 && bottomleft != 2 && bottomleft != 3 & bottomleft != 4 && bottomleft != 5 & bottomleft != 6 && bottomleft != 7 && bottomleft != 8){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            bottomleft = 0;

                            cout << "!! Invalid choice. BottomLeft : ";
                        }

                        cout << "\nWhat is the resource at the BottomRight of the card? Type here (in int) : ";

                        while (!(cin >> bottomright) || bottomright != 0 && bottomright != 1 && bottomright != 2 && bottomright != 3 & bottomright != 4 && bottomright != 5 & bottomright != 6 && bottomright != 7 && bottomright != 8){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            bottomright = 0;

                            cout << "!! Invalid choice. BottomRight : ";
                        }
                        

                        while (topleft != kingdom+1 && topright != kingdom+1 && bottomleft != kingdom+1 && bottomright != kingdom+1){
                            cout << "!! No corner is the same type as the kingdom of the card. Try again.";
                            topleft = 0;
                            topright = 0;
                            bottomleft = 0;
                            bottomright = 0;

                            cout << "\n0 | Empty";
                            cout << "\n1 | Fungi";
                            cout << "\n2 | Animal";
                            cout << "\n3 | Insect";
                            cout << "\n4 | Plant";
                            cout << "\n5 | Inkwell";
                            cout << "\n6 | Quill";
                            cout << "\n7 | Manuscript";
                            cout << "\n8 | Hidden (the corner is 'filled')";

                            cout << "\nReminder : for the resource card, at least one of the corner must have the same Ressource as the kingdom of the card.\n";
                            cout << "\nWhat is the resource at the TopLeft of the card? Type here (in int) : ";
                            while (!(cin >> topleft) || topleft != 0 && topleft != 1 && topleft != 2 && topleft != 3 & topleft != 4 && topleft != 5 & topleft != 6 && topleft != 7 && topleft != 8){
                                // Invalid value
                                cin.clear();
                                cin.ignore(100000, '\n');
                                topleft = 0;

                                cout << "!! Invalid choice. TopLeft : ";
                            }

                            cout << "\nWhat is the resource at the TopRight of the card? Type here (in int) : ";

                            while (!(cin >> topright) || topright != 0 && topright != 1 && topright != 2 && topright != 3 & topright != 4 && topright != 5 & topright != 6 && topright != 7 && topright != 8){
                                // Invalid value
                                cin.clear();
                                cin.ignore(100000, '\n');
                                topright = 0;

                                cout << "!! Invalid choice. TopRight : ";
                            }

                            cout << "\nWhat is the resource at the BottomLeft of the card? Type here (in int) : ";

                            while (!(cin >> bottomleft) || bottomleft != 0 && bottomleft != 1 && bottomleft != 2 && bottomleft != 3 & bottomleft != 4 && bottomleft != 5 & bottomleft != 6 && bottomleft != 7 && bottomleft != 8){
                                // Invalid value
                                cin.clear();
                                cin.ignore(100000, '\n');
                                bottomleft = 0;

                                cout << "!! Invalid choice. BottomLeft : ";
                            }

                            cout << "\nWhat is the resource at the BottomRight of the card? Type here (in int) : ";

                            while (!(cin >> bottomright) || bottomright != 0 && bottomright != 1 && bottomright != 2 && bottomright != 3 & bottomright != 4 && bottomright != 5 & bottomright != 6 && bottomright != 7 && bottomright != 8){
                                // Invalid value
                                cin.clear();
                                cin.ignore(100000, '\n');
                                bottomright = 0;

                                cout << "!! Invalid choice. BottomRight : ";
                            }
                        }

                        int score = 0;
                        cout << "\nHow many points does the card give when played on the board? If it doesn't give points, leave 0.";
                        cout << "\nNumber of points (in int) : ";

                        while (!(cin >> score) || score < 0){
                            // Invalid value
                            cin.clear();
                            cin.ignore(100000, '\n');
                            score = 0;

                            cout << "!! Invalid choice. Number of points (in int) : ";
                        }

                        // Creating the front of the card

                        Core::Face front;

                        if (score != 0){
                            front = Core::Face(score);
                        }
                        
                        if (topleft != 8){
                            front.AddSlot(Utils::SlotPosition::TopLeft,static_cast<Utils::Ressource>(topleft));
                        }

                        if (topright != 8){
                            front.AddSlot(Utils::SlotPosition::TopRight,static_cast<Utils::Ressource>(topright));
                        }

                        if (bottomleft != 8){
                            front.AddSlot(Utils::SlotPosition::BottomLeft,static_cast<Utils::Ressource>(bottomleft));
                        }

                        if (bottomright != 8){
                            front.AddSlot(Utils::SlotPosition::BottomRight,static_cast<Utils::Ressource>(bottomright));
                        }

                        // Create the card
                        Core::RessourceCard new_card(QString::fromStdString(name),
                                                    static_cast<Utils::Domaine>(kingdom),front);
            
                        Json::JsonHandler::getInstance()->WriteCard(new_card,QString::fromStdString(name), "ressources");

                        cout << "\nCard "<<name<<" created successfully! Returning to menu...\n";
                        
                        break;
                    }
                }

                break;
            }
            case 2:
                break;
            case 3:
                cout << "Closing Card Generator Tool...\n";
                break;
        }

    } while (choice != 3);
}