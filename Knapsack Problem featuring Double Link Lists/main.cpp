// File:    main.cpp
// Project: CSIS3400 Assignment 8
// Author:  Brandon Catalano 
// History:  1.1 Nov 1st, 2022
#include "SortDblLnkLst.h"
#include <iostream>
using namespace std;
//Array sorter to make 100% sure array is sorted.
void arraySort(int arr[]) {
	int temp, i, j;
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5 - 1; j++) {
			if (arr[j] < arr[i]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
//Recursive knapsack function
bool knapSack(int intArr[], int weight, int index,int size)
{
	//Counts total number of additions performed on intArr[index]
	int checkSum = -1;
	//self explanatory
	int total = 0;
	//checks if first index is not target weight
	if (intArr[index] != weight)
	{
		//cout << "Index is currently: " << index << " which holds value: " << intArr[index]<<endl;
		for (int i = index; i < size; i++)
		{
			total += intArr[i];

			checkSum += 1;
			/*
			cout << "Total: " << total<<endl;
			cout << "weight: " << weight;
			cout <<"Area 1"<< endl;
			cout << "I is currently: " << i<<endl;
			*/

			if ( (total > weight) && ( i<size )&& (i>index) )
			{
				/*
				cout << "Area 2" << endl;
				cout << "I check: " << i<<", which holds valuwe "<<intArr[i]<<endl;
				*/
				total = intArr[index];
				//Checksum is used to go back 1 less than the amount of additions performed to try and check
				//other number combinations.
				i -= checkSum-1;
				checkSum = 0;
				
				//cout<<"Also total is : "<<total<<endl;
			}
			//Runs if the total equals target weight.
			else if (total == weight)
			{
				cout << "Working combination found for target "<<weight<<endl<<endl;
				return true;
			}
			//Runs if we've reached the end of the array indexes and the last index doesnt match.
			else if ((index == size-1) && (total != weight))
			{
				cout<<"No possible combination found."<<endl<<endl;
				return false;
			}
			//Recursive call for when i reaches the maximum value of 4 and the target weight was not found.
			else //if (i==size-1)
			{
				//cout << "Area 3" << endl;
				knapSack(intArr, weight, index + 1,size);
			}

		}

	}
	//activates if first index is target weight
	else
	{
		cout << "Combination found: " << intArr[index] << " at index " << index <<
			" in the array is equal to target weight of " << weight << endl << endl;
		return 1;
	}
	return 0;

}

int main()
{
	int intArr[5] = { 2, 10, 21, 3, 5 };
	arraySort(intArr);
	knapSack(intArr, 24, 0, sizeof(intArr) / sizeof(int));
	/*
	SortDblLnkLst<string> h;
	h.putItem("dog1");
	h.putItem("dog3");
	h.putItem("dog2");
	cout << endl << endl;
	h.printItems();
	h.printItemsReverse();
	h.putItem("dog4");
	h.printItems();
	h.deleteItem("dog3");
	h.printItems();
	h.deleteItem("dog4");
	h.printItems();
	cout << "G list declaration" << endl;
	SortDblLnkLst<string> g(h);
	g.printItems();
	g.putItem("g list here, yo.");
	g.printItems();
	h.putItem("h list here, yo.");
	h.printItems();

	cout << "f integer linklist declaration" << endl << endl;
	SortDblLnkLst<int>f;
	f.putItem(1);
	f.putItem(2);
	f.putItem(45);
	
	SortDblLnkLst<int>c;
	c = f;
	c.printItems();
	c.printItemsReverse();
	
	//*/
	return 0;


}
