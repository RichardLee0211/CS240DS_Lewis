#include<iostream>

using namespace std;

int swap(int* array, int p1, int p2){
    int tmp = array[p1];
    array[p1] = array[p2];
    array[p2] = tmp;
    return 0;
}

int selectionSort(int* array, int start, int end){
    if(start == end )
        return 0;
    int minIndex = start;
    for(int i=start; i<=end; i++){
        if(array[minIndex] >= array[i]){
            minIndex = i;
        }
    }
    swap(array, minIndex, start);
    selectionSort(array, start+1, end);
    return 0;
}

int insertSort(int* array, int start, int end){
    // just insert in front of array
    return 0;
}

int popSort(int* array, int start, int end){
    if(start == end)
        return 0;
    for(int i=end-1; i>=start; i--){
        if(array[i]>=array[i+1])
            swap(array, i, i+1);
    }
    popSort(array, start+1, end);
    return 0;
}

int print(int* array, int size){
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}

int main(){
    int array[] = {3, 4, 2, 5, 6, 19, 20, 43, 26, 452, 123, 41, 234, 342};
    //selectionSort(array, 0, sizeof(array)/sizeof(int)-1 );
    popSort(array, 0, sizeof(array)/sizeof(int)-1 );
    print(array, sizeof(array)/sizeof(int));
    return 0;
}
