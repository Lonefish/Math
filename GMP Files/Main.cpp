#include <stdio.h>			/* for printf */
#include <gmp.h>
 
int main(int argc, char *argv[])
{

	mpz_t base, exp;                 		/* working numbers */
	mpz_t result, mod, tempmod;
	unsigned int modExp = 10;


	mpz_init_set_str (base, "3", 10);	/* Assume decimal integers */
	mpz_init_set_str (result, "0", 10);	/* init empty result */
	mpz_init_set_str (exp, "3", 10);	/* Assume decimal integers */
  	mpz_init_set_str (mod, "100", 10);	/* Assume decimal integers */
	
  	mpz_powm(result,base,exp, mod);
	//mpz_pow_ui(tempmod, mod, modExp);
	//mpz_init_set(mod, tempmod);

  	printf("%s ^ %s m %s => %s\n", mpz_get_str (NULL, 10, base), 			mpz_get_str(NULL, 10,exp),mpz_get_str (NULL, 10, mod), mpz_get_str (NULL, 10, result));
  	return 0;
}


