#include<iostream>
using namespace std;

int main(){
	int arr[100], size;
	
	cout << "Enter the size: "<< endl;
	cin >> size;

	cout << "Enter the array elements: "<< endl; // msg not come to CLI
	for(int i=0; i<size; i++){
		cin >> arr[i];
	}

	cout << "The entered array is: ";
	for(int i = 0; i<size; i++){
		cout << arr[i]<< "";
	}


	return 0;
}