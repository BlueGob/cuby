#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int queueIndex = 0;

		
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

void createQueue(node* elem,node** q){
	node* new = malloc(sizeof(node)); 
	*new = *elem; 
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

node* SearchMinimumCpuTime(node* list){
	int counter = 0;
	node *min = list;
	node* p = list;
	while(p!=NULL){
		if(min->cpuTime > p->cpuTime){
			min = p;
			queueIndex = counter;
		}
		counter++;
		p = p->next;
	}
	return min;
}
void main(int argc,char* argv[]){
		int listLength = 0;
		node* p = NULL;
		node* sortedList = NULL;
		node* queue = NULL ;
		int ok = 1;
		int i = 0;
		int timeStamp = 0;
		int min ;
		
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
			
		while(count != listLength){
			if(sortedList!=NULL){
			//fill in the queue
				p= sortedList;
				while(p!= NULL && p->arrivalTime<=timeStamp){
						createQueue(p,&queue);
						removeFromListe(&sortedList,0);
					p = p->next;
				}
			}

			//search min
			node *min;
			min = SearchMinimumCpuTime(queue);
			sortedTab[count] = *min;
			printf("the process %s has completed his CPU time and left at %d\n",min->name,timeStamp);
			removeFromListe(&queue,queueIndex);
			queueIndex = 0;
			++count;
			timeStamp = timeStamp + min->cpuTime;
	}
	ganttDiagram(sortedTab,listLength);
	
}
