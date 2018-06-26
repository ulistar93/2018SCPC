/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <list>
#define MAXMEM 200000

using namespace std;

int Answer;
int get_candi(vector< list<int> > &vert, int* rank, int n);
int reduce_vertex(vector< list<int> > &vert, int* rank, int n, int candi);

int main(int argc, char** argv)
{
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

	// freopen("input.txt", "r", stdin);

	cin >> T;
	int* rank = new int[MAXMEM];

	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		int n,m;
		cin >> n >> m;
		for(int i=1; i<n+1; i++) rank[i]=0;
		vector< list<int> > vertex(n+1);

		int v,u;
		for(int i=0; i<m; i++){
			cin >> v >> u;
			vertex[v].push_back(u);
			vertex[u].push_back(v);
			rank[v]++; rank[u]++;
		}
		int candi = get_candi(vertex,rank,n);
		Answer = reduce_vertex(vertex,rank,n,candi);
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}

int get_candi(vector< list<int> > &vert, int* rank, int n){
	//return a candidate.
	//not a set, just one member. because the order of erasing is no matter.
	int a,b;
	for(int i=0;i<n;i++){
		if(rank[i]==2){
			a = vert[i].front();
			b = vert[i].back();
			list<int>::iterator it;
			for(it=vert[a].begin(); it!=vert[a].end(); it++){
				if(*it == b){
//					cout << "candi : " << i << endl;
					return i;
				}
			}
		}
	}
	return -1;
}

int reduce_vertex(vector< list<int> > &vert, int* rank, int n, int candi){
//	cout << "reduce " << n << endl;
	if(candi == -1) return n;

	int a,b;
	a = vert[candi].front();
	b = vert[candi].back();
	vert[a].remove(b);
	vert[b].remove(a);
	rank[a]--; rank[b]--;
	vert[candi].pop_front(); //pop a
	vert[candi].pop_front(); //pop b
	rank[candi]=0;

	return reduce_vertex(vert,rank,n-1,get_candi(vert,rank,n-1));
}
