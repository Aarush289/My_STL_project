#include "faculty.h"

Faculty :: Faculty():name("unknown"),per(0){}
Faculty :: Faculty(std :: string s,bool fac):name(s),per(fac){}
std:: string Faculty :: getName() const { return name; }
bool Faculty ::     isPermanent() const {return per;}