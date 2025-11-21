#include <stdio.h>
void printHouse(){
    //print roof
    int i,n=8,j,k,col=15;
    for(i=0;i<n;i++){
        for(k=col/2-i-1;k>=0;k--){
            printf("   ");
        }
        for(j=0;j<=2*i;j++){
            if(i==n-1){
                printf(" * ");
            }
            else if(j==0||j==2*i){
                printf(" * ");
            }
            else{
                printf("   ");
            }
        }
        printf(" \n");
    }
    //print the part before windows and doors
    for(i=0;i<2;i++){
        for(j=0;j<15;j++){
            if(j==0||j==14){
                printf(" * ");
            }
            else{
                printf("   ");
            }        
        }
        printf(" \n");
    }
    //print windows
    for(i=0;i<5;i++){
        for(k=0;k<15;k++){
            if(k%2==0){
                printf(" * ");
            }
            else if((k==3||k==11)&&(i==0||i==4)){
                printf(" * ");
            }
            else if(k==7&&i==0){
                printf(" * ");
            }
            else{printf("   ");}
        }
        
        printf(" \n");

    }
    //ending
    for(i=0;i<5;i++){
        for(j=0;j<15;j++){
            if(j==0||j==6||j==8||j==14||i==4){
                printf(" * ");
            }
            else{printf("   ");}
        }
        printf(" \n");
    }
}
int main(){
    printHouse();
}