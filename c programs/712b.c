#include <stdio.h>
int main(){
    char string[100001];
    scanf("%s",&string);
    int countl=0,countr=0,countd=0,countu=0;
    int i=0;
    while(string[i]!=0){
        switch(string[i]){
            case'L':
            countl++;
            break;
            case'R':
            countr++;
            break;
            case'U':
            countu++;
            break;
            case'D':
            countd++;
            break;
        }
        i++;
    }
    if((countr+countl+countd+countu)%2!=0){printf("-1\n");}
    else{
        if(countr<countl)
        {
            int temp=countr;
            countr=countl;
            countl=temp;
                    }
        if(countu<countd)
        {
            int temp=countu;
            countu=countd;
            countd=temp;
                    }
            countu=countu-countd;
            countr=countr-countl;
            printf("%d\n",(countr+countu)/2);
            }
    }