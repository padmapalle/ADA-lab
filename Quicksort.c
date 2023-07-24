/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int partition(int arr[],int low,int high){
    int pivot=arr[high],i=low-1,temp;
    for(int j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    temp=arr[high];
    arr[high]=arr[i+1];
    arr[i+1]=temp;
    return i+1;
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int p=partition(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}

int main(){
     clock_t start,end;
    int n,arr[20];
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    start=clock();
    quicksort(arr,0,n-1);
    end=clock();
     double time=(double)(end-start)/CLOCKS_PER_SEC;
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nTime taken:%f seconds\n",time);
    return 0;
}