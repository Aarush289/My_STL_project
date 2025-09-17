#include<stdio.h>
int main(){
    int cases;
    scanf("%d",&cases);
    for(int j=1;j<=cases;j++){
        int n,m,k;
        int z;
        int colors=1;
        int x1=1;
        scanf("%d%d%d",&n,&m,&k);
        for(x1=1;x1<=n;x1++){
            int y1=1;
            for(;y1<=m;y1++){
                int x2=1;
                for(;x2<=n;x2++){
                    int y2=1;
                    for(;y2<=m;y2++){
                        if(((x2-x1)<k && (x2-x1)>(0-k))||((y2-y1)<k && (y2-y1)>(0-k))){
                            if(x2==x1&&y2==y1){}
                            else{colors=colors+1;}
                        }
                    }
                }
        }
        }
        printf("%d",colors);
    }
}