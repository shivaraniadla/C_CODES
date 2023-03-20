#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 20
int strcomp(char *s1, char *s2);
int main()
{
    char *s1 = NULL;
    char *s2 = NULL;
    s1 = (char *) malloc (SIZE * sizeof(char));//dynamic memory allocation
    s2 = (char *) malloc (SIZE * sizeof(char));
    if (NULL == s1 && NULL == s2) {
        printf("malloc failed!\n");
        exit(0);
    }
    printf("\nEnter first string:\n");
    if (NULL == (fgets(s1, SIZE, stdin))) {
        printf("Fgets failed ");
    }
    printf("\nEnter second string:\n");
    if (NULL == (fgets(s2, SIZE, stdin))) {
        printf("Fgets failed ");
    }
    //strcomp(s1, s2);
    *(s1 + (strlen(s1)) - 1) = '\0';
    *(s2 + (strlen(s2)) - 1 ) = '\0';
	int res = strcomp(s1, s2);
	if (res > 0)
		printf("\ns1 is greater than s2\n");
	else if (res < 0)
		printf("\ns1 is less than s2\n");
	else 
		printf("\ns1 is equal to s2\n");
    free(s1);
    free(s2);
    s1 = NULL;
    s2 = NULL;
    return 0;
}
int strcomp(char *s1, char *s2)
{
    while ( *s1 != '\0') {
		if ( *s1 != *s2) {
			break;
		}
        *s1++;
		*s2++;
       }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}
