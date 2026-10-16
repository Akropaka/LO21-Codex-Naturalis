#pragma once
#include "utils.h"

/**
 * @class Face
 * @brief Represents a face of a card, which can be either RECTO or VERSO.
 */
class Face {
    private:
        FaceType face_type;
    public:
        Face(FaceType face_type);
        Face();
        FaceType getFaceType() const;
};