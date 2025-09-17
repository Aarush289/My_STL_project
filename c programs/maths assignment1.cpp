#include<bits/stdc++.h>
using namespace std;
#define debug 0

class Vector3D{
    double x, y, z;
    Vector3D(){
        x=1;
        y=1;
        z=1;
    }
    Vector3D(){
        cout << "Enter 1st Component : ";
        cin >> x ;
        cout << "Enter 2nd Component : ";
        cin >> y;
        cout << "Enter 3rd Component : ";
        cin >> z;
    }
    ~Vector3D();
    Vector3D(const Vector3D &v2){
        x= v2.x;
        y = v2.y;
        z= v2.z ;
    }
    Vector3D operator+(Vector3D &v2){
        Vector3D v3;
        v3.x = x + v2.x;
        v3.y = y + v3.y;
        v3.z = z + v3.z;
        return v3;
    }

    Vector3D operator*(double a){
        Vector3D v3;
        v3.x = x*a;
        v3.y = y*a;
        v3.z = z*a;
        return v3;
    }

    Vector3D operator-(Vector3D &v2){
        Vector3D v3;
        v3.x = x - v2.x;
        v3.y = y - v3.y;
        v3.z = z - v3.z;
        return v3;
    }

    Vector3D operator/(double a){
        Vector3D v3;
        v3.x = double(x/a);
        v3.y = double(y/a);
        v3.z = double(z/a);
        return v3;
    }
    
    bool operator==(Vector3D &v2){
        if(x == v2.x && y == v2.y && z == v2.z ){return true;}
        else{return false;}
    }

    double dot_product(Vector3D &v2){
        double u;
        u = (x*v2.x + y*v2.y + z*v2.z);
        return u;
    }

    Vector3D vector_product( Vector3D &v2){
        Vector3D v3;
        v3.x = y*v2.z - z*v2.y;
        v3.y = z*v2.x - x*v2.z;
        v3.z = x*v2.y - y*v2.x;
        return v3;
    }

    double length(){
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

class matrix3d{
    double arr1[3];
    double arr2[3];
    double arr3[3];
    matrix3d{
        for(int i=0;i<3;i++){
            if(i!=0){arr1[i]=0;}
            else{arr1[i]=1;}
        }
        for(int i=0;i<3;i++){
            if(i!=1){arr1[i]=0;}
            else{arr1[i]=1;}
        }
        for(int i=0;i<3;i++){
            if(i!=2){arr1[i]=0;}
            else{arr1[i]=1;}
        }
    }
    matrix3d{
        cout << "Enter 1st row of matrix" << endl;
        for(int i=0;i<3;i++){
            cin >> arr1[i];
        }
        cout << "Enter 2nd row of matrix" << endl;
        for(int i=0;i<3;i++){
            cin >> arr2[i];
        }
        cout << "Enter 3rd row of matrix" << endl;
        for(int i=0;i<3;i++){
            cin >> arr3[i];
        }
    }
    ~matrix3d();

    matrix3d Transpose(matrix3d mat){
        matrix3d mat2;
        
    }
}

