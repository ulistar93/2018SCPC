#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#define MAXMEM 200000
#define MAXK 1000000000

using namespace std;

int main(){
	fstream fs;
	fs.open("sample_input.txt", fstream::out);

	srand(time(NULL));
	
	cout << "Test case : ";
	int T;
	cin >> T;
	fs << T << endl;
//	int mem = rand() % MAXMEM;
//	int k = rand() % MAXK;

	for(int test_case = 0; test_case  < T; test_case++)
	{
		int mem,k;
		cout << "n k :";
		cin >> mem >> k;
		fs << mem << " " << k << endl;

		cout << "Do you need small k's value? (y/n) ";
		char c;
		cin >> c;
		int* arr = new int[mem];
		switch(c){
			case 'n': 
				for(int i=0; i<mem; i++){
					fs << (rand() % MAXK)+1 << " ";
				}
				break;
			case 'y':
				int maxK, degK;
				cout << "Max K : ";
				cin >> maxK;
				cout << "degree K : ";
				cin >> degK;
				for(int i=0; i<mem; i++){
					arr[i] = (rand()%(maxK/degK)+1)*degK;
				}
				sort(arr,arr+mem);
				for(int i=0; i<mem; i++){ fs << arr[i] << " ";}
				break;		
			default :
				cout << "Wrong input. Please try again." << endl;
				break;
		}
		delete arr;
		fs << endl;

	}
	fs.close();

	return 0;
}
