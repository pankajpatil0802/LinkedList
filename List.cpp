#include<stdio.h>
#include<io.h>
#include<malloc.h>
#include<string.h>
#include<errno.h>
#include<fcntl.h>
extern int errno;

typedef struct LinkedList
{
	int iData;
	struct LinkedList *pNextNode;
}NODE;


NODE*
IsHeadNullInsert(NODE* prHead, NODE* prInput)
{
	prHead = prInput;
	prHead -> pNextNode = NULL;
	printf("First Node is Inserted..!!");
	return prHead;
}

NODE *
InsertAtFirst(
	NODE* prHead
	)
{
	NODE *plInput;
	plInput = (NODE *)malloc(sizeof(NODE));
	printf("\nPlease Insert the Integer Data :");
	fflush(stdin);
	scanf("%d",&plInput -> iData);

	if (NULL == prHead)
	{
		prHead = IsHeadNullInsert(prHead, plInput);
		return prHead;
	}
	plInput -> pNextNode = prHead;
	prHead = plInput;
	printf("Node is Inserted at First Position..!!");
	return prHead;
}

NODE*
InsertAtLast(
	NODE* prHead
	)
{
	NODE *plInput, *plTemp;
	plInput = (NODE *)malloc(sizeof(NODE));
	printf("\nPlease Insert the Integer Data :");
	fflush(stdin);
	scanf("%d",&plInput -> iData);

	if (NULL == prHead)
	{
		prHead = IsHeadNullInsert(prHead, plInput);
		return prHead;
	}
	plTemp = prHead;
	while (NULL != plTemp -> pNextNode)
	{
		plTemp = plTemp -> pNextNode;
	}
	plTemp -> pNextNode = plInput;
	plInput -> pNextNode = NULL;
	printf("Node is Inserted at Last Position..!!");
	return prHead;
}

NODE*
InsertAtAnyPosition(
	NODE* prHead,
	int irCount
	)
{
	NODE *plInput, *plTemp;
	plTemp = prHead;
	int iIterator, ilNodePosition;
	
	printf("Enter the Position at which You want to insert Node : ");
	fflush(stdin);
	scanf("%d", &ilNodePosition);

	if (1 == ilNodePosition || NULL == prHead)
	{
		prHead = InsertAtFirst(prHead);
		return prHead;
	}

	if (ilNodePosition > irCount)
	{
		prHead = InsertAtLast(prHead);
		return prHead;
	}

	plInput = (NODE*)malloc(sizeof(NODE));
	printf("\nPlease Insert the Integer Data :");
	fflush(stdin);
	scanf("%d", &plInput -> iData);

	iIterator=1;
	while (iIterator != ilNodePosition-1)
	{
		plTemp = plTemp -> pNextNode;
		iIterator++;
	}
	plInput -> pNextNode = plTemp -> pNextNode;
	plTemp -> pNextNode = plInput;
	printf("Node is Inserted at %d Position..!!", ilNodePosition);
	return prHead;
}


NODE*
DeleteAtAnyPosotion(
	NODE* prHead,
	int irCount
	)
{
	int iIterator;
	int ilNodePosition;
	NODE *plTemp, *plInput;

	printf("Enter the Position of Node which You want to Delete : ");
	fflush(stdin);
	scanf("%d", &ilNodePosition);

	plTemp = prHead;
	if (1 == ilNodePosition)
	{
		prHead = prHead -> pNextNode;
		free(plTemp);
		printf("Node is Deleted From 1st Position..!!");
		return prHead;
	}
	iIterator = 1;
	if (irCount == ilNodePosition)
	{
		while (iIterator != irCount)
		{
			plInput = plTemp;
			plTemp = plTemp -> pNextNode;
			iIterator++;
		}
		plInput -> pNextNode = NULL;
		free(plTemp);
		printf("Node is Deleted From Last Position..!!");
		return prHead;
	}
	while (iIterator != ilNodePosition-1)
	{
		plTemp = plTemp -> pNextNode;
		iIterator++;
	}
	plInput = plTemp;
	plTemp = plTemp -> pNextNode;
	plInput -> pNextNode =  plTemp -> pNextNode;
	free(plTemp);
	printf("Node is Deleted at %d Position..!!", ilNodePosition);
	return prHead;
}

