#include "student.h"
   
Student::  Student(std::string r, std::string h,float c, Faculty* f , bool u) 
            : rollNumber(r), hostel(h), cgpa(c), facad(f) ,btech(u) {}
    
Student::   ~Student() = default;
    
std::string Student:: getHostel() const { return hostel; }
std::string Student::getroll()const { return rollNumber;}
float Student:: getCGPA() const{return cgpa;}
Faculty* Student::getFacad() const { return facad; }
void Student::changeHostel(const std::string& newHostel) { hostel = newHostel; }
bool Student::if_btech(){return btech;}
