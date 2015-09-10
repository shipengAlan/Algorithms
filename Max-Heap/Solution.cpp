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
    // 建堆
    void Build_MaxHeap(){
        for(int i = length /2-1; i>=0; i--){
            Heapify(i);
        }
    }
    // 调整，找到父节点的左右子节点，调整最大的上来，然后向下递归继续调整
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
    // 堆排序，取堆的根部的数字，使用最后一个数字替换，调整根使其满足大根堆
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
// 测试
int main(){
    int a[10] = {4,1,3,2,16,9,10,14,8,7};
    MaxHeap mx(a,10);
    int *res = mx.HeapSort();
    for(int i=0;i<10;i++)
        cout<<res[i]<<" ";
    cout<<endl;
}
