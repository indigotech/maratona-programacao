#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* How many lucky numbers are there in the interval [0, 10^k)? */
const unsigned long long answer_0[20] = {
                      1,  /* k =  0 */
                      9,  /* k =  1 */
                     80,  /* k =  2 */
                    711,  /* k =  3 */
                   6319,  /* k =  4 */
                  56160,  /* k =  5 */
                 499121,  /* k =  6 */
                4435929,  /* k =  7 */
               39424240,  /* k =  8 */
              350382231,  /* k =  9 */
             3114015839,  /* k = 10 */
            27675760320,  /* k = 11 */
           245967827041,  /* k = 12 */
          2186034683049,  /* k = 13 */
         19428344320400,  /* k = 14 */
        172669064200551,  /* k = 15 */
       1534593233484559,  /* k = 16 */
      13638670037160480,  /* k = 17 */
     121213437100959761,  /* k = 18 */
	1077282263871477369,  /* k = 19 */
};

/* How many lucky numbers are there in the interval [10^k, 2*10^k)? */
const unsigned long long answer_1[20] = {
                     1,  /* k =  0 */
                     8,  /* k =  1 */
                    71,  /* k =  2 */
                   631,  /* k =  3 */
                  5608,  /* k =  4 */
                 49841,  /* k =  5 */
                442961,  /* k =  6 */
               3936808,  /* k =  7 */
              34988311,  /* k =  8 */
             310957991,  /* k =  9 */
            2763633608,  /* k = 10 */
           24561744481,  /* k = 11 */
          218292066721,  /* k = 12 */
         1940066856008,  /* k = 13 */
        17242309637351,  /* k = 14 */
       153240719880151,  /* k = 15 */
      1361924169284008,  /* k = 16 */
     12104076803675921,  /* k = 17 */
    107574767063799281,  /* k = 18 */
	956068826770517608,  /* k = 19 */
};

unsigned long long N;

unsigned long long is_pow10_(unsigned long long n) {
	while (n % 10 == 0) {
		n /= 10;
	}
	return (n == 1);
}

unsigned long long exp10_(unsigned long long n) {
	unsigned long long e = 0;
	while (n % 10 == 0) {
		n /= 10;
		e++;
	}
	return e;
}

unsigned long long pow10_(unsigned long long k) {
	unsigned long long n = 1;
	while (k--) n *= 10;
	return n;
}

unsigned long long floor_to_pow10_(unsigned long long n, unsigned long long k) {
	return (n / pow10_(k)) * pow10_(k);
}

unsigned long long largest_pow10_(unsigned long long n) {
	unsigned long long p = 1;
	while (p <= n / 10) p *= 10;
	return p;
}

/* Count how many lucky floors exist in the interval [A, B). */
unsigned long long lucky_floors(unsigned long long A, unsigned long long B) {
	unsigned long long D = B - A;
	if (!is_pow10_(D)) {
		unsigned long long C = A + largest_pow10_(D);
		return lucky_floors(A, C) + lucky_floors(C, B);
	}
	char buf[21];
	sprintf(buf, "%llu", A);
	if (strstr(buf, "4") || strstr(buf, "13")) {
		return 0;
	}
	if ((A / D) % 10 == 1) {
		return answer_1[exp10_(D)];
	} else {
		return answer_0[exp10_(D)];
	}
}

int main() {
	while (scanf("%llu", &N) != EOF) {
		/* Loop invariant: lucky_floors(0, lo) < N+1,
		 *                 lucky_floors(0, hi) >= N+1.
		 */
		unsigned long long lo = 1, hi = ~0ULL;
		while (hi - lo > 1) {
			unsigned long long mid = lo + (hi - lo) / 2;
			if (lucky_floors(0, mid) < N+1) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		printf("%llu\n", hi-1);
	}
	return 0;
}
