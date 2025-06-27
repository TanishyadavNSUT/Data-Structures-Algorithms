#include<iostream>
using namespace std;

//In selection sort, we selects the smallest value and put it at right place.
//Time complexity is O(n^2) for both best and worst case.

void printarray(int arr[],int n){
    for (int i = 0; i < n;i++){
        cout << arr[i] << " ";
    }
}

void selectionsort(int arr[],int n){
    for (int i = 0; i < n-1;i++){
        int minIndex = i;
        for (int j = i+1; j < n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main(){
    int arr[5] = {4, 2, 3, 5, 1};
    selectionsort(arr, 5);
    printarray(arr, 5);
}

//Stable and unstable algorithms:
/* Stable Algorithm:

A stable algorithm is one that maintains the relative order of elements with equal keys 
or values. This characteristic can be crucial when you sort a dataset multiple times
based on different criteria.

Example: Consider a list of student records where each record has a 'name' and 'grade'. 
If you sort by 'grade' and multiple students have the same 'grade', a stable algorithm will
maintain the original order of students with equal 'grades'. This property is beneficial 
when you have a dataset with layers of sorting criteria.

Unstable Algorithm:
An unstable algorithm may not preserve the relative order of elements with equal keys or 
values. When dealing with complex data, this can lead to unpredictable results if you plan 
to use multiple sorting operations.

Example: Using the same example of a list of student records, an unstable algorithm might 
change the original order of students with the same 'grade'. This can lead to unintended 
outcomes if you rely on the original sequence for other purposes.

Selection Sort:
Stability: Unstable.
Explanation: Selection sort finds the smallest (or largest) element and places it in the 
correct position, repeating this process for the remaining elements. When finding the minimum 
element, there's a possibility of rearranging elements with equal values, which makes it unstable.

Bubble Sort:
Stability: Stable.
Explanation: Bubble sort repeatedly swaps adjacent elements if they are in the wrong order. 
Because it swaps only adjacent elements, it maintains the relative order of equivalent elements, thus being stable.

Insertion Sort:
Stability: Stable.
Explanation: Insertion sort builds the sorted array one element at a time by inserting each 
new element into its correct position among previously sorted elements. This insertion maintains relative 
order, thus making the algorithm stable.*/

/* An in-place sort is a sorting algorithm that sorts a collection (like an array or list) using only 
a small, constant amount of additional storage space. This usually means that the sorting is done by 
rearranging the elements within the existing collection, rather than creating a new collection or
requiring significant extra space*/

//selection, bubble, insertion all are in place sorting algorithms.

