#ifndef BTECH_H
#define BTECH_H
#include "student.h"
#include "faculty.h"
#include<iostream>

class BTech : public Student{
    private:
        Faculty* BTPGuide;
    public:
    BTech(std::string r,std:: string h, float c, Faculty* f);
        Faculty* getBTPGuide();
        void setBTPGuide(Faculty* f);
        void printInfo() const override ;
};

#endif // BTECH_H