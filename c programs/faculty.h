#ifndef FACULTY_H
#define FACULTY_H
#include <string>

class Faculty{
    private:
        std::string name;
        bool per;
    public:
        Faculty();
        Faculty(std::string s,bool fac);
        std:: string getName() const ;
        bool isPermanent() const ;
};

#endif