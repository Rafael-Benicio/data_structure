#include <malloc.h>
#include <stdio.h>

typedef int KEY_TYPE;

class Register {
public:
  KEY_TYPE key;
};

class Element {
public:
  Register reg;
  Element *next;
};

class Queue {
public:
  Element *start;
  Element *end;

  Queue() {
    this->start = NULL;
    this->end = NULL;
  }

  int lenght() {
    Element *end = this->start;
    int size = 0;
    while (end != NULL) {
      size++;
      end = end->next;
    }
    return size;
  }

  void show() {
    printf("Queue:");
    Element *end = this->start;
    while (end != NULL) {
      printf(" %i |", end->reg.key);
      end = end->next;
    }
    printf("\n");
  }

  bool insert(KEY_TYPE reg) {
    Element *newElement = (Element *)malloc(sizeof(Element));
    newElement->reg = Register{reg};
    newElement->next = NULL;
    if (this->start == NULL)
      this->start = newElement;
    else
      this->end->next = newElement;
    this->end = newElement;
    return true;
  }

  bool pop(Register *reg) {
    if (this->start == NULL)
      return false;
    *reg = this->start->reg;
    Element *erase = this->start;
    this->start = this->start->next;
    free(erase);
    if (this->start == NULL)
      this->end = NULL;
    return true;
  }

  void reinicialize() {
    Element *end = this->start;
    while (end != NULL) {
      Element *erase = end;
      end = end->next;
      free(erase);
    }
    this->start = NULL;
    this->end = NULL;
  }
};

int main() {
  Queue my_queue;
  my_queue.show();
  my_queue.insert(1);
  my_queue.insert(6);
  my_queue.insert(5);
  my_queue.insert(4);
  my_queue.show();
  printf("lenght: %i \n", my_queue.lenght());
  Register my_register;
  my_queue.pop(&my_register);
  printf("%i \n", my_register.key);
  my_queue.show();
  my_queue.reinicialize();
  my_queue.show();
  return 0;
}