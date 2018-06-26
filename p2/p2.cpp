/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
//#include <cstdio>

using namespace std;

int count_digit(int num){
	int a,b,c,d,e;
	e = num%10;
	d = (num/10)%10;
	c = (num/100)%10;
	b = (num/1000)%10;
	a = (num/10000)%10;
	return a? 5:(b? 4:(c? 3:(d? 2:(e? 1:0))));
}

int reduce_5(int& );
int reduce_4(int& );
int reduce_3(int& );
int reduce_2(int& );

int Answer[4] = {0};

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

//	freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		int num,a,b,c,d,e;
		cin >> num;
		int digit = count_digit(num);
		int cnt = 0;

		for(int i=0; i<4; i++){
			switch(digit){
				case 5:
					Answer[cnt] = reduce_5(num);
					cnt++;
					digit = count_digit(num);
					break;
				case 4:
					Answer[cnt] = reduce_4(num);
					cnt++;
					digit = count_digit(num);
					break;
				case 3:
					Answer[cnt] = reduce_3(num);
					cnt++;
					digit = count_digit(num);
					break;
				case 2:
					Answer[cnt] = reduce_2(num);
					cnt++;
					digit = count_digit(num);
					break;
				case 1:
					Answer[cnt] = num;
					cnt++;
					num -= num; // num==0
					digit = 0;
					break;
				case 0:
					Answer[cnt] = 0;
					cnt++;
					digit = 0;
					break;
			}
		}
		cnt=0;
		for(int i=0; i<3; i++){
			if(Answer[i]!=0) cnt++;
		}
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		if(cnt>3){
			cout << "0" << endl;
		}else{
			cout << cnt << " ";
			for(int i=0; i<cnt; i++){
				cout << Answer[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;//Your program should return 0 on normal termination.
}

int reduce_5(int &num){
	int t_num = num;
	int a,b,c;
	a = (t_num/10000)%10;
	b = (t_num/1000)%10;
	c = (t_num/100)%10;
	int r_num = a*10000 + b*1000 + c*100 + b*10 + a; //abcba
	if( t_num - r_num < 0 ){
		t_num -= 100;
		a = (t_num/10000)%10;
		b = (t_num/1000)%10;
		c = (t_num/100)%10;
		if(a!=0){
			r_num = a*10000 + b*1000 + c*100 + b*10 + a; //abc'ba 
		}else{ // a'==0 b==9
			r_num = b*1000 + c*100 + c*10 + b; // bccb
		}
		num = num - r_num;
		return r_num;
	}else{ //t_num > r_num
		num = num - r_num;
		return r_num;
	}
}

int reduce_4(int &num){
	int t_num = num;
	int b,c;
	b = (t_num/1000)%10;
	c = (t_num/100)%10;
	int r_num = b*1000 + c*100 + c*10 + b; //bccb
	if( t_num - r_num < 0 ){
		t_num -= 100;
		b = (t_num/1000)%10;
		c = (t_num/100)%10;
		if(b!=0){
			r_num = b*1000 + c*100 + c*10 + b; //bc'c'b 
		}else{ // b'==0 c==9 //1000
			r_num = c*100 + 9*10 + c; // c9c // actually, it's 999
		}
		num = num - r_num;
		return r_num;
	}else{ //t_num > r_num
		num = num - r_num;
		return r_num;
	}
}

int reduce_3(int &num){
	int t_num = num;
	int c,d;
	c = (t_num/100)%10;
	d = (t_num/10)%10;
	int r_num = c*100 + d*10 + c; //bccb
	if( t_num - r_num < 0 ){
		t_num -= 10;
		c = (t_num/100)%10;
		d = (t_num/10)%10;
		if(c!=0){
			r_num = c*100 + d*10 + c; //cd'c
		}else{ // c'==0 d==9 //100
			r_num = d*10 + 9; // d9 // actually, it's 99
		}
		num = num - r_num;
		return r_num;
	}else{ //t_num > r_num
		num = num - r_num;
		return r_num;
	}
}

int reduce_2(int &num){
	int t_num = num;
	int d,e;
	d = (t_num/10)%10;
	e = t_num%10;
	int r_num = d*10 + d; //dd
	if( t_num - r_num < 0 ){
		t_num -= 10;
		d = (t_num/10)%10;
		e = t_num%10;
		if(d!=0){
			r_num = d*10 + d; //d'd' 
		}else{ // de = 10
			r_num = 9; // 10 = 9+1 = 8+2 ...
					// actually, this case will not be occur. becuase reduce 3 erase the decimal digit
		}
		num = num - r_num;
		return r_num;
	}else{ //t_num > r_num
		num = num - r_num;
		return r_num;
	}
}
