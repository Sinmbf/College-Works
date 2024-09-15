/* Prove using rules of inference
	p->q
	q->r
	p->r
*/

#include<stdio.h>

// Rules of Inference
// if p is true then q is true
// a=b=c => a=c

// Function to represent implication (p->q)
int implies(int p, int q) {
	return !p || q; // Equivalent to "not p or q" in logic
}

// Function to apply Modus Ponens for (p->q) and (q->r)
void modus_ponens_chain(int p, int q, int r) {
	printf("Given: p = %d, q = %d, r = %d\n",p,q,r);
	// Check if p -> q holds
	if(implies(p,q)) {
		printf("p -> q is True (Implication holds).\n");
		// Check if p is True, then q must be True
		if(p) {
			printf("p is True, so q must be True.\n");

			// Check if q->r holds
			if(implies(q,r)) {
				printf("q -> r is True (Implication holds).\n");
				// If q is true, then r must be True
				if(q) {
					printf("Since q is True, r must be True.\n");
					printf("Therefore, by Modus Ponens, p -> r holds.\n");
				}
			} else {
				printf("q -> r is False(Implication does not hold).\n");
			}

		} else {
			printf("p is False. Cannot apply Modus Ponens.\n");
		}
	} else {
		printf("p -> q is False. (Implication does not hold).\n");
	}
}

int main(){
	// Example: p=1, q=1, r=1 (Modus Ponens will succeed)
	int p1=1; // True
	int q1=1; // True
	int r1=1; // True
	modus_ponens_chain(p1,q1,r1);
	printf("\n");
	// Example: p=1, q=1, r=0 (Modus Ponens fails at q->r)
	int p2=1; // True
	int q2=1; // True
	int r2=0; // False
	modus_ponens_chain(p2,q2,r2);
	return 0;
}