#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

//max heap
//if parent index is i, then 
//1) left child is present at 2*i
//2) right child is present at 2*i +1
//if child index=i, its parent is at i/2 (irrespective of even or odd)
class maxheap{
    public:
    //attributes
    int arr[100];
    int size=0;

    //methods
    void heapify(vector<int> &vec);
    void push(int item);
    //void printHeap();
    int pop(); //delete the root since this is for priority queue
};

void maxheap :: heapify(vector<int> &vec){
    int n = vec.size();
    for(int i=0; i<n; ++i){
        this->push(vec[i]);
    }
    for(int i=0; i<n; ++i){
        vec[i] = this->pop();
    }
}

void maxheap::push(int item){
    //first insert
    size++;
    int index=size;
    arr[index]=item;
    //then check if its a heap tree (ie, if this child is smaller than the parent)
    while(index>1){
        int parent=index/2;
        //if not then swap parent and child and keep on checking until root node
        if(arr[parent]<arr[index]) {
            swap(arr[parent],arr[index]);
            index=parent;
        }else return;
    }
}
//void maxheap::printHeap(){ for(int i=1;i<=size;i++) cout<<arr[i]<<" "; }

int maxheap::pop(){
    if(size==0) return -1;
    //first swap the bottom most element and then move it to its correct position
    int num = arr[1];
    arr[1]=arr[size];
    //reduce size of tree
    size--;
    int index=1;
    //take the root to its correct position
    //only swap with the lower level's biggest candidate since only the biggest candidate can promote to the next level
    while(index<size){
        int left=index*2;
        int right=index*2+1;
        //check if current is lesser than left and left is greater than right
        if(left<=size && arr[index]<arr[left] && arr[left]>arr[right]){
            swap(arr[left],arr[index]);
            index=left;
        }
        //check if current is lesser than right and right is greater than left
        else if(right<=size && arr[index]<arr[right] && arr[right]>arr[left]){
            swap(arr[right], arr[index]);
            index=right;
        }
        else break;
    }
    return num;
}

int main(){
    maxheap sorter;
    vector<int> vec = {4,3,5,6,8,-1,2,3,6,734,52,7,3463,737,463,7734,632,62,43};
    sorter.heapify(vec);
    for(auto i : vec) cout<<i <<" ";
}