#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * my_strrev(char *str)
{

   char *right = str;
   char *left = str;
   char ch;
   while (*right)   right++;
   right--;
   while (left < right)
   {
       ch = *left;
       *left++ = *right;
       *right-- = ch;
   }
   return(str);
}

char* removeDuplicateLetters(char* s)
{
	int i = 0;
	int j = 0;
	int value = 0;
	int alpha[26] = {0};
	int cnt = strlen(s);
	char* dest = (char*)malloc(sizeof(char) * cnt);
	char* sub = (char*)malloc(sizeof(char) * cnt);
	char* p = NULL;

	my_strrev(s);
	strcpy(dest, s);
	memset(s, 0 , cnt);

	for(i=0; i<cnt; ++i)
	{
		value = dest[i] - 'a';
		if(0 == alpha[value])
		{
			++alpha[value];
			s[j++] = dest[i];
		}
		else if(0 < j && value < s[j - 1] - 'a')
		{
			char str[1] = {'\0'};
			str[0] = dest[i];

			memset(sub, 0, cnt);
			strcpy(sub, s);
			memset(s, 0 , cnt);
			p = strtok(sub, str);
            if(NULL != p)
            {
			    strcpy(s, p);
            }
			p = strtok(NULL, str);
			if(NULL != p)
			{
				strcat(s, p);
			}
			j--;
			s[j++] = dest[i];
		}
	}

	if(j < cnt)
	{
		s[j] = '\0';
	}

	my_strrev(s);

	free(dest);
	free(sub);
	return s;
}

int main()
{
	//char s[] = "bcabc";
	char s[] = "bxshkpdwcsjdbikywvioxrypfzfbppydfilfxxtouzzjxaymjpmdoevv";
	//char s[] = "cbacdcbc";
	printf("string: %s\n", removeDuplicateLetters(s));

	return 0;
}
