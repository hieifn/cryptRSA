#include <stdlib.h>
#include <stdio.h>

unsigned long long 
mod(unsigned long long a1, unsigned long long b1){

	long long r1 = a1 % b1;

    /* Uma correçã é necessária se r e b não forem do mesmo sinal */

    /* se r for negativo e b positivo, precisa corrigir */
	if ((r1 < 0) && (b1 > 0))
		return (b1 + r1);

    /* Se ra for positivo e b negativo, nova correcao */
	if ((r1 > 0) && (b1 < 0))
		return (b1 + r1);

	return (r1);
}

unsigned long long 
euclides_ext(unsigned long long a, unsigned long long b, unsigned long long c){
{
	unsigned long long r;

	r = mod(b, a);

	if (r == 0) {
		return (mod((c / a), (b / a)));   // retorna (c/a) % (b/a)
	}

	return ((euclides_ext(r, a, -1*c) * b + c) / (mod(a, b)));
}
int
main(){

	long long n = 10142789312725007;

	unsigned long long d;

	unsigned long long i;

	for( i  = pow( n, 0.5); i > 3; i-=2)
		if (n%i == 0)
		{
			printf("P: %llu \n\n",i);
			printf("Q: %llu \n\n",n/i);
			break;
		}

	unsigned long long qq = ( i - 1 ) * (n/i - 1);


	d = euclides_ext(5, qq, 1);

	printf("D: %llu \n\n",d);

	return 0;
}




/*
for i in xrange(int(p**0.5+2), 3, -2):
    if p%i == 0:
        print i
        print p/i
        break


*/



/*
void
rsa_break(unsigned long long p, unsigned long long q, unsigned long long e){

	p, q, e = argv[1:]
	p=int(p)
	q=int(q)
	e=int(e)

	n = p * q

	qq = (p – 1) * (q – 1)

	d = euclides_ext(e, qq, 1)
	print "N =", n
	print "QQ =", qq
	print "D =", d 
}*/
