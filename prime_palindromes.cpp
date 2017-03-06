#include <cstring>
#include <cstdio>
#include <cmath>	

int all[110000], cnt = 0;

void gen_palindrome()
{
	// 1 / 2 digit
	all[cnt++] = 2; all[cnt++] = 3; all[cnt++] = 5; 
	all[cnt++] = 7; all[cnt++] = 11;
 	// 3 digit
 	for (int i = 1; i < 10; ++i)
 		for (int j = 0; j < 10; ++j)
 			all[cnt++] = i * 100 + j * 10 + i;
	// 4 digit
 	for (int i = 1; i < 10; ++i)
 		for (int j = 0; j < 10; ++j)
 			all[cnt++] = i * 1000 + j * 100 + j * 10 + i;
	// 5 digit
	for (int i = 1; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k)
				all[cnt++] = i * 10000 + j * 1000 + k * 100 + j * 10 + i;	 
	// 6 digit
	for (int i = 1; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k)
				all[cnt++] = i * 100000 + j * 10000 + k * 1000 + k * 100 + j * 10 + i;	 
	// 7 digit 
	for (int i = 1; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k)
				for (int l = 0; l < 10; ++l)
					all[cnt++] = i * 1000000 + j * 100000 + k * 10000 + l * 1000 + k * 100 + j * 10 + i;
	// 8 digit 
	for (int i = 1; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k)
				for (int l = 0; l < 10; ++l)
					all[cnt++] = i * 10000000 + j * 1000000 + k * 100000 + l * 10000 + l * 1000 + k * 100 + j * 10 + i;
	
	// 9 digit
	for (int i = 1; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k)
				for (int l = 0; l < 10; ++l)
					for (int m  = 0; m < 10; ++m)
						all[cnt++] = i * 100000000 + j * 10000000 + k * 1000000 + l * 100000 + m * 10000 + l * 1000 + k * 100 + j * 10 + i;
}

bool is_prime(int n) {
	int m = sqrt(n);
	for (int i = 2; i <= m; ++i)
		if (n % i == 0) return false;
	return true;
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	gen_palindrome();
	int i = 0;
	while (all[i] < a) i++;
	while (i < cnt && all[i] <= b) {
		if (is_prime(all[i]))
			printf("%d\n", all[i]);
		i++;	
	}
	return 0;
}
