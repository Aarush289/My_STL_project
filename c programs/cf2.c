#include<stdio.h>
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int n,m,q;
        scanf("%d%d%d",&n,&m,&q);
        int array[m-1];
        int david[q-1];
        for(int j=0;j<m;j++){
            scanf("%d",&array[j]);
        }
        for(int j=0;j<q;j++){
            scanf("%d",&david[j]);
        }
        for(int j=0;j<q;j++){
            int flag1=0;
            for(int k=0;k<m;k++){
            if(david[j]>array[k]){}
            else {flag1=1;break;}}
            if(flag1==0){
                int max=array[0];
                for(int p=1;p<m;p++){
                    if(max>array[p]){}
                    else{max=array[p];}
                }
                printf("%d\n",n-max);     
                }
            int flag2=0;
            for(int k=0;k<m;k++){
            if(david[j]<array[k]){}
            else {flag2=1;break;}}
            if(flag2==0){
                int min=array[0];
                for(int p=1;p<m;p++){
                    if(min<array[p]){}
                    else{min=array[p];}
                }
                printf("%d\n",min-1);}
            if(flag1!=0&&flag2!=0){
                int l,k;
                for(int l=0;l<m;l++){
                    if(array[l]<david[j]){}
                    else{break;}
                }
                for(int k=m-1;k>=0;k--){
                    if(array[k]>david[j]){}
                    else{break;}
                }
                printf("%d\n",((array[k+1]-array[l-1])/2));
            }
        }
    }
    return 0;
}