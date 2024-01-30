#include <stdio.h>
#include <malloc.h>

#define MAX 50

typedef int KEY_TYPE;

class Register{
public:
	KEY_TYPE key;
};

class Queue{
public:
	Register arrayQueue[MAX];
	int start;
	int size;

	Queue(){
		this->start=0;
		this->size=0;
	}
	int lenght(){
		return this->size;
	}

	void show(){
		printf("Queue:");
		int i=this->start;
		int temp;
		for (temp=0;temp<this->size;temp++){
			printf(" %i |",this->arrayQueue[i].key);
			i=(i+1)%MAX;
		}
		printf("\n");
	}

	bool insert(KEY_TYPE reg){
		if(this->size>=MAX) return false;
		int posicao=(this->start+this->size)%MAX;
		this->arrayQueue[posicao]=Register{reg};
		this->size++;
		return true;
	}

	bool pop(Register* reg){
		if(this->size==0) return false;
		*reg=this->arrayQueue[this->start];
		this->start=(this->start+1)%MAX;
		size--;
		return true;
	}

	void reinicialize(){
		this->start=0;
		this->size=0;
	}
};



int main(){
	Queue my_queue;
	my_queue.show();
	my_queue.insert(1);
	my_queue.insert(3);
	my_queue.insert(65);
	my_queue.insert(62);
	my_queue.show();
	printf("%i :lenght\n",my_queue.lenght());
	Register my_resiter;
	my_queue.pop(&my_resiter);
	printf("%i\n",my_resiter.key);
	my_queue.show();
	my_queue.reinicialize();
	my_queue.show();

	return 0;
}