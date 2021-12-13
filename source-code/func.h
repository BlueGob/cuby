#include <stdlib.h>
#include <stdio.h>
struct node
{
	char name[50];
	int priority;
	int cpuTime;
	int arrivalTime;
	struct node* next;
};
typedef struct node node;

void createListes(node elem,node** q){
	node* new = malloc(sizeof(node)); 
	*new = elem; 
	new->next = NULL;
	if(*q == NULL){
		*q = new;
	}else{
		node* p = *q;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = new;
	}
}
node* configFile(char* file, int* listLength){

	node* list = NULL;
	node e;
	char* token;
	int i = 0;
	char* s= malloc(sizeof(char)*100);
	FILE *fptr;
	fptr = fopen(file,"r");
	if(fptr != NULL){
		while((fgets(s,100,fptr))!=NULL) {
			if(s[0] == '#' || s[0]== '\n'){
			
				continue;
		}	
				 token = strtok(s, "-");
				while( token != NULL ) {
					switch(i){
						case 0:
						strcpy(e.name,token);
						case 1 :
						e.priority = atoi(token);
						case 2: 
						e.arrivalTime = atoi(token);
						case 3:
						e.cpuTime = atoi(token);
					}
					i++;
  				token = strtok(NULL, "-");
				}
				i=0;
				*listLength = *listLength+1;
				createListes(e,&list);
				
				
			}
			//fclose(fptr);
			return list;
			
		}else{
			printf("file not found\n");
			return(NULL);
			
		
	}
}
void ganttDiagram(node tab[],int listLength){
		printf(" ");
				//print 1st line
				for (int i = 0; i < listLength; ++i)
					{
						for (int k = 0; k < tab[i].cpuTime*2; ++k)
							{
								printf("_");
							}
							printf(" ");
					}
				//print 2nd line
				printf("\n");
				printf("|");
				for (int i = 0; i < listLength; ++i)
					{
						printf("%s",tab[i].name);
						for (int k = 0; k < (tab[i].cpuTime*2)-2; ++k)
							{
								printf(" ");
							}
						printf("|");
					
				}
				//print 3rd line
				printf("\n");
				
				for (int i = 0; i < listLength; ++i)
				{
					printf("|");
					for (int k = 0; k < tab[i].cpuTime*2; ++k)
					{
						printf("_");
					}
				}
				printf("|");
				printf("\n");
				
				int x = tab[0].arrivalTime;
				printf("%d",x);
				//print 4th line
				for (int i = 0; i < listLength; ++i)
				{
					for (int k = 0; k < tab[i].cpuTime*2; ++k)
					{
						printf(" ");
					}
					x = x+tab[i].cpuTime;
					if(x>=10){
						printf("\b");
					}
					printf("%d",x);
				}
				printf("\n");
}
void printProcessTable(char* file){
	int listLength = 0; 
	char buffer[10];
	node* list = configFile(file,&listLength);
	char* tab[4]= {"name","priority","arrivalTime","cpuTime"};
	printf(" ");
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < strlen(tab[i]); ++j)
		{
			printf("_");
		}
		printf(" ");
	}
	printf("\n");
	printf("|");
	for (int i = 0; i < 4; ++i)
	{
		printf("%s",tab[i]);
		printf("|");
	}
	printf("\n");
	for (int i = 0; i < 4; ++i)
	{
		printf("|");
		for (int j = 0; j < strlen(tab[i]); ++j)
		{
			printf("_");
		}
	}
	printf("|");
	printf("\n");
	int x = 0;
	for (int i = 0; i < listLength; ++i)
	{
		
			printf("|");
			printf("%s",list->name);
			for (int k = 0; k < strlen(tab[x])-strlen(list->name); ++k)
			{
				printf(" ");
			}
			printf("|");
			printf("  ");
			printf("%d",list->priority);
			sprintf(buffer,"%d",list->priority);
			x++;
			for (int k = 0; k < strlen(tab[x])-strlen(buffer)-2; ++k)
			{
				printf(" ");
			}
			printf("|");
			printf("  ");
			printf("%d",list->arrivalTime);
			sprintf(buffer,"%d",list->arrivalTime);
			x++;
			for (int k = 0; k < strlen(tab[x])-strlen(buffer)-2; ++k)
			{
				printf(" ");
			}
			printf("|");
			printf("  ");
			printf("%d",list->cpuTime);
			sprintf(buffer,"%d",list->cpuTime);
			x++;
				for (int k = 0; k < strlen(tab[x])-strlen(buffer)-2; ++k)
			{
				printf(" ");
			}
			printf("|");
			printf("\n");
			x= 0;
		
		list = list ->next;
	}
	for (int i = 0; i < 4; ++i)
	{
		printf("|");
		for (int j = 0; j < strlen(tab[i]); ++j)
		{
			printf("_");
		}
	}
		printf("|");
	printf("\n");
}