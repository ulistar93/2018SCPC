#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <time.h>

#define MAXMEM 200000

using namespace std;

void swap(int* arr, int a, int b){
	int t = arr[a];
	arr[a] = arr[b];
	arr[b] = t;
	return;
}

int main(){
	fstream fs;
	fs.open("sample_input.txt", fstream::out);

	srand(time(NULL));
	
	cout << "Test case<=26 : ";
	int T;
	cin >> T;
	fs << T << endl;

	for(int test_case = 0; test_case  < T; test_case++)
	{
		int n,m;
		cout << "n 2~200000 / m 1~400000 x" << endl;
		cout << "n m(x) :";
		cin >> n;
		cout << " m is automatically determined" <<endl;
		m = 2*n-3;
		fs << n << " " << m << endl;

		fs << 1 << " " << 2 << endl;
		for(int i=3;i<n+1;i++){
			fs << i << " " << i-2 << endl; //3 1
			fs << i << " " << i-1 << endl; //3 2
			// 4 2
 			// 4 3
			// ...
			// n n-2
			// n n-1
		}


/*
		vector< list<int> > vert(n+1);
		int a,b;

		int* arr = new int[n];
		for(int i=0; i<n; i++){ arr[i]=i+1; }
		for(int i=0; i<n; i++){ swap(arr,rand()%n,rand()%n); }

		list<int> l(arr,arr+n);
		for(int i=0; i<m; i++){
			if(l.empty()){
				a = rand()%n +1;
				do{
					b = rand()%n +1;
				}while(a==b);
			}else if(l.size() == n){
				a = l.front();
				l.pop_front();
				b = l.front();
				l.pop_front();
			}else{
				a = l.front();
				l.pop_front();
				do{
					b = rand()%n +1;
				}while(a==b);
			}

			bool exist = false;
			list<int>::iterator it;
			for( it=vert[a].begin(); it!=vert[a].end(); it++){
				if(*it == b) exist = true;
			}
			if(!exist){
				vert[a].push_back(b);
				vert[b].push_back(a);
				fs << a << " " << b << endl;
			}else{ //exist
				i--;
			}


		}
*/
	}
	fs.close();

	return 0;
}
