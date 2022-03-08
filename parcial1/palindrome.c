#include <stdio.h>
#include <string.h>


void Palindrome(char str[])
{
	
	int l = 0;
	int h = strlen(str) - 1;

	
	while (h > l)
	{
		if (str[l++] != str[h--])
		{
			printf("%s No es Palindrome \n\n", str);
			return;
		}
	}
	printf("%s es palindrome \n\n", str);
}


int main()
{
	Palindrome("attccsva");
	Palindrome("wilter");
	Palindrome("oso");
	return 0;
}

