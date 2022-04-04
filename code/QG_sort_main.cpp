#include<sort.h>
int main()
{
	Show();
	return 0;
}

/**
 *  @name        : void show()
 *  @description : Ö÷½çÃæ 
 *  @param       : None 
 */
void Show()
{
	int flag;
	while(1)
	{
		while(1)
		{
			flag = 0;
			printf("You can do these funtion:\n");
			printf("1.Check whether there something wrong in all the sort;\n");
			printf("2.Get the time every the sort uses with long length;\n");
			printf("3.Get the time every the sort uses with many times;\n");
			printf("4.Read the number from the file and write them after sorting;\n");
			printf("5.Write some sorted number into the file;\n");
			printf("6.Write some random number into the file;\n");
			printf("7.Colour sort;\n");
			printf("8.Find some number you want;\n");
			printf("9.Quit.\n");
			scanf("%d", &flag);
			while(getchar() != '\n');
			if(flag>0 && flag<10)
				break;
			else
			{
				system("cls");
				printf("Please give me the right number:\n");
			}
		}
		switch(flag)
		{
			case(1):
				TextSort();
				break;
			case(2):
				TextBigData(10000);
				TextBigData(50000);
				TextBigData(200000);
				break;
			case(3):
				TextLittleData();
				break;
			case(4):
				ReadFile();
				break;
			case(5):
				WriteFile();
				break;
			case(6):
				WriteRandFile();
				break;
			case(7):
				ColourSortMain();
				break;
			case(8):
				FindKthMain();
				break;
			case(9):
				return;
		}
		printf("Give me anything to continue...");
		getchar();
		system("cls");
	}
}
