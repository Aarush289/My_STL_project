#include "iitm.h"
#include "Dual.h"
#include "B.tech.h"
#include <algorithm>
#include <iostream>

IITM::IITM() : students(), faculty() {}
bool IITM::check() {
    for (const auto& i : guideCount) {
        if (i.second > 2) { return false; }
    }
    for (const auto& i : TAguideCount) {
        if (i.second > 5) { return false; }
    }
    for (const auto& i : DDPguideCount) {
        if (i.second > 2) { return false; }
    }
    return true;
}
float IITM::percent() {
    float count = 0;
    for (Student* s : students) {
        if (!s->if_btech()) {
            Dual* b = dynamic_cast<Dual*>(s);
            if (b->getDDPGuide() == b->getTASupervisor()) { count++; }
        }
    }
    return (count / students.size()) * 100;
}
void IITM::printroll() {
    std::sort(students.begin(), students.end(), [](Student* a, Student* b) {
        return a->getroll() > b->getroll();  // high to low
    });
}
void IITM::printfacad() {
    std::sort(students.begin(), students.end(), [](Student* a, Student* b) {
        return a->getFacad() > b->getFacad();  // high to low
    });
}
void IITM::printhostel() {
    std::sort(students.begin(), students.end(), [](Student* a, Student* b) {
        return a->getHostel() > b->getHostel();  // high to low
    });
}

void IITM::noguide() {
    for (Student* s : students) {
        if (s->if_btech()) {
            BTech* b = dynamic_cast<BTech*>(s);
            if (b->getBTPGuide() == nullptr) { std::cout << b->getroll() << std::endl; }
        } else {
            Dual* b = dynamic_cast<Dual*>(s);
            if (b->getDDPGuide() == nullptr) { std::cout << b->getroll() << std::endl; }
        }
    }
}
// End of iitm.cpp