#include <stdio.h>			/* for printf */
#include <gmp.h>
 
int main(int argc, char *argv[])
{

	mpz_t base, exp;                 		/* working numbers */
	mpz_t result, mod, tempmod, tempresult;

	unsigned int modMul = 10;

	mpz_init_set_str (base, "3", 10);	// Set base
	mpz_init_set_str (result, "0", 10);	// Init variable
	mpz_init_set_str (exp, "3", 10);	// Set initial exponent
  	mpz_init_set_str (mod, "10", 10);	// Set modulo 10
	mpz_init_set_str (tempmod, "0", 10);  	// Init variable
	mpz_init_set_str (tempresult, "0", 10); // Init variable


	//Base calculation
  	mpz_powm(result,base,exp, mod);
	mpz_mul_ui (tempmod , mod, modMul);
	mpz_init_set(mod, tempmod);
	//printf("%s Result\n", mpz_get_str(NULL, 10, result));

	//Calculate 3 to the current power. Modulo 10^nth calculation
	for(int j = 0; j < 10; j++) {	
		for(int i = 0; i < 500; i++) {
			/*
			* Power of 3 to the result of the previous calculation, 
			* mod 10^i+1.
			* Result is stored in temp variable
			* Mod is multiplied by 10
			* Result and mod are copied back
			*/
			mpz_powm(tempresult,base,result, mod );
			mpz_mul_ui (tempmod , mod, modMul);
			mpz_init_set(mod, tempmod);
			mpz_init_set(result, tempresult);
			mpz_init_set(tempcounter, tempmod);
		}
		printf("Step %d\n", j);
	}
  	printf("Rightmost digits => %s\n",mpz_get_str (NULL, 10, result));
  	return 0;
}


