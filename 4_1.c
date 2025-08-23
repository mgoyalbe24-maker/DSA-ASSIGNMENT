#include<stdio.h>
int main(){
    int arr[]={1,2,3,4,5};
    int n;
    printf("Enter size:");
    scanf("%d",&n);
    for(int i=0;i<n/2;i++){
        int x=arr[i];
        int y=arr[n-i-1];
        arr[i]=y;
        arr[n-i-1]=x;
    }
    printf("reverse array:");
    printf("\n");
    for(int i=0;i<n;i++){
        
        printf("%d\t",arr[i]);
    }
    return 0;
}