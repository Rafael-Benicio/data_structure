#include <stdio.h>
#include <malloc.h>

typedef struct{
	int key;
}Register;

typedef struct aux{
	Register reg;
	struct aux* before;
	struct aux* next;
}Element;

typedef struct{
	Element* head;
}Deque;

void inicialize(Deque *deque){
	deque->head=(Element*)malloc(sizeof(Element));
	
	deque->head->next=deque->head;
	deque->head->before=deque->head;
}

int lenght(Deque*deque){
	Element* end=deque->head->next;
	int size=0;

	while (end!=deque->head){
		size++;
		end=end->next;
	}

	return size;

};

bool isEmpty(Deque* deque){
	return (deque->head==NULL) ? true: false;
};

void show(Deque *deque){
	Element* end=deque->head->before;

	printf("Start in end of Deque");
	while(end!=deque->head){
		printf("%i ",end->reg.key);
		end=end->before;
	}
	printf("\n");
}

bool insert(Deque* deque,Register reg){
	Element* newElement=(Element*) malloc(sizeof(Element));

	newElement->reg=reg;
	newElement->next=deque->head;
	newElement->before=deque->head->before;
	deque->head->before=newElement;
	newElement->before->next=newElement;

	return true;
}

bool deleteElement(Deque *deque,Register *reg){
	if (deque->head->next==deque->head) return false;

	Element* eraseElement=deque->head->next;
	*reg=eraseElement->reg;

	deque->head->next=eraseElement->next;

	free(eraseElement);
	return true;
}

bool reinicialize(Deque *deque){
	Element* end=deque->head->next;

	while (end!=deque->head){
		Element* eraseElement=end;
		end=end->next;
		free(eraseElement);
	}

	deque->head->next=deque->head;
	deque->head->before=deque->head;

	return true;
}

int main(){
	printf("oi mundo\n");
	return 0;
}