#include <iostream>
#include "Header.h"

unsigned int a = 1;
unsigned int a1 = 1;
unsigned int a0 = 0;


void menu() {
	cout << "Enter method number:";
	cin >> counter;
	while (counter <= 0 || counter >10) {
		cout << "Please, enter number from 1 to 10:";
		cin >> counter;
	}
	switch (counter) {
	case 1:
	{
		for (int i = 0; i < amount; i++) {
			randOut(rand_1(),0,1,10);
		}
		histOut(0,1,10);
		break;
	}
	case 2: {
		for (int i = 0; i < amount; i++) {
			randOut(rand_2(),0,1,10);
		}
		histOut(0,1,10);
		break;
	}
	case 3: {
		for (int i = 0; i < amount; i++) {
			randOut(rand_3(),0,1,10);
		}
		histOut(0,1,10);
		break;
	}
	case 4: {
		for (int i = 0; i < amount; i++) {
			randOut(rand_4(),0,1,10);
		}
		histOut(0,1,10);
		break;
	}
	case 5: {
		for (int i = 0; i < amount; i++) {
			randOut(rand_5(),0,1,10);
		}
		histOut(0,1,10);
		break;
	}
	case 6: {
		for (int i = 0; i < amount; i++) {
			randOut(rand_6(),-3,3,10);
	}
		histOut(-3,3,10);
		break;
	}
	case 7: {
		for (int i = 0; i < amount; i++) {
			randOut(rand_7(), -3, 3,10);
	}
		histOut(-3, 3,10);
		break;
	}
	case 8: {
		for (int i = 0; i < amount; i++) {
			randOut(rand_8(), 0, 3 ,10);
		}
		histOut(0, 3 ,10);
		break;
	}
	case 9: {
		for (int i = 0; i < amount; i++) {
			randOut(rand_9(), 0, 100,1);
		}
		histOut(0, 100,1);
		break;
	}
	case 10: {
		for (int i = 0; i < amount; i++) {
			randOut(rand_10(), 0, 100, 1);
		}
		histOut(0, 100, 1);
		break;
	}
	}
}

void randOut(double n, int min, int max,int delta) {
	cout << n << "\n";
	for (int i = min*delta; i < max*delta; i++) {
		if (delta * n > i && delta * n < i + 1) hist[i - (min*delta)]++;
	}

}
void histOut(int min,int max,int delta) {
	if (delta > 1)
	for (int i = min*delta; i < max*delta; i++) {
		cout << "[" << i << "/"<<delta<<"," << i + 1 << "/"<<delta<<"]:   " << hist[i - (min*delta)] / amount << "\n";
	}
	else for (int i = min*delta; i < max*delta; i++) {
		cout << "[" << i  << "," << i + 1 << "]:   " << hist[i - (min*delta)] / amount << "\n";
	}

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void generate_1() {
	a = (a * b + c) % m;
}

double rand_1() {
	generate_1(); return a / (m * 1.f);
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void generate_2() {
	a = (a * a * d + a * b + c) % m; 
}

double rand_2() { 
	generate_2(); return a / (m * 1.f); 
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void fib_n() {
		a1 += a0 % m;
		a0 = (a1 - a0) % m;
}
double rand_3() {
	fib_n(); 
	return a0 / (m * 1.f);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void generate_4() {
	a = (b*(a)^(-1) + c) % m;
}
double rand_4() {
	generate_4();
	return a / (m*1.f);
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double rand_5() {

	double x = rand_2();
	double y = rand_3();
	
	return abs((x-y));
}
//---------------------------------------------------------------------------------------------------------------------------------------
double rand_6() {
	double sum = 0;
	
	for (int i = 0; i < 12; i++) {
		double k = rand_1();
		sum += k;  
	}
	return s + (sum - 6)*sgm;
}
//---------------------------------------------------------------------------------------------------------------------------------------
double rand_7() {
	for (;;) {
		double u1 = rand_5(), u2 = rand_3();
		double v1 = 2 * u1 - 1, v2 = 2 * u2 - 1;
		double S = v1 * v1 + v2 * v2;
		if (S < 1) {
			double x1 = v1 * sqrt(-2 * log(S) / S);
			double x2 = v2 * sqrt(-2 * log(S) / S);
			if (rand_5() > 0.5) return x1;
			 else return x2;
		}
	}

}
//---------------------------------------------------------------------------------------------------------------------------------------
double rand_8() {
	for (;;) {
		double u = rand_3();
		double v = rand_5();
		double x = sqrt(8/e)*(v - 1 / 2) / u;
		if (x*x <= -4 * log(u))
			return x;
	}
}
//---------------------------------------------------------------------------------------------------------------------------------------
double rand_9() {
	for (;;) {
		double u = rand_3();
		if (u >= 0)
			return -mu*log(u);
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------

double rand_10() {
	for (;;) {
		double u = rand_2();
		double y = tan(pi*u);
		double x = sqrt(2 * mu - 1)*y + mu - 1;
		double v = rand_3();
		if (x > 0 && v < (1 + y*y)* exp((mu - 1)*log(x / (mu - 1)) - sqrt(2 * mu - 1)* y))
			return x;
	}
}