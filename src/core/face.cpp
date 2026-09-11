#include "core.h"
#include <iostream>
#include "utils.h"

using namespace std;

Face::Face(FaceType face_type) : face_type(face_type) {
    cout << "Face créer sur le côté " << static_cast<int>(face_type) << endl;
}

Face::Face() : face_type(FaceType::RECTO) {

}

FaceType Face::getFaceType() const {
    return face_type;
}