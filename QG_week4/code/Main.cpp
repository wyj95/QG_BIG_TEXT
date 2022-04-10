int main()
{
	show();
	return 0;
}

void show()
{
	BiTree T=(BiTree)malloc(sizeof(Tree));
	BiTree newTree;
	CreateBiTree(T);
	int flag, key;
	while(1)
	{
		flag = -1;
		while(1)
		{
			printf("\nWhat would you like to do:\n");
			printf("1.Read the tree;\n");
			printf("2.Get the depth of the tree;\n");
			printf("3.Get the number of the tree's node;\n");
			printf("4.Get the number of the tree's leaf;\n");
			printf("5.Delete some node of the tree whose number is what you give me;\n");
			printf("6.Search the node whose number is what you give me and show it;\n");
			printf("7.Add a node whose number is what you give me;\n");
			printf("8.Check whether the tree is a BiTree or not;\n");
			printf("9.DESTROY the tree and then quit.\n");
			printf("Now give me the number in front of what you want to do:\n");
			scanf("%d", &flag);
			while(getchar() != '\n');
			if(flag>0 && flag<11)
				break;
			else
				printf("Please give me a right number!\n");
		}
		system("cls");
		switch(flag)
		{
			case(1):
				if(T->left==NULL && T->right==NULL)
				{
					printf("Sorry,but the tree is NULL,you should creat a tree first!\n");
					CreateBiTree(T);
				}
				ReadMain(T);
				break;
			case(2):
				printf("The depth of the tree is %d.\n", Depth(T));
				break;
			case(3):
				printf("The number of the tree's node is %d.\n", NodeCount(T));
				break;
			case(4):
				printf("The number of the tree's leaf is %d.\n", LeafCount(T));
				break;
			case(5):
				printf("PLease give me the number of the tree you want to delete:\n");
				scanf("%d", &key);
				while(getchar() != '\n');
				DeleteNode(T, key);
				break;
			case(6):
				printf("Please give me the number of the node you want to search:\n");
				scanf("%d", &key);
				while(getchar() != '\n');
				ShowNode(SearchNode(T, key));
				break;
			case(7):
				printf("Please give me a number which you want to add into the tree:\n");
				scanf("%d",&key);
				while(getchar() != '\n');
				AddNode(T, key);
				printf("Adding is finished.\n");
				break;
			case(8):
				CheckTree(T, T->data);
				printf("Check over.It is really a BiTree!\n");
				break;
			case(9):
				DestroyTree(T);
				return;
		}
		printf("Give me anything to continue...\n");
		while(getchar() != '\n');
	}
	exit(-1);
}

void GetInt(int *a)
{
	char s[50];
	int flag=1;
	while(1)
	{
		gets(s);
		if(strlen(s) <= 5)
		{
			int i;
			for(i=0; i<5 && s[i]!='\0'; i++)
				if(s[i]>'9' || s[i]<'0')
				{
					flag=0;
					break;
				}
			if(flag == 1)
			{
				*a = 0;
				for(i=0; i<5 && s[i]!='\0'; i++)
					*a = (*a)*10 + s[i] - '0';
				if(*a != 0)
					return;
			}
		}
		printf("Please give me a right int number which is smaller than 10000:\n");
	}
 } 

void CreateBiTree(BiTree T)
{
	int number,depth;
	while(1)
	{
		printf("Please give me the number of the tree:\n");
		GetInt(&number);
		printf("Then give me the depth of the tree:\n");
		GetInt(&depth);
		if(depth>number)
			printf("Please give me the right depth which should be smaller than the number!\n");
		else
			break;
	}
	CreateTree(T, depth, &number, 0);
}

void CreateTree(BiTree T, int depth, int *number, int min)
{
	if(depth<=0 || (*number)<=0)
		return;
	if(depth == 1)
	{
		T->data = (*number)--;
		T->left = NULL;
		T->right = NULL;
		return;
	}
	if(*number > min)
	{
		T->right = (BiTree)malloc(sizeof(Tree));
		CreateTree(T->right, depth-1, number, min+1);
	}
	else
		T->right = NULL;
	T->data = (*number)--;
	if(*number > 0)
	{
		T->left = (BiTree)malloc(sizeof(Tree));
		CreateTree(T->left, depth-1, number, min+1);
	}
	else
		T->left = NULL;
}
