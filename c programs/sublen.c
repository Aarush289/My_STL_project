#include<stdio.h>
#include<string.h>
int sub(char *ptr1,char *ptr2){
    int flag=0;
    if(*(ptr1)==0 || *(ptr2)==0){return 0;}
    else{
        while(*ptr1!=0){
            if(*ptr1==*ptr2){flag=1;break;}
            else{ptr1++;}
        }
        if(flag==0){return 0;}
        else{return 1+sub(ptr1+1,ptr2+1);}
    }
}
int main(){
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    char len1[n1+1];
    char len2[n2+1];
    int len=strlen(len1);
    scanf("%s%s",len1,len2);
    int answer=sub(len1,len2);
    if(answer==strlen(len2)){printf("1\n");}
    else{printf("0\n");}
}