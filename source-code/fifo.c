#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include"func.h"

void main(int argc,char* argv[]){
	node* p;
	node* list;
	int ok = 1;
	int i = 0;
	int listLength = 0;
	int timeStamp = 0;
	list =  configFile(argv[1],&listLength);
	p = list;
	
	node f[listLength];
	//liste vers tab
	while(p!=NULL){
		f[i] = *p;
		p = p->next;
		i++;
	}
	//fifo algorithm tab tri
		do{
			ok = 1;
			for(i =0;i<listLength-1;i++){
				if(f[i].arrivalTime>f[i+1].arrivalTime){
					node aux = f[i];
					f[i] = f[i+1];
					f[i+1] = aux;
					ok == 0;
				}
			}
		}while(ok == 0);
	//print the table
		for (int i = 0; i < listLength; ++i)
		{
			if(f[i].arrivalTime>timeStamp){
				timeStamp = timeStamp + f[i].cpuTime+ (f[i].arrivalTime - timeStamp);
			}else{
				timeStamp = timeStamp + f[i].cpuTime;
			}
			
			printf("the process %s has completed his CPU time and left at %d\n",f[i].name,timeStamp);
			//printf("\033[A");
		}
		//print gantt diagram
		ganttDiagram(f,listLength);
}


	
