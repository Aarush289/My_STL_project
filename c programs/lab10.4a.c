#include<stdio.h>
#include<string.h>
int main(){
    char orig[1000];
    fgets(orig,1000,stdin);
    while(1){
        char input1[1000];
        scanf("%s",input1);
         if(strlen(input1)==4 && input1[0]=='e' && input1[1]=='x' && input1[2]=='i' && input1[3]=='t'){break;}
        char input2[1000];
         scanf("%s",input2);
        for(int i=0;i<strlen(orig);i++){
            int k=0;
            int flag=1;
            int j;
                for(j=i;j<i+strlen(input1);j++){
                    if(orig[j]==input1[k]){k++;}
                    else{flag=0;break;}
                }

                if(flag==1)
                {   
                     int p=0;
                    for(int l=i;l<(i+strlen(input1));l++){
                            orig[l]=input2[p];
                            p++;
                }
                i=j;
            }
        }
        printf("%s",orig);
    }
}