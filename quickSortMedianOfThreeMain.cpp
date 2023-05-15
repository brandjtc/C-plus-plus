// File:    quickSortMedianOfThreeMain.cpp
// Project: CSIS3400 Assignment 11
// Author:  Brandon Catalano 
// History:  1.2 Nov 22nd, 2022



#include <iostream>
using namespace std;
//displays sorted array.
static int F[] = {18, 5, 1, 3, 9, 7, 2, 12, 99, 6, 21};
static const int numValues = 11;
static int F2[] = { 18, 5, 1, 3, 9, 7, 2, 12, 99, 6, 21 };



void display(int arr[])
{
    for (int i = 0; i < numValues; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void medianOfThree(int first, int last, int* arr)
{
    int midVal = first + last;
    midVal += midVal % 2;
    midVal /= 2;
    //cout << endl << "this is first: " << first << endl;
    //cout << endl << "this is last: " << last << endl;
    //cout << endl << "This is midval: " << midVal << endl;

    if (arr[first] > arr[last])
        swap(first, last);

    if (arr[first] > arr[midVal])
        swap(first, midVal);

    if (arr[midVal] > arr[last])
        swap(midVal, last);

    swap(arr[first], arr[midVal]);


}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Split function modified to use median of three rule.

int split(int first, int last, int *arr)
{
    medianOfThree(first, last, arr);
    //int counter = 0;
   
    int splitVal = arr[first];
    int saveF = first;
    bool onCorrectSide;
    first++;
    do
    {
        onCorrectSide = true;
        while (onCorrectSide)
        {
            if (arr[first] > splitVal)
                onCorrectSide = false;
            else
            {
                first++;
                onCorrectSide = (first <= last);
            }
            //counter++;
        }
        onCorrectSide = (first <= last);
        while (onCorrectSide)
        {
            if (arr[last] <= splitVal)
                onCorrectSide = false;
            else
            {
                last--;
                onCorrectSide = (first <= last);
            }
           // counter++;
        }
        if (first < last)
        {
            swap(arr[first], arr[last]);
            first++;
            last--;
        }
    } while (first <= last);
    swap(arr[saveF], arr[last]);
    cout << endl;
    //cout << "Counter is: " << counter << endl;
    display(arr);
    return last;
}

void quickSort(int first, int last, int *arr)
{
    if (first < last)
    {
        int splitPoint;
        splitPoint = split(first, last, arr);
        //F[first].......F[splitPoint-1] <= splitVal
        //F[splitPoint] = splitValue
        //F[splitPoint+1].......F[last] > splitVal
        quickSort(first, splitPoint - 1, arr);
        quickSort(splitPoint + 1, last, arr);
    }
}

//Iterative version of quicksort.
void quickSortIterative(int first, int last, int* arr)
{
    int stack[numValues];
    //int counter = 0;
    int topVal = 0;
    stack[topVal++] = first;
    //cout << "First stack is: " << stack[topVal-1] << endl;
    stack[topVal++] = last;
   // cout << "Last stack is: " << stack[topVal - 1] << endl;
   // cout << "Last is: " << last << " and first is: " << first << endl;
    //cout << "Top is " << topVal << endl;
    while (topVal >= 0)
    {

        cout << "TopVal Check: " << topVal << endl;
        last = stack[--topVal];
    
   
        first = stack[--topVal];
        cout << "TopVal Check: " << topVal << endl;

        if (topVal <= 0)
        {
            //cout << "Go home, you're drunk" << endl;
            break;
        }
    
        //cout << "Last is: " << last << " and first is: " << first<<endl;

        
        //cout << endl<<"First, mid, last" << endl;
        //cout <<endl<< first << ", " << midVal << ", " << last<<endl;

        //cout <<"post median"<<endl;

        //cout << "First, mid, last" << endl;
        //cout << first << ", "<<midVal<< ", " << last<<endl;
        int splitPoint=split(first, last, arr);
        if (splitPoint-1 > first) {

            stack[topVal++] = first;
           // cout << endl << "Added first: " << first << endl;
            stack[topVal++] = splitPoint - 1;
           //cout << endl << "Added midVal - 1: " << midVal - 1 << endl;

        }

        if (splitPoint+1 < last)
        {

            stack[topVal++] = splitPoint + 1;
          //  cout << endl << "Added midval+1: " << midVal + 1 << endl;
            stack[topVal++] = last;
            //cout << endl << "Added last: " << last << endl;
        }
    }
    
}

int main()
{   //*
    cout << "Array before Sorting recursively" << endl;
    display(F);
    cout << "-----------------------------------" << endl;
    quickSort(0, numValues-1, F);
    cout << "-----------------------------------" << endl;
    cout << "Array After Sorting recursively" << endl;
    display(F);

    cout << endl;
    cout << endl;

    cout << "sorted Array before Sorting recursively" << endl;
    display(F);
    cout << "-----------------------------------" << endl;
    quickSort(0, numValues - 1, F);
    cout << "-----------------------------------" << endl;
    cout << "sorted Array After Sorting recursively" << endl;
    display(F);

    cout << endl;
    cout << endl;

    //*/
    cout << "Array before Sorting iteratively" << endl;
    display(F2);
    cout << "-----------------------------------" << endl;
    quickSortIterative(0, numValues - 1, F2);
    cout << "-----------------------------------" << endl;
    cout << "Array After Sorting iteratively" << endl;
    display(F2);
    return 0;
    //*/

}