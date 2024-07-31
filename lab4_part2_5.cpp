#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data ;
	struct node *next ;
	struct node *prev ;
}node;
node *head = NULL , *tail = NULL ;

node *newNode(int n){
	node *new_node ;
	new_node = (node*)malloc(sizeof(node));
	new_node->data = n - 48 ;
	new_node->next = NULL ;
	new_node->prev = NULL ;
}

void displayLL (){
	node *ptr ;
	ptr = head ;
	while(ptr != NULL){
		printf("%d",ptr->data);
		ptr = ptr->next ;
	}
	printf("\n");
}
void displayReLL (){
	node *ptr ;
	ptr = tail ;
	while(ptr != NULL){
		printf("%d",ptr->data);
		ptr = ptr->prev ;
	}
	printf("\n");
}

int search(int x){
	node *ptr ;
	int count = 1; 
 	ptr = head ;
	while (ptr != NULL && ptr->data != x){
		count++ ;
		ptr = ptr->next ;
	}
	if (ptr != NULL){
		return count ;
	}else {
		return -1 ;
	}
}


int main (){
	node *new_node , *ptr , *preptr ;
	char s1[31] , *data ;
	int i ,count=1;
	data = s1 ;
	scanf("%30s",s1);
	while(*data){
		if(*data == 'N'){
			data++;
			new_node = newNode(*data);
			head = new_node ;
			tail = new_node ;
			data++;	
		}else if (*data == 'I'){
			data++;
			if(*data == 'F'){
				data++;
				new_node = newNode(*data);
				new_node->next = head ;
				head->prev = new_node;
				head = new_node ;
				data++;
			}else if (*data == 'A'){
				data++;
				ptr = head ;
				for (i=1;i<*data-48;i++){
					ptr = ptr->next ;
				}
				data++;
				if (ptr->next == NULL){
					new_node = newNode(*data);
					ptr->next = new_node ;
					new_node->prev = ptr ;
					tail = new_node ;
					data++;
				}else{
					preptr = ptr;
					ptr = ptr->next;
					new_node = newNode(*data);
					new_node->next = ptr ;
					new_node->prev = preptr ;
					preptr->next = new_node ;
					data++;					
				}
			}else if (*data == 'L'){
				data++;
				new_node = newNode(*data);
				new_node->prev = tail ;
				tail->next = new_node ;
				tail = new_node ;
				data++;	
			}				
		}else if(*data == 'D'){
			data++;
			if (*data == 'F'){
				ptr = head->next ;
				ptr->prev = NULL ;
				head->next = NULL ;
				free(head);
				head = ptr ;
				data++;
			}else if(*data == 'A'){
				data++;
				ptr = head ;
				int check = 0 ;
				while(ptr != NULL){
					if (count == *data-48){
						check = 1;
						break ;
					}
					count++;
					ptr = ptr->next;	
				}	
				if (check == 1){
					if (ptr == tail){
						preptr = tail->prev ;
						preptr->next = NULL ;
						free(tail);
						tail = preptr;	
					}else if(ptr == head){
						printf("xx");
						preptr = head->next ;
						preptr->prev = NULL ;
						free(head);
						head = preptr;
					}else{
						preptr = ptr->prev;
						preptr->next = ptr->next;
						ptr->next->prev = preptr;
						ptr->next = NULL ;
						ptr->prev = NULL ;
						free(ptr);
					}
				}
				data++;			
			}
		}else if(*data == 'P'){
			displayLL();
			data++;
		}else if(*data == 'R'){
			displayReLL();
			data++;
		}else if (*data == 'S'){
			data++;
			printf("%d",search(*data-48));
			data++;
		}
	}
	return 0;
}
