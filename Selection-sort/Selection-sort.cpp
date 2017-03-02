#include<iostream>
using namespace std;

void Selection_sort(int a[], int n){
	/* 
	 *  选择排序不稳定排序，内排序
	 *  算法时间复杂度为O(n^2)，空间复杂度为O(1)
	 */
	for(int i=0;i<n;i++){
		int min = i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min])
				min = j;
		}
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}
	
}
/*  递归版选择排序  */
void Selection_sort_recursive(int a[], int p, int q){
	if(p < q){
		int max = p;
		for(int i=p+1;i<=q;i++){
			if(a[max]<a[i])
				max = i;
		}
		int temp = a[p];
		a[p] = a[max];
		a[max] = temp;
		Selection_sort_recursive(a, p+1, q);
	}
}
int main(){
	int a[5] = {5, 4, 3, 2, 1};
	Selection_sort(a, 5);
	Selection_sort_recursive(a, 0, 4);
	for(int i=0;i<5;i++)
		cout<<a[i]<<",";
	cout<<endl;
	return 0;
}
