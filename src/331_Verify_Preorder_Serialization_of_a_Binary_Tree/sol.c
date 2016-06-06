/******************************************************************************
*In a binary tree, if we consider null as leaves, then
*
*all non-null node provides 2 outdegree and 1 indegree (2 children and 1 parent), except root
*all null node provides 0 outdegree and 1 indegree (0 child and 1 parent).
*Suppose we try to build this tree. During building, we record the difference between out degree and in degree diff = outdegree - indegree. When the next node comes, we then decrease diff by 1, because the node provides an in degree. If the node is not null, we increase diff by2, because it provides two out degrees. If a serialization is correct, diff should never be negative and diff will be zero when finished.
*
*from :https://leetcode.com/discuss/83824/7-lines-easy-java-solution
*
*我这里翻译一下：
*
*对于二叉树，我们把空的地方也作为叶子节点（如题目中的#），那么有
*
*所有的非空节点提供2个出度和1个入度（根除外）
*所有的空节点但提供0个出度和1个入度
*我们在遍历的时候，计算diff = outdegree – indegree. 当一个节点出现的时候，diff – 1，因为它提供一个入度；当节点不是#的时候，diff+2(提供两个出度) 如果序列式合法的，那么遍历过程中diff >=0 且最后结果为0.
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef char 	bool;
#define false	0
#define true	1

bool isValidSerialization(char* preorder)
{
	int diff = 1;
	bool flag = false;

	while((NULL != preorder) && ('\0' != *preorder))
	{
		char* data = NULL;
		char* ptr = NULL;
		int i = 0;
		int len = strlen(preorder) - 1;

		data = (char*)malloc(sizeof(char)*len);
		ptr = data;
		for(i=0; i<len; ++i)
		{
			data[i] = '\0';
		}

		while((',' != *preorder) && (NULL != preorder) && ('\0' != *preorder))
		{
			printf("current preorder: %c\n", *preorder);
			*ptr++ = *preorder++;
		}

		printf("data= %s\n", data);


		--diff;
		if(0 == strstr(data, "#"))
		{
			diff += 2;
		}

		if(flag)
		{
			return false;
		}
		printf("diff: %d\n", diff);
		if(0 > diff)
		{
			return false;
		}
		else if(0 == diff)
		{
			flag = true;
		}

		if(',' == *preorder)
		{
			++preorder;
		}

		if(NULL != data)
		{
			free(data);
		}
	}

	return flag;
}

int main()
{
	char array[] = "#,7,6,9,#,#,#";
	//char array[] = "#";
	//char* array = "9,#,19,9,9,#,#,9,#,#,59,#,#";
	//char array[] = "9,#,19,9,9,#,#,9,#,#,59,#,#";
	//char array[] = "9,3,4,#,#,1,#,#,2,#,6,#,#";
	//char array[] = "9,#,92,#,#";
	printf("%d\n", isValidSerialization(array));
	return 0;
}
