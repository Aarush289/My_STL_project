#include<bits/stdc++.h>
using namespace std;
#define debug 0

class sphere{
    public:
        double centerX;
        double centerY;
        double centerZ;
        double radius;
        sphere(){
            cout << "Enter X-coordinate of center" <<endl;
            cin >> centerX;
            cout << "Enter Y-coordinate of center" << endl;
            cin >> centerY;
            cout << "Enter Z-coordinate of center" << endl;
            cin >> centerZ;
            cout << " Enter radius of sphere" << endl;
            cin >> radius ;
        }
        ~sphere(){};

};

class ray{
    public:
        double x;
        double y;
        double z;
        ray() : x(0), y(0), z(0) {}

        ray(bool askinput){
            if(askinput){
                cout << "Enter component in 1st dimention"<<endl;
                cin >> x;
                cout << "Enter component in 2nd dimention"<<endl;
                cin >> y;
                cout << "Enter component in 3rd dimention"<<endl;
                cin >> z;
            }
        }
        ~ray(){};

       ray(const ray &v2){
        x= v2.x;
        y = v2.y;
        z= v2.z ;
        }
        ray operator+(const ray &v2) const{
            ray v3;
                v3.x = x + v2.x;
                v3.y = y + v3.y;
                v3.z = z + v3.z;
                return v3;
        }

        ray operator*(double a) const{
            ray v3;
                v3.x = x*a;
                v3.y = y*a;
                v3.z = z*a;
                return v3;
            }

        ray operator-(const ray &v2) const{
            ray v3;
                v3.x = x - v2.x;
                v3.y = y - v3.y;
                v3.z = z - v3.z;
                return v3;
            }

        ray operator/(double a) const{
            ray v3;
                v3.x = double(x/a);
                v3.y = double(y/a);
                v3.z = double(z/a);
                return v3;
            }
        
        bool operator==(ray &v2){
            if(x == v2.x && y == v2.y && z == v2.z ){return true;}
            else{return false;}
        }

        double dot_product(const ray &v2) const{
            double u;
            u = (x*v2.x + y*v2.y + z*v2.z);
            return u;
        }

        ray vector_product(const ray &v2) const{
            ray v3;
                v3.x = y*v2.z - z*v2.y;
                v3.y = z*v2.x - x*v2.z;
                v3.z = x*v2.y - y*v2.x;
                return v3;
            }

        double length() const{
            double h;
            h=sqrt(x*x + y*y + z*z);
            return h;
        }

        void Normalize(){
            double h= double(1.0/sqrt(x*x +y*y + z*z));
            x = h*x;
            y = h*y;
            z = h*z;
            return ;
        }
};

class triangle{
    public:
        ray vertex1;
        ray vertex2;
        ray vertex3;
        triangle() : vertex1(true), vertex2(true), vertex3(true) {}
        ~triangle(){};
};

class plane{
    public:
        double x;
        double y;
        double z;
        plane(){
            cout << "Enter component in 1st dimention"<<endl;
            cin >> x;
            cout << "Enter component in 2nd dimention"<<endl;
            cin >> y;
            cout << "Enter component in 3rd dimention"<<endl;
            cin >> z;

        }
        ~plane(){};
};



void Intersect(ray& r, plane& p){
    if(r.x*p.x + r.y*p.y + r.z*p.z < (1e-6)){cout << "Does Not Intersect" << endl;}
    else{cout << "Intersect" << endl;}
    return ;
}

void Intersect(ray& r , sphere& s){
    double term1 , term2 , term3 , term4 ;
    term1 = (s.centerX)*(r.y*r.y + r.z*r.z - r.x*r.y - r.x*r.z );
    term2 = (s.centerY)*(r.x*r.x + r.z*r.z - r.x*r.y - r.y*r.z );
    term3 = (s.centerZ)*(r.y*r.y + r.x*r.x - r.z*r.y - r.x*r.z );
    term4 = r.y*r.y + r.z*r.z + r.x*r.x ;
    double term5;
    term5 = double((term1 + term2 + term3)*1.0/term4);
    term5 = sqrt(term5);
    if(term5 - s.radius >(1e-6)){cout << "Does not Intersect" <<endl;}
    else{cout << "Intersects" <<endl;}
    return ;
}

void Intersect(const ray& r , const triangle& t){
    double factor1,factor2,factor3;
    double numerator,denominator;
    if(r.dot_product((t.vertex2-t.vertex1).vector_product(t.vertex3-t.vertex1)) < (1e-6)){cout << "Does not Intersect" <<endl; return;}
    numerator = (t.vertex1).dot_product(r.vector_product((t.vertex2)-(t.vertex1))) ;
    denominator = (t.vertex3-t.vertex1).dot_product(r.vector_product(t.vertex2 - t.vertex1)) ;

    if(denominator == 0){cout << "Does not intersect" <<endl; return;}

    factor1 = double(numerator*(-1.0)/denominator) ;
    if(factor1 >1 || factor1 < 0){cout << "Does not intersect" <<endl; return;}

    numerator = (t.vertex1).dot_product(r.vector_product(t.vertex3 - t.vertex1)) ;
    denominator = (t.vertex2 - t.vertex1).dot_product(r.vector_product(t.vertex3 - t.vertex1)) ;
    
    if(denominator == 0){cout << "Does not intersect" <<endl; return;}

    factor2 = double(numerator*(-1.0)/denominator) ;
    if(factor2 >1 || factor2 < 0){cout << "Does not intersect" <<endl; return;}
    
    factor3 = factor1+factor2 ;
    if(factor3 >1 || factor3 < 0){cout << "Does not intersect" <<endl; return;}

    cout << "Intersects" << endl;
    return;
}

int main(){
    ray r(true);
    char str[10];
    cout << "Enter the object type : Plane or Sphere or Triangle" <<endl;
    cin >> str;
    str[0] = toupper(str[0]);
    switch (str[0]){
        case 'P' :{
                plane p1;
                Intersect (r , p1);
                break;
        }
        case 'S' :{
                sphere s1;
                Intersect (r , s1);
                break;
        }
        case 'T' :{
                triangle t1;
                Intersect (r , t1);
                break;
        }
        default :{
                cout << " Invalid shape , Please give some valid shape " << endl;
        }
    }
    return 0;
}