NODE*
SortLinkedList(
	NODE* prHead,
	int irCount
	)
{
	NODE *plTemp, *plInput;
	int i, j, iContainer;
	for (i = 0; i < (irCount-1); i++)
	{
		plTemp = prHead;
		for (j = 0; j < (irCount-1); j++)
		{
			plInput = plTemp -> pNextNode;
			if ((plTemp -> iData) > (plInput -> iData))
			{
				iContainer = plTemp -> iData;
				plTemp -> iData = plInput -> iData;
				plInput -> iData = iContainer;
			}
			plTemp = plInput;
		}
	}
	printf("Linked List is Sorted Successfully..!!");
	return prHead;
}

NODE*
SortPointerLinkedList(
	NODE* prHead,
	int irCount
	)
{
	NODE *plTemp, *plInput, *iContainer;
	int i, j;
	for (i = 0; i < (irCount-1); i++)
	{
		plTemp = prHead;
		for (j = 0; j < (irCount-1); j++)
		{
			plInput = plTemp -> pNextNode;
			if ((plTemp -> iData) > (plInput -> iData))
			{
				iContainer = plTemp -> pNextNode;
				plTemp -> pNextNode = plInput -> pNextNode;
				plInput -> pNextNode = iContainer;
			}
			plTemp = plInput;
		}
	}
	printf("Linked List is Sorted Successfully..!!");
	return prHead;
}


NODE*
RemoveDublicateItems(
	NODE* prHead,
	int *piCount
	)
{
	int i, j, ilCount = *piCount;
	NODE *plTemp, *plInput, *plDelete;
	plTemp = prHead;
	for (i = 1; i < (ilCount); i++)
	{
		plDelete = plTemp;
		for (j = 0; j < (ilCount - i); j++)
		{
			plInput = plDelete;
			plDelete = plDelete -> pNextNode;
			if ((plTemp -> iData) == (plDelete -> iData))
			{
				plInput -> pNextNode = plDelete -> pNextNode;
				free (plDelete);
				ilCount--;
				*piCount = ilCount;
				printf("Dublicate Entry is Removed Successfully..!!");
			}
		}
		plTemp = plTemp -> pNextNode;
	}
	return prHead;
}

NODE*
ReverseLinkedList(
	NODE *prHead
	)
{
	NODE *plTemp, *plInput;
	plInput = prHead;
	prHead = prHead -> pNextNode;
	plTemp= prHead;
	plInput -> pNextNode = NULL;
	while (NULL != prHead)
	{
		prHead = prHead -> pNextNode;
		plTemp -> pNextNode = plInput;
		plInput = plTemp;
		plTemp = prHead;
	}
	prHead = plInput;
	printf("Linked List is Reversed Successfully..!!");
	return prHead;
}

//NODE*
//Reverse(
//	NODE* plTemp
//	)
//{
//	NODE* prHead, *plInput, *plTemp2;
//	if (plTemp == NULL)
//	{
//		return NULL;
//	}
//
//	if(NULL == plTemp->pNextNode)
//	{
//		prHead = plTemp;
//		return prHead;
//	}
//	plTemp2 = Reverse(plTemp->pNextNode);
//	plInput = plTemp -> pNextNode;
//	plInput -> pNextNode = plTemp;
//	plTemp->pNextNode = NULL;
//}


NODE*
Reverse(
	NODE* prHead
	)
{
	NODE* plTemp, *plInput;
	if (prHead == NULL)
	{
		return NULL;
	}

	if(NULL == prHead->pNextNode)
	{
		plInput = prHead;
		return prHead;
	}
	plTemp = prHead;
	prHead = Reverse(prHead->pNextNode);
	prHead -> pNextNode = plTemp;
	plTemp->pNextNode = NULL;
	return plTemp;
}


