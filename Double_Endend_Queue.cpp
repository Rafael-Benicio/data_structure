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
  Element *before;
  Element *next;
};

class Deque {
public:
  Element *head;

  Deque() {
    this->head = (Element *)malloc(sizeof(Element));

    this->head->next = this->head;
    this->head->before = this->head;
  }

  int lenght() {
    Element *end = this->head->next;
    int size = 0;

    while (end != this->head) {
      size++;
      end = end->next;
    }

    return size;
  };

  bool isEmpty() { return (this->head == NULL) ? true : false; };

  void show() {
    Element *end = this->head->before;

    printf("Start in end of Deque");
    while (end != this->head) {
      printf("\n%i", end->reg.key);
      end = end->before;
    }
    printf("\n");
  }

  bool insert(KEY_TYPE reg) {
    Element *newElement = (Element *)malloc(sizeof(Element));

    newElement->reg = Register{reg};
    newElement->next = this->head;
    newElement->before = this->head->before;
    this->head->before = newElement;
    newElement->before->next = newElement;

    return true;
  }

  bool deleteElement(Register *reg) {
    if (this->head->next == this->head)
      return false;

    Element *eraseElement = this->head->next;
    *reg = eraseElement->reg;

    this->head->next = eraseElement->next;

    free(eraseElement);
    return true;
  }

  bool reinicialize() {
    Element *end = this->head->next;

    while (end != this->head) {
      Element *eraseElement = end;
      end = end->next;
      free(eraseElement);
    }

    this->head->next = this->head;
    this->head->before = this->head;

    return true;
  }
};

int main() {
  Deque novo_deque;

  if (novo_deque.isEmpty()) {
    novo_deque.show();
  }

  novo_deque.insert(1);
  novo_deque.insert(4);
  novo_deque.insert(5);
  novo_deque.insert(67);
  novo_deque.show();
  printf("%i : Lenght\n", novo_deque.lenght());
  novo_deque.reinicialize();
  printf("%i : Lenght\n", novo_deque.lenght());

  return 0;
}