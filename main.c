#include <stdio.h>

#define MAXN 1000

int solutions[MAXN+1];

void iteratepittriplets();

int main()
{
    iteratepittriplets();
    int maxsols = -1;
    int valmax = -1;
    for(int i = 1; i <= MAXN; i++){
        if(solutions[i]> maxsols){
            maxsols = solutions[i];
            valmax = i;
        }
    }

    printf("%d\n", valmax);
}


typedef struct {
	int a;
	int b;
	int c;
} triplet;

struct {
	triplet stack[10000000];
	int front;
} stack;

#define init(s) ((s).front = -1)
#define isempty(s) ((s).front == -1)
#define any(s) ((s).front != -1)
#define push(s, x) ((s).stack[++((s).front)] = (x))
#define pop(s) ((s).stack[(s).front--])
#define top(s) ((s).stack[(s).front])


void accounttriplet(triplet t) {
	int perim0 = t.a + t.b + t.c;
	for (int perim = perim0, a = t.a, b = t.b, c = t.c; perim <= MAXN; perim += perim0, a += t.a, b += t.b, c += t.c) {
		solutions[perim]++;
	}
}

void iteratepittriplets() {

	init(stack);

	triplet t1 = { 3, 4, 5 };

	push(stack, t1);
	while (any(stack)) {
		triplet t2 = pop(stack);
		int perim = t2.a + t2.b + t2.c;
		if (perim >= MAXN)
			continue;

		accounttriplet(t2);

		//variant 1
		t1.a = t2.a - 2 * t2.b + 2 * t2.c;
		t1.b = 2 * t2.a - t2.b + 2 * t2.c;
		t1.c = 2 * t2.a - 2 * t2.b + 3 * t2.c;

		push(stack, t1);

		//variant 2
		t1.a = t2.a + 2 * t2.b + 2 * t2.c;
		t1.b = 2 * t2.a + t2.b + 2 * t2.c;
		t1.c = 2 * t2.a + 2 * t2.b + 3 * t2.c;

		push(stack, t1);

		//variant 3
		t1.a = -t2.a + 2 * t2.b + 2 * t2.c;
		t1.b = -2 * t2.a + t2.b + 2 * t2.c;
		t1.c = -2 * t2.a + 2 * t2.b + 3 * t2.c;

		push(stack, t1);

	}
}