#ifndef STUDENT_H
#define STUDENT_H
#include <string>

#include "faculty.h"

class Student {
    protected:
        std::string rollNumber;
        std::string hostel;
        Faculty* facad;
        float cgpa;
        bool btech;
    
    public:
        Student(std::string r, std::string h,float c, Faculty* f , bool u) ;
        virtual ~Student() = default;
    
        std::string getHostel() const;
        std::string getroll() const;
        float getCGPA() const;
        Faculty* getFacad() const ;
        void changeHostel(const std:: string& newHostel) ;
        bool if_btech();
        virtual void printInfo() const = 0; // for polymorphism
    };
    
#endif // STUDENT_H