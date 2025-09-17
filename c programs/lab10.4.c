#include<stdio.h>
#include<string.h>
int main(){
    char orig[100000];
    fgets(orig,sizeof(orig),stdin);
    char input[1000000];
    scanf("%s",input);
    while(1){
        char input1[10000000];
        scanf("%s",input1);
        char input2[10000000];
         scanf("%s",input2);
        if(strlen(input1)==4 && input1[0]=='e' && input1[1]=='x' && input1[2]=='i' && input1[3]=='t'){break;}
        for(int i=0;i<strlen(input);i++){
            int k=0;
            int flag=1;
            int j;
                for(j=i;j<i+strlen(input1);j++){
                    if(input[i]==input1[k]){k++;}
                    else{flag=0;break;}
                }
                if(flag==1)
                {
                    for(int l=i;l<i+strlen(input1);l++){
                        int p=0;
                            input[i]=input2[p];
                            p++;
                }
                i=j;
            }
        }
        printf("%s\n",input);
    }
}