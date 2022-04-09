void ReadMain(BiTree T)
{
	int flag;
	while(1)
	{
		flag = 0;
		while(1)
		{
			system("cls");
			printf("Now you can choose some way to read the tree:\n");
			printf("1.Front read the tree;\n");
			printf("2.Back read the tree;\n");
			printf("3.Mid read the tree;\n");
			printf("4.Front read the tree without recursion;\n");
			printf("5.Back the read the tree without recursion;\n");
			printf("6.Mid read the tree without recursion;\n");
			printf("7.Level read the tree;\n");
			printf("Now give me the number of the way you want to read the tree by:\n");
			scanf("%d", &flag);
			while(getchar() != '\n');
			if(flag > 0 && flag < 8)
				break;
			else
				printf("Please give me the righ number!\n"); 
		}
		switch(flag)
		{
			case(1):
				FReadBiTreeR(T);
				break;
			case(2):
				BReadBiTreeR(T);
				break;
			case(3):
				MReadBiTreeR(T);
				break;
			case(4):
				FReadBiTree(T);
				break;
			case(5):
				BReadBiTree(T);
				break;
			case(6):
				MReadBiTree(T);
				break;
			case(7):
				LReadBiTree(T);
				break;
		}
		printf("Would you like to continue?\n");
		printf("If yes give me a 'Y', or you will return the main funtion:\n");
		if(getchar() != 'Y')
		{
			while(getchar() != '\n');
			break;
		}
		while(getchar() != '\n');
	}
}

void FReadBiTreeR(BiTree T)
{
	if(T == NULL)
		return;
	ShowNode(T);
	if(T->left != NULL)
		FReadBiTreeR(T->right);
	if(T->right != NULL)
		FReadBiTreeR(T->left);
}

void MReadBiTreeR(BiTree T)
{
	if(T == NULL)
		return;
	if(T->left != NULL)
		MReadBiTreeR(T->right);
	ShowNode(T);
	if(T->right != NULL)
		MReadBiTreeR(T->left);
}

void BReadBiTreeR(BiTree T)
{
	if(T == NULL)
		return;
	if(T->left != NULL)
		BReadBiTreeR(T->right);
	if(T->right != NULL)
		BReadBiTreeR(T->left);
	ShowNode(T);
}

void push(BiTree T)
{
	Stack *s = TreeStack;
	TreeStack = (Stack*)malloc(sizeof(Stack));
	TreeStack->data = T;
	TreeStack->next = s;
}

BiTree pop()
{
	if(TreeStack == NULL)
		return NULL;
	Stack *s = TreeStack;
	BiTree p = s->data;
	TreeStack = TreeStack->next;
	free(s);
	return p;
}

void FReadBiTree(BiTree T)
{
	push(T);
	BiTree p;
	while(TreeStack != NULL)
	{
		p = pop();
		ShowNode(p);
		if(p->left != NULL)
			push(p->left);
		if(p->right != NULL)
			push(p->right);
	}	
}

void BReadBiTree(BiTree T)
{
	push(T);
	BiTree OldPtr = T;
	BiTree p;
	while(TreeStack != NULL)
	{
		p = pop();
		if(p->left == OldPtr || p->right ==OldPtr)
			ShowNode(p);
		else if(p->left != NULL)
		{
			push(p);
			push(p->left);
			if(p->right != NULL)
				push(p->right);
		}
		else if(p->right != NULL)
		{
			push(p);
			push(p->right);
		}
		else
		{
			ShowNode(p);
		}
		OldPtr = p;
	}
}

void MReadBiTree(BiTree T)
{
	push(T);
	BiTree p;
	while(TreeStack != NULL)
	{
		p = pop();
		if(TreeStack != NULL &&p->right == TreeStack->data)
			ShowNode(p);
		else if(p->right != NULL)
		{ 
			push(p->right);
			push(p);
			if(p->left != NULL)
				push(p->left);
		}
		else if(p->left != NULL)
		{
			push(p);
			push(p->left);
		}
		else
			ShowNode(p);
	}
}

void pushQ(BiTree T)
{
	Stack *s = (Stack*)malloc(sizeof(Stack));
	s->data = T;
	s->next = NULL;
	if(TreeQueue->head == NULL)
	{
		TreeQueue->now = s;
		TreeQueue->head = s;
	}
	else
	{
		TreeQueue->now->next = s;
		TreeQueue->now = s;
	}
}

BiTree popQ()
{
	Stack* s = TreeQueue->head;
	BiTree p=s->data;
	TreeQueue->head = s->next;
	free(s);
	return p;
}

void LReadBiTree(BiTree T)
{
	TreeQueue = (Queue*)malloc(sizeof(Queue));
	TreeQueue->head = NULL;
	TreeQueue->now = NULL;
	pushQ(T);
	BiTree p;
	while(TreeQueue->head != NULL)
	{
		p = popQ();
		ShowNode(p);
		if(p->right != NULL)
			pushQ(p->right);
		if(p->left != NULL)
			pushQ(p->left);
	}
	free(TreeQueue);
}
