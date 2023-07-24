/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void merge(int arr[],int l,int m,int h){
    int i,j,k;
    int n1=m-l+1;
    int n2=h-m;
    int temp1[n1];
    int temp2[n2];
    for(int i=0;i<n1;i++){
        temp1[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        temp2[i]=arr[m+i+1];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2){
        if(temp1[i]<temp2[j]){
            arr[k]=temp1[i];
            i++;
        }
        else{
            arr[k]=temp2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=temp1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=temp2[j];
        j++;
        k++;
    }

}

void mergesort(int arr[],int l, int h){
    if(l<h){
        int m=(l+h-1)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}

int main(){
    clock_t start,end;
    int arr[100000],n,low,high;
    printf("Enter size of array: ");
    scanf("%d",&n);
    // printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        arr[i]=rand() % 1000;
        // scanf("%d",&arr[i]);
    }
    low=0;
    high=n-1;
    start=clock();
    mergesort(arr,low,high);
    end=clock();
    double time=(double)(end-start)/CLOCKS_PER_SEC;
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nTime taken:%f seconds\n",time);
    return 0;
}
