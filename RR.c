#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
int quantum ;
void removeFromListe(node **list,int index){
	node * headHolder = *list;
	if(index == 0){
		*list = headHolder->next;
		free(headHolder);
	}else {
		node * p = *list;
		for (int i = 0; i < index - 1; i++)
		{
			p = p->next;
		}
		p->next = p->next->next;
		free(p->next);
	}
}
node removeTail(node** list){
	node* p = *list;
	if(p == NULL){
		return *p;
	}
	if(p->next == NULL){
	node elem = *p;
	elem.cpuTime = elem.cpuTime - quantum;	
	free(*list);
	*list = NULL;
	return elem;
	}
	while(p->next->next!=NULL){
		p= p->next;
		//printf("%s",p->name);
	}

	node elem = *(p->next);
		
	p->next = NULL;
	free(p->next);
	elem.cpuTime = elem.cpuTime - quantum;
	return elem;

}


void insertHead(node elem,node** q){
	node* new = malloc(sizeof(node)); 
	*new = elem; 
	new->next = *q;
	*q = new;
}

void main(int argc,char* argv[]){
		int listLength = 0;
		node gantt[100];
		node* p;
		node* sortedList;
		node* queue = NULL ;
		int ok = 1;
		int i = 0;
		int timeStamp = 0;
		int min;
		
		node* list ;
		
		list = configFile(argv[1],&listLength); 
		p = list;
		//liste to tab
		node sortedTab[listLength];
		while(p!=NULL){
			sortedTab[i] = *p;
			p = p->next;
			i++;
		}
		
		//algorithm tab tri
			do{
				ok = 1;
				for(i =0;i<listLength-1;i++){
					if(sortedTab[i].arrivalTime>sortedTab[i+1].arrivalTime){
						node aux = sortedTab[i];
						sortedTab[i] = sortedTab[i+1];
						sortedTab[i+1] = aux;
						ok == 0;
					}
				}
			}while(ok == 0);

		

			//create list
		sortedList = malloc(sizeof(node));
		*sortedList = sortedTab[0];
		sortedList->next = NULL;
		p = sortedList;
		for (int i = 1; i < listLength; i++)
		{
			node* aux = malloc(sizeof(node));
			*aux = sortedTab[i];
			aux->next= NULL;
			p->next = aux;
			p= p->next;
		} 
			int count = 0;
		timeStamp = sortedList->arrivalTime;
		i =0;
		printf("enter your quantum\n");
		scanf("%d",&quantum);
		
		while(count != listLength){
			if(sortedList!=NULL){
			//fill in the queue
				p= sortedList;
				while(p!= NULL && p->arrivalTime<=timeStamp){
						insertHead(*p,&queue);
						removeFromListe(&sortedList,0);
					p = p->next;
				}
			}
	//round robin queue
		node aux = removeTail(&queue);
		
		if(aux.cpuTime > 0){
			
			timeStamp = timeStamp +quantum ;
			//fill the queue
			if(sortedList!=NULL){
				p= sortedList;
				while(p!= NULL && p->arrivalTime<=timeStamp){
						insertHead(*p,&queue);
						removeFromListe(&sortedList,0);
					p = p->next;
				}
			}
			insertHead(aux,&queue);
			aux.cpuTime = quantum;
			gantt[i] = aux;
			i++;
			
		}else if(aux.cpuTime == 0){
			timeStamp = timeStamp +quantum ;
			printf("the process %s has completed his CPU time and left at %d\n",aux.name,timeStamp);
			count ++;
			aux.cpuTime = quantum;
			gantt[i] = aux;
			i++;
		}else{
			timeStamp  = timeStamp + quantum + aux.cpuTime;
			printf("the process %s has completed his CPU time and left at %d\n",aux.name,timeStamp);
			count ++;
			aux.cpuTime = quantum + aux.cpuTime;
			gantt[i] = aux;
			i++;
		}
}	
ganttDiagram(gantt,i);
}
