#include<iostream>
using namespace std;
#define MinusInifity -10000
void print(int r[]){
    cout<<"Maxsum:"<<r[0]<<"  is from "<<r[1]<<" to "<<r[2]<<endl;
}
int * mid_MaxsumSubarray(int a[], int l, int r){
    int mid = (l+r)/2;
    int sum_l = 0, max_sum_l = MinusInifity;
    int left = mid;
    for(int i=mid;i>=l;i--){
        sum_l += a[i];
        if(max_sum_l <sum_l){
            max_sum_l = sum_l;
            left = i;
        }
    }
    int sum_r = 0, max_sum_r = MinusInifity;
    int right = mid+1;
    for(int i=mid+1;i<=r;i++){
        sum_r += a[i];
        if(max_sum_r <sum_r){
            max_sum_r = sum_r;
            right = i;
        }
    }
    int * result = new int[3];
    result[0] = max_sum_r + max_sum_l;
    result[1] = left;
    result[2] = right;
    return result;
}
int * MaxsumSubarray(int a[], int l, int r){
    if(l==r){
        int * result = new int[3];
        result[0] = a[l];
        result[1] = result[2] = l;
        return result;
    }
    int mid = (l+r)/2;
    int * left_result = MaxsumSubarray(a,l,mid);
    int * right_result = MaxsumSubarray(a,mid+1,r);
    int * mid_result = mid_MaxsumSubarray(a,l,r);
    //print(mid_result);
    if(left_result[0]>=right_result[0]&&left_result[0]>=mid_result[0])
        return left_result;
    if(left_result[0]<=right_result[0]&&right_result[0]>=mid_result[0])
        return right_result;
    if(left_result[0]<=mid_result[0]&&right_result[0]<=mid_result[0])
        return mid_result;
}

int main(){
    //{1, -2, 3, 10, -4, 7, 2, -5} 18
    //{-1,-2,-3,-4} -1
    //{31,-41,59,26,-53,58,97,-93,-23,84} 187
    int a[] = {31,-41,59,26,-53,58,97,-93,-23,84};
    int * result = MaxsumSubarray(a,0,9);
    print(result);
    return 0;
}
