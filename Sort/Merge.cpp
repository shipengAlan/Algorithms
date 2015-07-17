#include<iostream>
using namespace std;
#define MAX 10000
template<typename T>
void Merge(T a[], int p ,int q ,int r){
    T * L = new T[q-p+2];
    T * R = new T[r-q+1];
    int i = 0;
    for(i=0;i<q-p+1;i++)
        L[i] = a[p+i];
    L[i] = MAX;
    for(i=0;i<r-q;i++)
        R[i] = a[q+1+i];
    R[i] = MAX;
    int m = 0, n = 0;
    i = 0;
    while(i<r-p+1){
        T Min = 0;
        if(L[m]<=R[n]){
            Min = L[m];
            m++;
        }
        else{
            Min = R[n];
            n++;
        }
        a[i+p] = Min;
        i++;
    }
    delete [] L;
    delete [] R;
	return;
}
template<typename T>
void MergeSort(T a[],int l ,int r){
    if(l < r){
        int mid = (l+r)/2;
        MergeSort(a,l,mid);
        MergeSort(a,mid+1,r);
        Merge(a,l,mid,r);
    }
}
template<typename T>
void print(T a[],int n){
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    // test 1
    int a[] = {1,2,1,2,7,2,1};
    int n = 7;
    print(a,n);
    MergeSort(a,0,6);
    print(a,n);
        // test 2
    float b[] = {1.2,2.1,1.9,2.4,7.1,2.2,1.99};
    int m = 7;
    print(b,m);
    MergeSort(b,0,6);
    print(b,m);
    return 0;
}
