#include "core/card.h"
#include "core/face.h"
#include <iostream>
#include "utils.h"

using namespace std;

/**
 * @brief Constructor for the Face class.
 * @param face_type The type of the face (RECTO or VERSO).
 */
Face::Face(FaceType face_type) : face_type(face_type) {
    cout << "Face créer sur le côté " << static_cast<int>(face_type) << endl;
}

/**
 * @brief Default constructor for the Face class.
 * Initializes the face as RECTO by default.
 */
Face::Face() : face_type(FaceType::RECTO) {

}

/**
 * @brief Getter for the face type of the face.
 * @return The type of the face (RECTO or VERSO).
 */
FaceType Face::getFaceType() const {
    return face_type;
}