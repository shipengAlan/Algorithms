#include<iostream>
using namespace std;
void Bubble_sort(int a[], int n){
	for(int i=0;i<n;i++){
		/*
		 * 冒泡排序：稳定内排序
		 * 时间复杂度为O(n^2),空间复杂度为O(1)
		 * 比插入排序速度慢，why
		 * 
		 */
		for(int j=n-1;j>i;j--){
			if(a[j]<a[j-1]){
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
}
/* 递归版冒泡排序  */
void Bubble_sort_recursive(int a[], int p, int q){
	if(p<q){
		for(int i=q;i>p;i--){
			if(a[i-1]<a[i]){
				int temp = a[i-1];
				a[i-1] = a[i];
				a[i] = temp;
			}
		}
		Bubble_sort_recursive(a, p+1, q);

	}
}
int main(){
	int a[5] = {5, 4, 3, 2, 1};
	Bubble_sort(a, 5);
	Bubble_sort_recursive(a, 0, 4);
	for(int i=0;i<5;i++){
		cout<<a[i]<<",";
	}
	cout<<endl;
	return 0;
}
