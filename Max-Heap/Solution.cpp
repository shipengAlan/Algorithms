#include<iostream>
using namespace std;
class MaxHeap{
public:
    int * a;
    int length;
    MaxHeap(int arr[], int l){
        a = arr;
        length = l;
    }
    // ����
    void Build_MaxHeap(){
        for(int i = length /2-1; i>=0; i--){
            Heapify(i);
        }
    }
    // �������ҵ����ڵ�������ӽڵ㣬��������������Ȼ�����µݹ��������
    void Heapify(int i){
        int left = i*2 + 1;
        int right = i*2 + 2;
        int large = i;
        if(left<length&&a[left]>a[i]){
            large = left;
        }
        if(right<length&&a[right]>a[large])
            large = right;
        if(large!=i)
        {
            int temp = a[large];
            a[large] = a[i];
            a[i] = temp;
            Heapify(large);
        }
    }
    // ������ȡ�ѵĸ��������֣�ʹ�����һ�������滻��������ʹ����������
    int * HeapSort(){
        Build_MaxHeap();
        int * res = new int[length];
        int i = 0;
        while(length!=0){
            res[i] = a[0];
            a[0] = a[length-1];
            length--;
            Heapify(0);
            i++;
        }
        return res;
    }


};
// ����
int main(){
    int a[10] = {4,1,3,2,16,9,10,14,8,7};
    MaxHeap mx(a,10);
    int *res = mx.HeapSort();
    for(int i=0;i<10;i++)
        cout<<res[i]<<" ";
    cout<<endl;
}
