#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* rmExtraBlanks(char *str)
{
	int length = strlen(str);
	char newStr[length];
	int i=0;
	while( *str != '\0' )
	{
		if( *str == ' ' )
		{
			newStr[i] = *str;
			i++;
			while( (*str == ' ') )
				str++;
		}
		newStr[i] = *str;
		i++;
		str++;
	}
	//printf("%s\n",newStr);
	str = newStr;
	return str;
}

int main()
{
	char *p;
	int length;
	printf("Enter the length of string = ");
	scanf("%d",&length);
	p = (char *)malloc(length+1);
	printf("Enter the string = ");
	gets();// because input is buffer is not empty.
	gets(p);// input-string.
	char *result = rmExtraBlanks(p);
	printf("New String = %s\n",result);
	return 0;
}