NODE*
SearchByPosition(
	NODE* prHead,
	int irCount
	)
{
	NODE *plTemp;
	int ilNodePosition, ilIterator = 1;
	printf("Enter the Position of Node which You want to Search : ");
	fflush(stdin);
	scanf("%d", &ilNodePosition);
	plTemp = prHead;
	if(ilNodePosition > irCount || ilNodePosition < 1)
	{
		printf("Linked List only Consist of %d Nodes", irCount);
		return prHead;
	}
	while(ilNodePosition != ilIterator)
	{
		plTemp = plTemp -> pNextNode;
		ilIterator++;
	}
	printf("The Value at This %d Position is : %d ", ilNodePosition , plTemp -> iData);
	return prHead;
}

NODE*
SearchByValue(
	NODE* prHead
	)
{
	NODE* plTemp;
	int ilNodeValue, ilNodePosition = 1;

	printf("Enter the Integer Value which You want to Search : ");
	fflush(stdin);
	scanf("%d", &ilNodeValue);

	plTemp = prHead;
	while (
		ilNodeValue != plTemp -> iData && 
		NULL != plTemp->pNextNode
		)
	{
		plTemp = plTemp -> pNextNode;
		ilNodePosition++;
	}
	if(ilNodeValue == plTemp -> iData)
	{
		printf("The Value %d is found at %d Position..!! ", ilNodeValue, ilNodePosition);
		return prHead;
	}
	printf("Integer Value %d does not found in Linked List..!!", ilNodeValue);
	return prHead;
}

bool
PrintLinkedList(
	NODE* prHead,
	int irCount
	)
{
	NODE* plTemp;
	plTemp = prHead;
	printf("Total Number of Nodes in the Linked List : %d", irCount);
	printf("\nLinear Linked List Is as Follows : ");
	while (NULL != plTemp)
	{
		printf("-> %d ", plTemp -> iData);
		plTemp = plTemp -> pNextNode;
	}
	return true;
}


//bool
//StoreListIntoFile(
//	NODE* prHead,
//	int irCount
//	)
//{
//	int icRead = 0;
//	int icWrite = 0;
//	int ifDescriptor;
//	char *szBufferLL;
//	NODE* plTemp;
//
//	if (NULL == prHead)
//	{
//		printf("Nothing to write into the file..!!");
//		return false;
//	}
//	szBufferLL = (char*)calloc(irCount,sizeof(NODE));
//	if (NULL == szBufferLL)
//	{
//		printf( "szBufferLL Insufficient memory available..!!\n" );
//		return false;
//	}
//	printf("szBufferLL Memory is allocated Successfully..!!" );
//	plTemp = prHead;
//	while (NULL != plTemp -> pNextNode)
//	{
//		//strcpy(szBufferLL, plTemp -> iData);
//		//strcpy(szBufferLL, plTemp -> pNextNode));
//		icWrite = _write(ifDescriptor, szBufferLL, irCount*sizeof(NODE));
//		plTemp = plTemp -> pNextNode;
//	}
//	ifDescriptor = _open("LinkedList.txt", O_WRONLY | O_CREAT);
//	if (-1 == ifDescriptor)
//	{
//		// print which type of error have in a code
//		printf("Error Number % d\n", errno); 
//
//		// print program detail "Success or failure"
//		perror("Program");
//	}
//
//	//icRead = _read(ifDescriptor, szBufferLL, irCount*sizeof(NODE));
//	
//	free(szBufferLL);
//	_close(ifDescriptor);
//	return true;
//}


