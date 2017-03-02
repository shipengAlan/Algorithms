#include<iostream>
using namespace std;

void Max_Heapify(int a[], int k, int size){
	int l = (k+1) * 2 -1;
	int r = (k+1) * 2;
	int large = l;
	if(a[k]>a[l]){
		large = k;
	}
	if(a[r]>a[large]){
		large = r;
	}
	int temp = a[k];
	a[k] = a[large];
	a[large] = temp;
	Max_Heapify(a, large, size);
}
int main(){

	return 0;
}
