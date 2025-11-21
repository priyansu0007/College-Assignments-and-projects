#include <stdio.h>
int chain_matrix(int);
int main(){
    int n,ways;
    printf("Enter the number of matrix");
    scanf("%d",&n);
    ways=chain_matrix(n);
    printf("Number of ways: %d",ways);
}
int chain_matrix(int n){
    if (n==1){return 1;}
    int i,sum=0;
    for(i=1;i<=n-1;i++){
        sum+=(chain_matrix(i)*chain_matrix(n-i));
    }
    return sum;
}