#include <iostream>
#include<exception>
#include <random>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

unordered_map< Faculty* , int> guideCount;
unordered_map<Faculty*,int> DDPguideCount;
unordered_map<Faculty*,int> TAguideCount;
class Faculty{
    private:
        string name;
        bool per;
    public:
        Faculty():name("unknown"),per(0){}
        Faculty(string s,bool fac):name(s),per(fac){}
        string getName() const { return name; }
        bool isPermanent() const {return per;}
};

class Student {
    protected:
        string rollNumber;
        string hostel;
        Faculty* facad;
        float cgpa;
        bool btech;
    
    public:
        Student(std::string r, std::string h,float c, Faculty* f , bool u) 
            : rollNumber(r), hostel(h), cgpa(c), facad(f) ,btech(u) {}
    
        virtual ~Student() = default;
    
        string getHostel() const { return hostel; }
        string getroll()const { return rollNumber;}
        float getCGPA() const{return cgpa;}
        Faculty* getFacad() const { return facad; }
        void changeHostel(const string& newHostel) { hostel = newHostel; }
        bool if_btech(){return btech;}
        virtual void printInfo() const = 0; // for polymorphism
    };
    


class BTech : public Student{
    private:
        Faculty* BTPGuide;
    public:
    BTech(string r, string h, float c, Faculty* f)
    : Student(r, h, c, f,1), BTPGuide(nullptr) {}
        Faculty* getBTPGuide(){return BTPGuide;}
        void setBTPGuide(Faculty* f){BTPGuide =f;}
        void printInfo() const override {
            cout << "BTech Student: " << rollNumber << " CGPA: " << cgpa << endl;
        }
};

class Dual : public Student{
    private:
        Faculty* DDPGuide;
        Faculty* TA;
    public:

    Dual(string r, string h, float c, Faculty* f)
    : Student(r, h, c, f,0), DDPGuide(nullptr),TA(nullptr) {}
        Faculty* getDDPGuide(){return DDPGuide;}
        Faculty* getTASupervisor(){return TA;}
        void setDDPGuide(Faculty* f){DDPGuide = f;}
        void setTA(Faculty* f){TA = f;}

        void printInfo() const override {
            cout << "Dual Student: " << rollNumber << " CGPA: " << cgpa << endl;
        }
};

class IITM{
    public:
        vector<Student*> students;
        vector<Faculty*> faculty;
        IITM():students(),faculty(){}
        bool check(){
            for(const auto& i: guideCount){
                if(i.second>2){return 0;}
            }
            for(const auto& i: TAguideCount){
                if(i.second>5){return 0;}
            }
            for(const auto& i: DDPguideCount){
                if(i.second>2){return 0;}
            }
            return 1;
        }
        
        float percent(){
                float count=0;
                for(Student* s: students){
                    if(!s->if_btech()){
                        Dual* b= dynamic_cast<Dual*>(s);
                        if(b->getDDPGuide()==b->getTASupervisor()){count++;}
                    }
                }
                float per = (count/(1e5))*100;
                return per;
        }
        void printroll(){
            std::sort(students.begin(), students.end(), [](Student* a, Student* b) {
                return a->getroll() > b->getroll();  // high to low
            });
        }
        void printfacad(){
            std::sort(students.begin(), students.end(), [](Student* a, Student* b) {
                return a->getFacad() > b->getFacad();  // high to low
            });
        }
        void printhostel(){
            std::sort(students.begin(), students.end(), [](Student* a, Student* b) {
                return a->getHostel() > b->getHostel();  // high to low
            });
        }
        void noguide(){
            for(Student* s: students){
                if(s->if_btech()){
                    BTech* b=dynamic_cast<BTech*>(s);
                    if(b->getBTPGuide() == nullptr){cout << b->getroll() << endl;}
                }
                else{
                    Dual* b=dynamic_cast<Dual*>(s);
                    if(b->getDDPGuide()== nullptr){cout << b->getroll() << endl;}
                }
            }
            return ;
        }

};

int main(){
        IITM iit;
        srand(time(0));
        vector<string> hostels = {"Ganga", " Mandak" , "Swarna" , " Godavari","Krishna"};
        for(int i=0;i<100;i++){
            string prof = "prof"+to_string(i+1);
            bool r = rand()%2;
            iit.faculty.push_back(new Faculty(prof,r));
        }
        for(int i=0;i<1e5;i++){
            string roll = "CS24" +to_string(i+1) ;
            string hostel = hostels[rand()%hostels.size()];
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
           
            while((facindex < j && guideCount[iit.faculty[facindex]] ==2 )|| (facindex < j && !iit.faculty[facindex]->isPermanent())){facindex++;}
            if(facindex >= j){break;}
            if(s->if_btech())
            {
                BTech* b=dynamic_cast<BTech*>(s);
                b->setBTPGuide(iit.faculty[facindex]);
                guideCount[iit.faculty[facindex]]++;
            }
        }
        std::sort(iit.students.begin(), iit.students.end(), [](Student* a, Student* b) {
            return (a->getHostel())[0] > (b->getHostel())[0];  // high to low
        });
        facindex=0;
       
        for(Student* s : iit.students){
           
            while((facindex < j && DDPguideCount[iit.faculty[facindex]] ==2 )|| (facindex < j && !iit.faculty[facindex]->isPermanent())){facindex++;}
            if(facindex >= j){break;}
            if(!(s->if_btech()))
            {
                Dual* b=dynamic_cast<Dual*>(s);
                b->setDDPGuide(iit.faculty[facindex]);
                DDPguideCount[iit.faculty[facindex]]++;
            }
        }
        
        int count=0;

        for(Student* s : iit.students){
           int r=rand()%j;
            while(TAguideCount[iit.faculty[r]]>=5){r=rand()%j;}
            if(count == 5*j){break;}
            if(!(s->if_btech()))
            {
                Dual* b=dynamic_cast<Dual*>(s);
                b->setTA(iit.faculty[r]);
                TAguideCount[iit.faculty[r]]++;
                count++;
            }
        }

}