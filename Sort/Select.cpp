#include<iostream>
using namespace std;
template<typename T>
void Select(T a[],int n){
    for(int i=0;i<n;i++){
        T Min = a[i];
        int key = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<Min){
                Min = a[j];
                key = j;
            }
        }
        T temp = a[i];
        a[i] = Min;
        a[key] = temp;
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
    Select(a,n);
    print(a,n);
    // test 2
    float b[] = {1.2,2.1,1.9,2.4,7.1,2.2,1.99};
    int m = 7;
    print(b,m);
    Select(b,m);
    print(b,m);
}
