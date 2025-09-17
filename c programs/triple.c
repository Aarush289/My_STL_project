#include<stdio.h>
int main(){
    int side1,side2,hypo;
    for(hypo=500;hypo>=1;hypo--){
        int temp=hypo*hypo;
        side1=1;
        for (;side1<hypo;side1++){
            int temp2=(temp-(side1*side1));
            int side2=1;
            for(side2=1;side2<side1;side2++){
                int square=side2*side2;
                if(square==temp2){
                    printf("%d,%d,%d\n",side1,side2,hypo);break;
                }
            }
        }
    }
}