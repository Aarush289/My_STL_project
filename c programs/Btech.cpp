#include "BTech.h"


BTech:: BTech(std::string r, std::string h, float c, Faculty* f)
    : Student(r, h, c, f,1), BTPGuide(nullptr) {}
  Faculty* BTech:: getBTPGuide(){return BTPGuide;}
void BTech:: setBTPGuide(Faculty* f){BTPGuide =f;}
void BTech::printInfo() const  {
            std::cout << "BTech Student: " << rollNumber << " CGPA: " << cgpa << std::endl;
        }