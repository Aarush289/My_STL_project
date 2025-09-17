#include "faculty.h"
#include "iitm.h"
#include "B.tech.h" 
#include "Dual.h"
#include "student.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


int main(){
        IITM iit;
        srand(time(0));
        std::vector<std::string> hostels = {"Ganga", " Mandak" , "Swarna" , " Godavari","Krishna"};
        for(int i=0;i<100;i++){
            std::string prof = "prof"+std::to_string(i+1);
            bool r = rand()%2;
            iit.faculty.push_back(new Faculty(prof,r));
        }
        for(int i=0;i<1e5;i++){
           std:: string roll = "CS24" +std::to_string(i+1) ;
           std:: string hostel = hostels[rand()%hostels.size()];
            float cgpa = 6.0 + static_cast<float>(static_cast<float>(rand())/(RAND_MAX))*4.0;
            Faculty* facad = iit.faculty[rand() % iit.faculty.size()];
            if(rand()%2==0){
                iit.students.push_back(new BTech(roll , hostel , cgpa , facad));
            }
            else{
                iit.students.push_back(new Dual(roll , hostel , cgpa , facad));
            }
        }
       
        std::sort(iit.students.begin(), iit.students.end(), [](Student* a, Student* b) {
            return a->getCGPA() > b->getCGPA();  // high to low
        });
        int j=iit.faculty.size();
        int k=iit.students.size();
        int facindex=0;
        for(Student* s : iit.students){
           
            while((facindex < j && iit.guideCount[iit.faculty[facindex]] ==2 )|| (facindex < j && !iit.faculty[facindex]->isPermanent())){facindex++;}
            if(facindex >= j){break;}
            if(s->if_btech())
            {
                BTech* b=dynamic_cast<BTech*>(s);
                b->setBTPGuide(iit.faculty[facindex]);
                iit.guideCount[iit.faculty[facindex]]++;
            }
        }
        std::sort(iit.students.begin(), iit.students.end(), [](Student* a, Student* b) {
            return (a->getHostel())[0] > (b->getHostel())[0];  // high to low
        });
        facindex=0;
       
        for(Student* s : iit.students){
           
            while((facindex < j && iit.DDPguideCount[iit.faculty[facindex]] ==2 )|| (facindex < j && !iit.faculty[facindex]->isPermanent())){facindex++;}
            if(facindex >= j){break;}
            if(!(s->if_btech()))
            {
                Dual* b=dynamic_cast<Dual*>(s);
                b->setDDPGuide(iit.faculty[facindex]);
                iit.DDPguideCount[iit.faculty[facindex]]++;
            }
        }
        
        int count=0;

        for(Student* s : iit.students){
           int r=rand()%j;
            while(iit.TAguideCount[iit.faculty[r]]>=5){r=rand()%j;}
            if(count == 5*j){break;}
            if(!(s->if_btech()))
            {
                Dual* b=dynamic_cast<Dual*>(s);
                b->setTA(iit.faculty[r]);
                iit.TAguideCount[iit.faculty[r]]++;
                count++;
            }
        }

}