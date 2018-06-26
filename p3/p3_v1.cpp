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
#include <time.h>

using namespace std;

int Answer;
clock_t begin, end;
int get_candi(vector< list<int> > &vert, int* rank, int n);
int reduce_vertex(vector< list<int> > &vert, int* rank, int n, int candi);

void print_vertex(vector< list<int> > &vert, int* rank, int n){
	cout << " -r-------------------------"<<endl;
	for(int i=0;i<n+1;i++){
		cout << " -   ("<< rank[i] <<") vert["<<i<<"]";
		for(list<int>::iterator it=vert[i].begin(); it!=vert[i].end(); it++){
			cout << "-" << *it;
		}
		cout << endl;
	}
	cout << " ---------------------------"<<endl;
}
int n_print;
bool p = false;

int main(int argc, char** argv)
{
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

	// freopen("input.txt", "r", stdin);

	cin >> T;
	int* rank = new int[MAXMEM];

	for(test_case = 0; test_case  < T; test_case++)
	{
		cout << "Case #" << test_case+1 << endl;
		Answer = 0;
		int n,m;
		cin >> n >> m;
n_print = n;
		for(int i=1; i<n+1; i++) rank[i]=0;
		vector< list<int> > vertex(n+1);

		int v,u;
		for(int i=0; i<m; i++){
			cin >> v >> u;
			vertex[v].push_back(u);
			vertex[u].push_back(v);
			rank[v]++; rank[u]++;
		}
if(p) print_vertex(vertex,rank,n_print);
		int candi = get_candi(vertex,rank,n);
		Answer = reduce_vertex(vertex,rank,n,candi);
		
		// Print the answer to standard output(screen).
//		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	end = clock();
	cout << "Elapsed Time : " << (end-begin)/(float)CLOCKS_PER_SEC << endl;

	return 0;//Your program should return 0 on normal termination.
}

int get_candi(vector< list<int> > &vert, int* rank, int n){
	//return a candidate.
	//not a set, just one member. because the order of erasing is no matter.
	int a,b;
//	cout << "in get_candi" << endl;
	for(int i=0;i<vert.size();i++){
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
	end = clock();
if(p) cout << "reduce "<< n <<" start : " << (end-begin)/(float)CLOCKS_PER_SEC << endl;
if(p) print_vertex(vert,rank,n_print);

	if(candi == -1){ 
//		cout << " fail candi" <<endl;
		return n; }

if(p) cout << " removed candi : " << candi << endl;
	int a,b;
	a = vert[candi].front();
	b = vert[candi].back();
	vert[a].remove(candi);
	vert[b].remove(candi);
	rank[a]--; rank[b]--;
	vert[candi].pop_front(); //pop a
	vert[candi].pop_front(); //pop b
	rank[candi]=0;

	return reduce_vertex(vert,rank,n-1,get_candi(vert,rank,n-1));
}
