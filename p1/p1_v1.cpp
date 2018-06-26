//ulistar93@unist.ac.kr
//github.com/ulistar93
//Free to use without commercialization or plagiarism problem

//SCPC code

/*
You should use the statndard input/output
in order to receive a score properly.
Do not use file input and output
Please be very careful. 
*/

#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAXMEM 200000
#include <time.h>
using namespace std;

int Answer;

bool not_range_k(int a, int b, int k){
	return (b-a>k);
}

int main(int argc, char** argv)
{
	clock_t begin, end;
	begin = clock();
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	
	//freopen("sample_input.txt", "r", stdin); //erase // of #include <cstdio> too to use this

	int* mem = new int[MAXMEM];
	int* rankTable = new int[MAXMEM];

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;

		int n,k;
		cin >> n >> k;

		mem[0]=0;
		rankTable[0]=0;
		for(int i=1; i<n+1; i++){
			cin >> mem[i];
			rankTable[i]=0;			
		}
		sort(mem+1,mem+n);
		rankTable[1]=1;
		int busCount = 1;
		for(int i=2; i<n+1; i++){
			for(int r=1; r<n+1; r++){
				if( not_range_k(mem[rankTable[r]], mem[i], k) ){
					rankTable[r]=i;
					if(busCount < r) busCount = r;
					break;
				}
			}
		}
		Answer = busCount;
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
/*		cout << " n k " << n << k << endl;
		cout << " mem[] : ";
		for(int i=0;i<n+1;i++) cout << mem[i] << " ";
		cout << endl;
		cout << " rnT[] : ";
		for(int i=0;i<n+1;i++) cout << rankTable[i] << " ";
		cout << endl << "Answer : ";
*/		cout << Answer << endl;
	}

	delete [] mem;
	delete [] rankTable;
	end = clock();
	cout << "Elapsed Time : " << (end-begin)/(float)CLOCKS_PER_SEC << endl;
	return 0;//Your program should return 0 on normal termination.
}
