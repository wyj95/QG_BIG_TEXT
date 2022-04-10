int Depth(BiTree T)
{
	if(T->left != NULL)
	{
		if(T->right != NULL)
		{
			int d1=Depth(T->left);
			int d2=Depth(T->right);
			return(max(d1,d2) + 1);
		}
		else
			return Depth(T->left)+1;
	}
	else
	{
		if(T->right != NULL)
			return Depth(T->right)+1;
		else
			return 1;
	}
}

int NodeCount(BiTree T)
{
	int number=0;
	NodeCount1(T, &number);
	return number; 
}

void NodeCount1(BiTree T, int *number)
{
	if(T->right != NULL)
		NodeCount1(T->right, number);
	(*number)++;
	if(T->left != NULL)
		NodeCount1(T->left, number);
}

int LeafCount(BiTree T)
{
	int number=0;
	LeafCount1(T, &number);
	return number;
}

void LeafCount1(BiTree T, int *number)
{
	if(T->left != NULL)
		LeafCount1(T->left, number);
	else if(T->right == NULL)
		(*number)++;
	if(T->right != NULL)
		LeafCount1(T->right, number);
}

void DeleteNode(BiTree T, int key)
{
	int flag=0;
	BiTree p;
	if(T->data == key)
	{
		if(T->right != NULL)
		{
			p = T->right;
			if(p->left != NULL)
			{
				while(p->left->left != NULL)
					p = p->left;
				T->data = p->left->data;
				free(p->left);
				p->left = NULL;
			}
			else
			{
				p->left = T->left;
				T = p;
			}		 
		}
		else if(T->left != NULL)
		{
			BiTree p1,p2;
			p1 = T->left;
			if(p1->right == NULL)
			{
				T->data = p1->data;
				T->left = p1->left;
				free(p1);
			}
			else
			{
				while(T->right->right != NULL)
				{
					p2 = p1;
					p1 = p1->right;
				}
				T->data = p1->right->data;
				p2->right = p1->left;
				free(p1);
			}
		}
		else
		{
			printf("Now there are not any number in the tree,\n");
			printf("you should build a new tree!\n");
			CreateBiTree(T);
		}
	}
	/*
	删除思路：
		假设结点p的值==key： 
		若该结点p右结点p1不为空，且p1的左结点不为空，则将p1的斜左二叉树的末尾p3值赋给p，然后置p3的前结点
									左结点为NULL，释放p3
								且p1的左结点为空，则将p1的左结点赋值为p的左结点，然后p1取代原p的位置
								  
		若该结点p右结点为空，且其左结点p1的右结点也为空，则将左结点p1的值赋给该结点p，然后p1取代原p的位置 
							且其左结点p1的右结点p2不为空，则将p1的斜右二叉树上的末尾p3的值赋给p，然后置p3
								的前结点为NULL，释放p3 
							且其左结点为空，则提示树已空，要求重新建立新的树(直接删除该点) 
	*/ 
	while(1)
	{
		if(T->data < key)
		{
			if(T->right == NULL)
				break;
			if(T->right->data == key)
			{
				BiTree T1 = T->right;//T1为待删除结点 
				flag = 1;
				if(T1->right != NULL)
				{
					p = T1->right;
					if(p->left != NULL)
					{
					 	while(p->left->left != NULL)
					 		p = p->left;//p指向T1右结点的左斜二叉树末尾 
					 	T1->data = p->left->data;
					 	free(p->left);
					 	p->left = NULL;
					}
					else
					{
					 	p->left = T1->left;
					 	free(T->right);
					 	T->right = p;
					}
				}
				else if(T1->left != NULL)//T1右结点也为空 
				{
					p = T1->left;
					if(p->right == NULL)
					{
						T1->data = p->data;
						T1->left = p->left;
						free(p);
					}
					else
					{
						while(p->right->right != NULL)
							p = p->right;
						T1->data = p->right->data;
						free(p->right);
						p->right = NULL;
					}
				}
				else//T1左右结点都为空 
				{
					T->right = NULL;
					free(T1);
				}
				break;
			}
			T = T->right;
		}
		if(T->data > key)
		{
			if(T->left == NULL)
				break;
			if(T->left->data == key)
			{
				BiTree T1 = T->left; 
				flag = 1;
				if(T1->right != NULL)
				{
					p = T1->right;
					if(p->left != NULL)
					{
						while(p->left->left != NULL)
							p = p->left;
						T1->data = p->left->data;
						free(p->left);
						p->left = NULL;
					}
					else
					{
						p->left = T1->left;
						free(T1);
						T->left = p; 
					}
				}
				else if(T1->left != NULL)
				{
					p = T1->left;
					if(p->right == NULL)
					{
						T->left = p;
						free(T1);
					}
					else
					{
						while(p->right->right != NULL)
							p = p->right;
						T1->data = p->right->data;
						free(p->right);
						p->right = T1->right;
					}
				}
				else
				{
					T->left = NULL;
					free(T1);
				}
				break;
			}
			T = T->left;
		}
	}
	if(flag)
		printf("The node whose number is %d has been deleted.\n", key);
	else
		printf("Sorry,there isn't any node whose number is %d.\n", key);
}

