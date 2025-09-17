#include <stdio.h>
int main(){
    char brace[100001];
    scanf("%s",&brace);
    int i=0;
    int flag=0;
    int count1=0,count2=0,count3=0,count11=0,count22=0,count33=0;
    while(brace[i]!=0){
        switch(brace[i]){
            case'(':
            count1++;
            break;
            case')':
            count11++;
            break;
            case'{':
            count2++;
            break;
            case'}':
            count22++;
            break;
            case'[':
            count3++;
            break;
            case']':
            count33++;
            break;
        }
        i++;
    }
    i=0;
    if((count1==count11 && count2==count22) && count3==count33){
    while(brace[i]!=0){
        switch(brace[i]){
            case'{':
            if(brace[i+1]==')' || brace[i+1]==']'){flag=1;}
            else{};
            break;
             case'(':
            if(brace[i+1]=='}'||brace[i+1]==']'){flag=1;}
            else{};
            break;
             case'[':
            if(brace[i+1]==')'||brace[i+1]=='}'){flag=1;}
            else{};
            break;     
        }
        if(flag==0){break;}
        i++;
    }
    }
    else{flag=0;}
    if(flag==1){printf("Yes\n");}
    else{printf("No");}
}