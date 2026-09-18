#pragma once
#include "utils.h"

class Face {
    private:
        FaceType face_type;
    public:
        Face(FaceType face_type);
        Face();
        FaceType getFaceType() const;
};