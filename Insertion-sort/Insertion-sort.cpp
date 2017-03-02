#include<iostream>
using namespace std;
void Insertion_sort(int a[],int n){
	/*
	 * 快排，从小到大排列
	 * 稳定的内排序，时间复杂度为O(n^2)，空间复杂度为常数O(1)
	 * 复杂度跟逆序对的数量，输入为逆序时复杂对为O(n^2)，正序时为O(n)
	 * 使用循环不变式证明算法的正确性
	 */
	for(int i=1;i<n;i++){
		int key = a[i];
		int j = i-1;
		while(j>=0&&a[j]>key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1]= key;
	}
}
/*  逆序插入排序  */
void Insertion_sort_reverse(int a[], int n){
	for(int i=1;i<n;i++){
		int key = a[i];
		int j = i-1;
		while(j>=0&&a[j]<key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}
/*  递归版插入排序  */
void Insertion_sort_recursive(int a[], int p, int q){
	if(p<q){
		Insertion_sort_recursive(a, p, q-1);
		int key = a[q];
		int j = q-1;
		while(j>=0&&a[j]>key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}
int main(){
	int a[5] = {5,4,3,2,1};
	Insertion_sort(a, 5);
	Insertion_sort_reverse(a, 5);
	Insertion_sort_recursive(a, 0, 4);
	for(int i=0;i<5;i++)
		cout<<a[i]<<",";
	cout<<endl;
	return 0;
}
