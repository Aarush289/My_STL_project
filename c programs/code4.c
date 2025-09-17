# include<stdio.h>
int main(){
    int cases;
    scanf("%d",&cases);
    for(int i=0;i<cases;i++){
        int l,m;
        scanf("%d%d",&l,&m);
        int sum=0;
        for(int j=l;j<=m;j++){
            if(j%2==0){}
            else{sum++;}
        }
        printf("%d",sum/2);
    }
    return 0;
}