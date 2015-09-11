#include <stdio.h>			/* for printf */
#include <gmp.h>
 
int main(int argc, char *argv[])
{

	mpz_t base, exp;                 		/* working numbers */
	mpz_t result, mod, tempmod, tempresult;
	unsigned int modMul = 10;


	mpz_init_set_str (base, "3", 10);	/* Assume decimal integers */
	mpz_init_set_str (result, "0", 10);	/* init empty result */
	mpz_init_set_str (exp, "3", 10);	/* Assume decimal integers */
  	mpz_init_set_str (mod, "10", 10);	/* Assume decimal integers */
	mpz_init_set_str (tempmod, "0", 10);
	mpz_init_set_str (tempresult, "0", 10);

  	mpz_powm(result,base,exp, mod);
	mpz_mul_ui (tempmod , mod, modMul);
	mpz_init_set(mod, tempmod);
	printf("%s Result\n", mpz_get_str(NULL, 10, result));
	for(int j = 0; j < 10; j++) {	
		for(int i = 0; i < 500; i++) {
			mpz_powm(tempresult,base,result, mod );
			mpz_mul_ui (tempmod , mod, modMul);
			mpz_init_set(mod, tempmod);
			mpz_init_set(result, tempresult);
		}
		printf("Step %d\n", j);
	}
  	printf("Rightmost digits => %s\n",mpz_get_str (NULL, 10, result));
  	return 0;
}


