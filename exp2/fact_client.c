/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "fact.h"


void
fact_prog_1(char *host,int a)
{
	CLIENT *clnt;
	int  *result_1;
	number  fact_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, FACT_PROG, FACT_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
    fact_1_arg.a=a;
	result_1 = fact_1(&fact_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	else
	{
	printf("Factorial of no is:- %d",*result_1);
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;
    int a;
	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	printf("Enter the no:-");
	scanf("%d",&a);
	fact_prog_1 (host,a);
exit (0);
}