void ShowNode(BiTree T)
{
	if(T == NULL)
	{
		printf("Sorry,but we have not found what you want to find.\n");
		return;
	}
	printf("The node's number is %d.\n", T->data);
	if(T->right !=NULL)
	{
		printf("The number of its left son-node is %d.\n", T->right->data);
		if(T->data >= T->right->data)
			exit(0);
	}
	else
		printf("It doesn't have left son-node.\n");
	if(T->left !=NULL)
	{
		printf("The number of its right son-node is %d.\n", T->left->data);
		if(T->data <= T->left->data)
			exit(0);
	}
	else
		printf("It doesn't have right son-node.\n");
}

BiTree SearchNode(BiTree T, int key)
{
	if(T->data == key)
		return T;
	else if(T->data < key)
	{
		if(T->right == NULL)
			return NULL;
		else
			return SearchNode(T->right, key);
	}
	else
	{
		if(T->left == NULL)
			return NULL;
		else
			return SearchNode(T->left, key);
	}
}

void AddNode(BiTree T, int key)
{
	if(T->data > key)
	{
		if(T->left != NULL)
			AddNode(T->left,key);
		else
		{
			BiTree p=(BiTree)malloc(sizeof(Tree));
			p->data = key;
			p->left = NULL;
			p->right = NULL;
			T->left = p;
		}
	}
	else if(T->data < key)
	{
		if(T->right != NULL)
			AddNode(T->right,key);
		else
		{
			BiTree p=(BiTree)malloc(sizeof(Tree));
			p->data = key;
			p->right = NULL;
			p->left = NULL;
			T->right = p;
		}
	}
	else
	{
		printf("Sorry,but there has been a node whose number is %d!\n",key);
	}
}

void CheckTree(BiTree T, int n)
{
	if(CheckRight(T->right, n) | CheckLeft(T->left, n))
	{
		printf("The tree has something wrong!!!!\n");
		printf("%d",n);
		exit(0);
	}
	if(T->left != NULL)
		CheckTree(T->left, T->left->data);
	if(T->right != NULL)
		CheckTree(T->right, T->right->data);
}

int CheckRight(BiTree T, int n)
{
	if(T == NULL)
		return 0;
	if(T->data <= n)
		return 1; 
	return (CheckRight(T->right, n) | CheckRight(T->left, n));
}

int CheckLeft(BiTree T, int n)
{
	if(T == NULL)
		return 0;
	if(T->data >= n)
		return 1;
	return (CheckLeft(T->right, n) | CheckLeft(T->left, n));
}

void DestroyTree(BiTree T)
{
	if(T->left != NULL)
		DestroyTree(T->left);
	if(T->right != NULL)
		DestroyTree(T->right);
	free(T);
	free(TreeQueue);
}
