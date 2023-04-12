#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

int list[10] = {0,1,2,3,4,5,6,7,8,9};

int checkA(int,int);
int checkB(int,int);

int main() {
	srand(time(NULL));
	
	int answer=0;
	int x;
	for(int i=0; i<4; i++) {
		answer *= 10;
		do {
			x = rand()%10;
		} while(list[x] == -1);
		
		answer += x;
		list[x] = -1;
	}
	
	int turn=1, guess;
	int A, B;
	bool success = false;
	cout << "Random number appears, take a guess. (note : if you want to quit the game, enter -1)" << endl;
	while(!success) {
		cout << "guess " << turn << ": ";
		cin >> guess;
		if(guess==-1) break;
		A = checkA(answer,guess);
		B = checkB(answer,guess) - A;
		cout << A << "A" << B << "B" << endl << endl;
		if(A==4) success = true;
		turn++;
	}
	if(success)	cout << "congratulation!" << endl;
	else	cout << endl << "Alright, let's end the game, busy man." << endl;
	
	return 0;
}

int checkA(int a, int n) {
	int A = 0;
	for(int i=0; i<4; i++) {
		if(a%10 == n%10) {
			A++;
		}
		a /= 10;
		n /= 10;
	}
	return A;
}

int checkB(int a, int n) {
	int B = 0;
	for(int i=0; i<4; i++) {
		if(list[n%10] == -1) {
			B++;
		}
		n /= 10;
	}
	return B;
}
