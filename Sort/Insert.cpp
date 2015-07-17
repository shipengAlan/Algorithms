#include<iostream>
using namespace std;
template<typename T>
void Insert_Sort(T a[],int n){
    for(int i=1;i<n;i++){
        T key = a[i];
        int j = i - 1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
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
    int a[] = {1,3,4,5,2,0,9};
    int n = 7;
    print(a,n);
    Insert_Sort(a,n);
    print(a,n);
    // test 2
    float b[] = {1.1,3.1,4.1,5.2,2.3,0.3,9.5};
    int m = 7;
    print(b,m);
    Insert_Sort(b,m);
    print(b,m);
    return 0;
}
