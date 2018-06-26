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
#include <cstdio>

using namespace std;

int Answer;
clock_t begin, end;
bool candi_check(vector< list<int> > &vert, int i);
int reduce_vertex(vector< list<int> > &vert, int* rank, int n, list<int> &candi);

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
	fflush(stdout);
}

void print_candi(list<int> candi){
	cout << " -[[";
	list<int>::iterator it;
	for(it=candi.begin(); it!=candi.end(); it++){
		cout << " "<< *it;
	}
	cout << " ]]-"<<endl;
	fflush(stdout);
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
		list<int> candi;
		for(int i=1; i<n+1; i++){
			if(rank[i]==2){
				if(candi_check(vertex,i)) candi.push_back(i);
			}
		}
//print_vertex(vertex,rank,n_print);
//print_candi(candi);
		Answer = reduce_vertex(vertex,rank,n,candi);
		
		// Print the answer to standard output(screen).
//		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	end = clock();
	cout << "Elapsed Time : " << (end-begin)/(float)CLOCKS_PER_SEC << endl;

	return 0;//Your program should return 0 on normal termination.
}

bool candi_check(vector< list<int> > &vert, int i){
	int a,b;
	a = vert[i].front();
	b = vert[i].back();
	list<int>::iterator it;
	for(it=vert[a].begin(); it!=vert[a].end(); it++){
		if(*it == b) return true;
	}
	return false;
}

int reduce_vertex(vector< list<int> > &vert, int* rank, int n, list<int> &candi){
	end = clock();
//cout << "reduce "<< n <<" start : " << (end-begin)/(float)CLOCKS_PER_SEC << endl;
//print_vertex(vert,rank,n_print);
//print_candi(candi);

	if(candi.empty()) return n;

	int c = candi.front();
//cout << " removed candi : " << c << endl;
	int a,b;
	a = vert[c].front();
	b = vert[c].back();
	vert[a].remove(c);
	rank[a]--;
	if(rank[a]==2){ //if a is new candi
		if(candi_check(vert,a)) candi.push_back(a);
	}else if(rank[a]==1){ //if a was candi
		candi.remove(a);
	}
	vert[b].remove(c);
	rank[b]--;
	if(rank[b]==2){
		if(candi_check(vert,b)) candi.push_back(b);
	}else if(rank[b]==1){ //if a was candi
		candi.remove(b);
	}
	vert[c].pop_front(); //pop a
	vert[c].pop_front(); //pop b
	candi.pop_front();
	rank[c]=0;

	return reduce_vertex(vert,rank,n-1,candi);
}
