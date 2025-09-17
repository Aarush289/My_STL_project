#include<bits/stdc++.h>
using namespace std;
#define debug 0

int optimize(int mid,int w,int h){
    int power1=0;
    int power2=0;
    int a=(mid/w);
    int b=(mid/h);
    int pro=1;
    while(pro<a){
        a/=10;
        power1++;
    }
    while(pro<b){
        b/=10;
        power2++;
    }
    if((power1+power2) > 18){return 1;}
    else{return 0;}
}
int main(){
    int w;
    int h;
    int n;
    scanf("%lld%lld%lld",&w,&h,&n);
    int pro1=(w*n);
    int pro2=(h*n);
    int pro;
    if(pro1>pro2){pro=pro1;}
    else{pro=pro2;}
    int low=1;
    int high=pro;
     int mid;
    while(low<=high){
       mid=(low+high)/2;
        int m;
        int test=optimize(mid,w,h);
        if(test){high=mid;continue;}
        m=((mid/w)*(mid/h));
        if(m<n){low=mid+1;}
        if(m>=n){
           int m2=(((mid-1)/w)*((mid-1)/h));
            if(m2>=n){high=mid;}
#include<bits/stdc++.h>
using namespace std;
#define debug 0

long long int optimize(long long int mid,long long int w,long long int h){
    long long int power1=0;
    long long int power2=0;
    long long int a=(mid/w);
    long long int b=(mid/h);
    long long int pro=1;
    while(pro<a){
        a/=10;
        power1++;
    }
    while(pro<b){
        b/=10;
        power2++;
    }
    if((power1+power2) > 18){return 1;}
    else{return 0;}
}
int main(){
    long long int w;
    long long int h;
    long long int n;
    scanf("%lld%lld%lld",&w,&h,&n);
    long long int pro1=(w*n);
    long long int pro2=(h*n);
    long long int pro;
    if(pro1>pro2){pro=pro1;}
    else{pro=pro2;}
    long long int low=1;
    long long int high=pro;
     long long int mid;
    while(low<=high){
       mid=(low+high)/2;
        long long int m;
        long long int test=optimize(mid,w,h);
        if(test){high=mid;continue;}
        m=((mid/w)*(mid/h));
        if(m<n){low=mid+1;}
        if(m>=n){
           long long int m2=(((mid-1)/w)*((mid-1)/h));
            if(m2>=n){high=mid;}
            else{break;}
        }
    }
    printf("%lld\n",mid);
}
            else{break;}
        }
    }
    printf("%lld\n",mid);
}
