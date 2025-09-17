#include<bits/stdc++.h>
using namespace std;
# define debug 0
int main() {
    double c;
    scanf("%lf",&c);
    double low=0;
    double high=1e3;
    double mid=(low+high)/2;
    double value=(((2*mid*mid)+(1/(2*mid)))*(1e-8));
    while(low<high){
        mid=(low+high)/2;
        double pro= (mid*mid*mid*mid);
        double exp=pro+mid-c;
        value=(((2*mid*mid)+(1/(2*mid)))*(1e-8));
        if(exp>value){high=mid;}
        else{if(exp<(-value)){low=mid;}
                else{break;}
                }
    }
    if(debug){printf("%f %f %f\n",low,high,mid);}
    double result=(mid*mid);
    printf("%.8f\n",result);
}
