#include <iostream>
#include <malloc.h>

#define STACK_MAX_LENGHT 50
typedef int KEY_TYPE;

class Register {
	public:
		KEY_TYPE key;
};

class Stack{
	private:
		Register stackRegisters[STACK_MAX_LENGHT];
		int top;

	public:
		Stack(){
			this->top=-1;
		}

		int lenght(){
			return this->top+1;
		}

		void show(){
			std::cout<<"Stack:---"<<std::endl;
			int i;
			for (i=this->top;i>=0;i--){
				std::cout<< this->stackRegisters[i].key<<std::endl;
			}
			std::cout<<std::endl;
		}
		bool push(Register reg){
			if (this->top>STACK_MAX_LENGHT-1)return false;
			this->top=this->top+1;
			this->stackRegisters[this->top]=reg;
			return true;
		}
		bool popout(){
			if (this->top==-1) return false;
			this->top=this->top-1;
			return true;
		}

		KEY_TYPE pop(){
			if (this->top==-1) throw "Empty stack";
			this->top=this->top-1;
			return this->stackRegisters[0].key;
		}

		void reset(){
			this->top=-1;
		}
};


int main(){
	Stack pilha_1=Stack();
	pilha_1.show();
	pilha_1.push(Register{3});
	pilha_1.push(Register{4});
	pilha_1.push(Register{3});
	pilha_1.show();
	pilha_1.popout();
	std::cout<<pilha_1.lenght()<<std::endl;
	pilha_1.show();
	pilha_1.reset();
	pilha_1.push(Register{100});
	pilha_1.show();
	std::cout<<pilha_1.pop()<<std::endl;
	return 0;
}