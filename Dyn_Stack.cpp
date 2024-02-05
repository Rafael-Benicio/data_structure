#include <malloc.h>
#include <stdio.h>

#define KEY_TYPE int

class Register {
public:
  KEY_TYPE key;
};

class Element {
public:
  Register reg;
  Element *next;
};

class Stack {
public:
  Element *top;

  Stack() { this->top = NULL; };

  int lenght() {
    Element *end = this->top;
    int size = 0;
    while (end != NULL) {
      size++;
      end = end->next;
    }
    return size;
  };

  bool isEmpty() { return (this->top == NULL) ? true : false; };

  bool insert(KEY_TYPE reg) {
    Element *novo = (Element *)malloc(sizeof(Element));
    novo->reg = Register{reg};
    novo->next = this->top;
    this->top = novo;
    return true;
  }

  bool pop(Register *reg) {
    if (this->top == NULL)
      return false;
    *reg = this->top->reg;
    Element *erase = this->top;
    this->top = this->top->next;
    free(erase);
    return true;
  }

  void show() {
    printf("Stack:");
    Element *topRegister = this->top;
    while (topRegister != NULL) {
      printf(" %i |", topRegister->reg.key);
      topRegister = topRegister->next;
    }
    printf("\n");
  }

  bool reinicialize() {
    Element *erase;
    Element *position = this->top;
    while (position != NULL) {
      erase = position;
      position = position->next;
      free(erase);
    }
    this->top = NULL;
    return true;
  }
};

int main() {
  Stack my_stack;
  my_stack.show();
  my_stack.insert(1);
  my_stack.insert(6);
  my_stack.insert(5);
  my_stack.insert(4);
  my_stack.insert(8);
  my_stack.show();
  printf("lenght: %i \n", my_stack.lenght());
  Register my_register;
  my_stack.pop(&my_register);
  printf("%i \n", my_register.key);
  my_stack.show();
  my_stack.reinicialize();
  my_stack.show();

  return 0;
}