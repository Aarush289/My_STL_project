#include "Dual.h"
Dual:: Dual(std::string r, std::string h, float c, Faculty* f)
    : Student(r, h, c, f,0), DDPGuide(nullptr),TA(nullptr) {}
Faculty* Dual:: getDDPGuide(){return DDPGuide;}
Faculty* Dual:: getTASupervisor(){return TA;}
void Dual:: setDDPGuide(Faculty* f){DDPGuide = f;}
void Dual:: setTA(Faculty* f){TA = f;}
void Dual::printInfo() const {
    std::cout << "Dual Student: " << rollNumber << " CGPA: " << cgpa << std::endl;
}
