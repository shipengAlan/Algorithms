#include<iostream>
#define INT_MAX 0xffffffe
using namespace std;
void merge(int a[], int l, int q, int r){
	int * L = new int[q - l + 2];
	int * R = new int[r - q + 1];
	for(int i=l;i<=q;i++)
		L[i-l] = a[i];
	for(int i=q+1;i<=r;i++)
		R[i-q-1] = a[i];
	L[q-l+1] = INT_MAX;
	R[r-q] = INT_MAX;
	int i=0, j=0;
	for(int k=l;k<=r;k++){
		if(L[i]<=R[j]){
			a[k] = L[i];
			i++;
		}
		else{
			a[k] = R[j];
			j++;
		}
	}
}
void merge_sort(int a[], int l, int r){
	/* 
	 *  归并排序 稳定 外排序
	 *  时间复杂度为O(nlogn)，空间复杂度O(n)
	 *  采用分治法，递归实现
	 */
	if(l<r){
		int q = (l+r)/2;
		merge_sort(a, l, q);
		merge_sort(a, q+1, r);
		merge(a, l, q, r);
	}
}

int main(){
	int a[7] = {8, 2, 5, 4, 6, 9, 7};
	merge_sort(a, 0, 6);
	for(int i=0;i<7;i++)
		cout<<a[i]<<",";
	cout<<endl;
	return 0;
}
