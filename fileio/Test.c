#include <stdio.h>

int main()
{
	FILE *fp;

	fp = fopen("filename.txt", "w");

	/*Process of the file*/
	fprintf(fp, "%s", "Hello Kelvino");
	/*End of processing*/
	fclose(fp);
	return 0;
}
