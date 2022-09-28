#include <iostream>
#include <fstream>
using namespace std;
//merge function
void merge(int arr[],int leftindex,int m,int rightindex){
    int i=leftindex,j=m+1,k=leftindex;
    int legth=rightindex+1;
    int temp[5];
    while(i<=m && j<=rightindex){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }else{
            temp[k]=arr[j];
            k++;
            j++ ;
        }
    }
    while(i<=m){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=rightindex){
        temp[k]=arr[j];
        j++;
        k++;
     }
     for(int a=0;a<=rightindex;a++){
         arr[a]=temp[a];
     }
}
//mergesort function
void mergeSort(int arr[], int leftindex, int rightindex){
    if(leftindex<rightindex)//to check if it has only one element
    {
        //calculate the midpoint
        int m=(leftindex+rightindex)/  2;
        mergeSort(arr,leftindex,m);//mergesort for the first half
        mergeSort(arr,m+1,rightindex);//mergesort for the second half
        merge(arr,leftindex,m,rightindex);
    }
}

int main(){
    int myarr[5];
    cout<<"Enter five integers:"<<endl;
    for(int i=0;i<5;i++){
        cin>>myarr[i];
    }
    cout<<"Entered array is:"<<endl;
    //print before sorted
    for(int i=0;i<5;i++){
        cout<<myarr[i]<<" ";
    }
    cout<<endl;
    mergeSort(myarr,0,4 );
    cout<<"Sorted array is:"<<endl;
    //print after sorted
    for(int i=0;i<5;i++){
        cout<<myarr[i]<<" ";
    }
    cout<<endl;

}