int
main()
{
	bool boReturn;
	char chChoice2;
	int iChoice1;
	int iNodePosition=0;

	NODE *pHead = NULL, *pTemp = NULL, *pInput = NULL, *pDelete = NULL;
	static int iCount=0;

	do
	{
		printf("\n ****************MENU****************");
		printf("\n 1.Insert Node at First Position.");
		printf("\n 2.Insert Node at Last Position.");
		printf("\n 3.Insert Node at Any Position.");
		printf("\n 4.Delete Node from any Position.");
		printf("\n 5.Sort Nodes of The Linear List.");
		printf("\n 6.Remove Dublicate Nodes.");
		printf("\n 7.Reverse The Linear List.");
		printf("\n 8.Search Value at Position of List.");
		printf("\n 9.Search a specific Data in List.");
		printf("\n 10.Display The Linear List.");
		printf("\n ************************************");
		printf("\nEnter Your Choice from 1-10 : ");
		fflush(stdin);
		scanf("%d", &iChoice1);

		switch (iChoice1)
		{
			case 1 :
				pHead = InsertAtFirst(pHead);
				if (NULL == pHead)
				{
					printf("Error at Inserting at First Position..!!");
					break;
				}
				iCount++;
				break;
			case 2 :
				pHead = InsertAtLast(pHead);
				if (NULL == pHead)
				{
					printf("Error at Inserting at First Position..!!");
					break;
				}
				iCount++;
				break;
			case 3 :
				pHead = InsertAtAnyPosition(pHead, iCount);
				if (NULL == pHead)
				{
					printf("Error at Inserting at First Position..!!");
					break;
				}
				iCount++;
				break;
			case 4 :
				if (NULL == pHead)
				{
					printf("Nothing to delete(Please Insert Something First)..!!");
					break;
				}
				if (iNodePosition > iCount)
				{
					printf("Node Position does not Available..!!");
					printf("Total Number of Nodes in the Linked List : %d", iCount);
					break;
				}
				pHead = DeleteAtAnyPosotion(pHead, iCount);
				if (NULL == pHead)
				{
					printf("Error at Inserting at First Position..!!");
					break;
				}
				iCount--;
				break;
			case 5 :
				if (NULL == pHead || 1 == iCount)
				{
					printf("Doesn't have Sufficient Node(Please Insert Something First)..!!");
					break;
				}
				pHead = SortLinkedList(pHead, iCount);
				if (NULL == pHead)
				{
					printf("Error at Inserting at First Position..!!");
					break;
				}
				break;
			case 6 :
				if (NULL == pHead || 1 == iCount)
				{
					printf("Doesn't have Sufficient Node(Please Insert Something First)..!!");
					break;
				}
				pHead = RemoveDublicateItems(pHead, &iCount);
				if (NULL == pHead)
				{
					printf("Error at Inserting at First Position..!!");
					break;
				}
				break;
			case 7 :
				if (NULL == pHead || 1 == iCount)
				{
					printf("Doesn't have Sufficient Node(Please Insert Something First)..!!");
					break;
				}
				pHead = ReverseLinkedList(pHead);
				if (NULL == pHead)
				{
					printf("Error at Reversing..!!");
					break;
				}
				break;
			case 8 :
				if (NULL == pHead || 1 == iCount)
				{
					printf("Doesn't have Sufficient Node(Please Insert Something First)..!!");
					break;
				}
				pHead = SearchByPosition(pHead, iCount);
				if (NULL == pHead)
				{
					printf("Error at Inserting at First Position..!!");
					break;
				}
				break;
			case 9 :
				if (NULL == pHead || 1 == iCount)
				{
					printf("Doesn't have Sufficient Node(Please Insert Something First)..!!");
					break;
				}
				pHead = SearchByValue(pHead);
				if (NULL == pHead)
				{
					printf("Error at Inserting at First Position..!!");
					break;
				}
				break;
			case 10 :
				boReturn = PrintLinkedList(pHead, iCount);
				if (false == boReturn)
				{
					printf("Error at Inserting at First Position..!!");
					break;
				}
				break;
			default :
				printf("\nPlease Enter The Number between 1 to 10.....");
		}
		printf("\n***************************************");
		printf("\nWould you Like to Continue(Y/N) : ");
		fflush(stdin);
		scanf("%c", &chChoice2);
	}while('Y' == chChoice2 || 'y' == chChoice2);

	//free(pInput);
	//for (i = iCount ; i > 0 ; i--)
	//{
	//	pTemp = pHead;
	//	while (0 != pTemp)
	//	{
	//		pTemp = pTemp -> pNextNode;
	//	}
	//	free(pTemp);
	//}

	while (0 != iCount)
	{
		pTemp = pHead;
		pHead = pHead -> pNextNode;
		free (pTemp);
		iCount--;
	}

	getchar();
	return 0;

}