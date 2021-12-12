#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "func.h"


DIR *folder;
int i = 0;
int j=1;
struct dirent *entry;
char* choice_tab[10];

void Greeting(){
	int width = 70;
	printf("%40s  ______  __    __  .______   ____    ____  \n%40s /      ||  |  |  | |   _  \\  \\   \\  /   / \n%40s|  ,----'|  |  |  | |  |_)  |  \\   \\/   / \n%40s|  |     |  |  |  | |   _  <    \\_    _/ \n%40s|  `----.|  `--'  | |  |_)  |     |  |     \n%40s \\______| \\______/  |______/      |__|     \n\n\n"," "," "," "," "," "," ");
	printf("Welcome to our small operating system CUBY,for now cuby will sort the processes based on sorting algorithms,\nThis os is made for education purpose by Moslem GANNOUN & Ons CHAHED a two 1st year engineer students in ISI  \n");
}

void getAlgorithms()
{	printf("\n");
	while( (entry=readdir(folder)) ){
   				  	  if(entry->d_name[0] =='.' || strcmp(entry->d_name,"algo.h")==0 )
   				  	  	continue;
   				  	  choice_tab[j] = entry->d_name;
   				  	  j++;

   				  } 
}
void menu(){
	for (int i = 1; i < j; ++i)
	{
		printf("[%d]: %s\n",i,choice_tab[i]);
	}
}

void main(int argc,char* argv[]){
	 node e; 
	 int exit = 0;
	 char command[] = "";
	 char choice[20];
	if(argc == 2){
		system("clear");
		Greeting();
		char* s;
		FILE *fptr;
		fptr = fopen(argv[1],"r");
		if(fptr != NULL){
   			folder = opendir("algorithms/");
   			if(folder == NULL){
   				printf("unable to open diractory");
   			}else{
   				  
   				 	getAlgorithms();
   				  	closedir(folder);
   				  	while(exit != 1){
	   				  	printf("\033[0;31m");
	   				  	printf("Cuby>");
	   				  	printf("\033[0m");
	   				  	scanf("%s",&choice);
	   				  	if(strcmp(choice,"help")==0){
	   				  		printf("menu:\tdisplay our algorithms\nclear:\tclear the console\nconfig:\tdisplay the config file\n1..%d:\tchoose one algorithm\n",j-1);
	   				  	}else if(strcmp(choice,"clear")==0){
	   				  		system("clear");
	   				  	}else if(strcmp(choice,"menu")==0){
	   				  		menu();
	   				  	}else if(strcmp(choice,"config")==0){
	   				  		system("cat config.conf");
	   				  	}else if(atoi(choice)!=0){
	   				  		if(atoi(choice)>j-1){
	   				  			printf("invalid choice, choose between 1 and %d \n",j-1);
	   				  		}else{
	   				  		system(strcat(strcat(strcat(strcat(command,"./algorithms/"),choice_tab[atoi(choice)])," "),argv[1]));
	   				  		strcpy(command,"");
	   				  		}
	   				  	}else if(strcmp(choice,"exit")==0){
	   				  		printf("goodbye see you soon ^^\n");
	   				  		exit = 1;
	   				  	}else{
	   				  		printf("type \"help\" for more information\n");
	   				  		
	   				  	}
	   				  	
   				}
   			}
   			
		}else{
			printf("error reading file \n");
		}
	}else{
		printf("please enter config file. \n");
	}

		
}