#include<iostream>
using namespace std;
/* 计数排序 稳定的外排序，时间复杂度为O(n)，不是基于比较的排序算法  */
void Counting_sort(int a[], int n){
	int max = 0x80000001;
	for(int i=0;i<n;i++){
		if(a[i]>max)
			max = a[i];
	}
	int * C = new int[max+1];
	for(int i=0;i<max+1;i++){
		C[i] = 0;
	}
	int * B = new int[n];
	for(int i=0;i<n;i++){
		C[a[i]]++;
		B[i] = a[i];
	}
	for(int i=0;i<max+1;i++){
		C[i+1] = C[i] + C[i+1];
	}
	for(int i=n-1;i>=0;i--){
		//if(C[B[i]-1]>=0){
			a[C[B[i]]-1] = B[i];
			C[B[i]]--;
		//}
	}
}

int main(){
	int a[7] = {8, 2, 5, 4, 6, 9, 7};
	Counting_sort(a, 7);
	for(int i=0;i<7;i++)
		cout<<a[i]<<",";
	cout<<endl;
	int b[11] = {1, 5, 8, 5, 0, 6, 7, 6, 5, 8, 3};
	Counting_sort(b, 11);
	for(int i=0;i<11;i++)
		cout<<b[i]<<",";
	cout<<endl;
	//Counting_sort(NULL, 0);
	return 0;
}
