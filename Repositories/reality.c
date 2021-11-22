#include <stdio.h>
#include <math.h>

int equal(float x, float y, float epsilon) {
	return fabs(x-y) < epsilon;
}

void associative_function() {
	printf("ASSOCIATIVE FUNCTION: \n");

	float x = 1000000.0f;

	printf("1000000.0f + 0.01f == 1000000.0f: %d\n", x + 0.01f == x); // 1000000.0f + 0.01f = 1000000.0f

	printf("-1000000.0f + (1000000.0f + 0.01f) == 0.0f: %d\n(-1000000.0f + 1000000.0f) + 0.01f == 0.01f: %d\n",
		-x + (x + 0.01f) == 0.0f, // -1000000.0f + (1000000.0f + 0.01f) = 0.0f
		(-x + x) + 0.01f == 0.01f); // (-1000000.0f + 1000000.0f) + 0.01f = 0.01f
}

void float_compiler_optimize() {
	printf("\nFLOAT COMPILER OPTIMIZE TEST: \n");

	float a1 = 1.1;
	float b1 = 2.2;
	float c1 = 3.3;
	float d1 = 4.4;

	float x1 = a1 + b1 + c1;
	float y1 = b1 + c1 + d1;

	printf("%f %f\n", x1, y1);

	float a2 = 1.1;
	float b2 = 2.2;
	float c2 = 3.3;
	float d2 = 4.4;

	float temp = b2 + c2;
	float x2 = a2 + temp;
	float y2 = temp + d2;

	printf("%f %f\n", x2, y2);
}

int main() {
	associative_function();
	float_compiler_optimize();

	int equal_test = equal(0.01, 0.0123, 0.0022);
	int equal_test1 = equal(0.01, 0.0123, 0.0024);
	printf("\nequal_test (0.01, 0.0123, 0.0022): %d\nequal_test1 (0.01, 0.0123, 0.0024): %d\n", equal_test, equal_test1);
}

