#include <stdio.h>
#include <string.h>
int main(){
    char string[100001];
    scanf("%s",&string);
    int counta=0;
    int countb=0;
    int i=0;
    while(string[i]!=0){
        int flag=0;
        for(int j=i;j<strlen(string);j++){if(string[j]=='a'){flag=1;}}
        if(flag==0){break;}
        i++;
    }
   // printf("%d\n",i);
    for(int j=0;j<strlen(string);j++)
    {   
        if(string[j]=='a'){counta++;}
    }
   // printf("%d\n",counta);
    int flag2=0;
    for(int j=0;j<i;j++){if(string[j]!='a'){countb++;}}
    if(countb>(strlen(string)-i)){printf(":(\n");flag2=1;}
    //printf("%d\n",countb);
    while(countb<(strlen(string)-i)){
        i++;
        countb++;
    }
   // printf("%d\n",countb);
    char string2[i-counta];
    char string3[i-counta];
    int k=0;
        for(int j=0;j<i;j++){
            if(string[j]!='a'){string2[k]=string[j];k++;}
        }
    //    for(k=0;k<i-counta;k++){printf("%c",string2[k]);}
      //  printf("\n");
        k=0;
        for(int j=i;j<strlen(string);j++){
            string3[k]=string[j];
            k++;
        }
       // for(k=0;k<i-counta;k++){printf("%c",string3[k]);}
       // printf("\n");
        int flag=0;
        for(int j=0;j<(i-counta);j++){
            if(string2[j]==string3[j]){}
            else{flag=1;break;}
        }
        if(flag2==0){
            if(flag==0){
                for(int k=0;k<i;k++){printf("%c",string[k]);}
                printf("\n");
            }
            else{printf(":(\n");}
        }
    return 0;
}
