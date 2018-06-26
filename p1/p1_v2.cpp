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
#include <list>
#define MAXMEM 200000
//#include <cstdio>
//#include <time.h>

using namespace std;

int Answer;

bool not_range_k(int a, int b, int k){
    return (b-a>k);
}

int main(int argc, char** argv)
{
    //setbuf(stdout, NULL);
    //clock_t begin, end;
    //begin = clock();
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

	//freopen("input.txt", "r", stdin);

    int* mem = new int[MAXMEM];
    int* rankTable = new int[MAXMEM];
    list<int> bus;
    
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
        int busCount = 1;
        rankTable[busCount]=1;
        bus.clear();
        bus.push_back(busCount);

        for(int i=2; i<n+1; i++){
            if( not_range_k(mem[rankTable[bus.back()]],mem[i],k) ){
                rankTable[bus.back()] = i;
            }else if( not_range_k(mem[rankTable[bus.front()]],mem[i],k) ){
                rankTable[bus.front()] = i;
                bus.push_back(bus.front());
                bus.pop_front();
            }else{
                busCount++;
                rankTable[busCount] = i;
                bus.push_back(busCount);
            }
        }
        Answer = busCount;
        // Print the answer to standard output(screen).
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
        
	}
	delete [] mem;
    delete [] rankTable;
    //end = clock();
    //cout << "Elapsed Time : " << (end-begin)/(float)CLOCKS_PER_SEC << endl;
	return 0;//Your program should return 0 on normal termination.
}
