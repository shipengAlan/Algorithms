#include<iostream>
#include<stack>
using namespace std;
int Partition(int a[], int p, int r){
	int x = a[r];
	int i = p-1;
	for(int j=p;j<r;j++){
		if(a[j]<x){
			i++;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[r] = a[i+1];
	a[i+1] = x;
	return i+1;

}
/* 快速排序，不稳定的内排序
 * 平均时间和最好的复杂度为O(nlogn)，最差时间复杂度为O(n^2)
 * 递归实现版
 */
void Quick_sort(int a[], int p, int r){
	if(p<r){
		int q = Partition(a, p, r);
		Quick_sort(a, p, q-1 );
		Quick_sort(a, q+1, r);
	}
}
/* 非递归实现快速排序，用堆栈  */
void Quick_sort2(int a[], int n){
	int l = 0;
	int r = n-1;
	if(l>=r)
		return;
	stack<int> s;
	s.push(l);
	s.push(r);
	while(!s.empty()){
		r = s.top();
		s.pop();
		l = s.top();
		s.pop();
		int p = Partition(a, l, r);
		if(l<p-1){
			s.push(l);
			s.push(p-1);
		}
		if(p+1<r){
			s.push(p+1);
			s.push(r);
		}
	}
}
int main(){
	//int a[5] = {1, 2, 3, 4, 5};
	//int a[5] = {5, 4, 3, 2, 1};
	int a[8] = {8,3,2,4,6,4,6,7};
	//Quick_sort(a, 0, 7);
	Quick_sort2(a, 8);
	for(int i=0;i<7;i++){
		cout<<a[i]<<",";
	}
	cout<<endl;
	return 0;
}
