#ifndef IITM_H
#define IITM_H

#include <vector>
#include <unordered_map>
#include "student.h"
#include "faculty.h"

class IITM {
    

public:
    std::unordered_map<Faculty*, int> guideCount;
    std::unordered_map<Faculty*, int> DDPguideCount;
    std::unordered_map<Faculty*, int> TAguideCount;
    std::vector<Student*> students;
    std::vector<Faculty*> faculty;

    IITM();

    bool check();
    float percent();
    void printroll();
    void printfacad();
    void printhostel();
    void noguide();

};

#endif
