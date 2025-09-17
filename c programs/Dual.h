#ifndef DUAL_H
#define DUAL_H
#include <iostream>
#include <string>
#include "student.h"
#include "faculty.h"

class Dual : public Student{
    private:
        Faculty* DDPGuide;
        Faculty* TA;
    public:

    Dual(std::string r, std::string h, float c, Faculty* f);
        Faculty* getDDPGuide();
        Faculty* getTASupervisor();
        void setDDPGuide(Faculty* f);
        void setTA(Faculty* f);

        void printInfo() const override ;
};
#endif // DUAL_H