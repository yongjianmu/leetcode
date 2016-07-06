#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxProduct(char** words, int wordsSize) 
{
	int i = 0;
	int j = 0;
	int product = 0;
	int tmp_product = 0;
	int flag = 0;
	int* element = (int*)malloc(sizeof(int) * wordsSize);

	for(i=0; i<wordsSize; ++i)
	{
		element[i] = 0x0;
		
		for(j=0; j<strlen(words[i]); ++j)
		{
			element[i] |= (1 << (words[i][j] - 'a'));
		}
	}

	for(i=0; i<wordsSize; ++i)
	{
		flag = 0;
		for(j=i + 1; j<wordsSize; ++j)
		{
			if(0 == (element[i] & element[j]))
			{
				flag = 1;
				tmp_product =  (strlen(words[i])) * (strlen(words[j]));
				printf("words[%d], len: %ld, words[%d], len:%ld\n", i, strlen(words[i]), j, strlen(words[j]));
			}

			if((1 == flag) && tmp_product > product)
			{
				product = tmp_product;
			}
		}

	}

	free(element);

	return product;
}

int main()
{
	char* words[] = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
	int num = 6;

	printf("Max Product: %d\n", maxProduct(words, num));

	return 0;
}
