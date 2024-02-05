#include <malloc.h>
#include <stdio.h>

using namespace std;

class Node {
private:
  // Variaveis------
  int data;
  Node *next;

public:
  int getData() { return data; }

  Node *getNext() { return next; }

  void setNext(Node *n) { next = n; }

  void setData(int val) { data = val; }
  // Construtor---------------
  Node(int val) {
    data = val;
    next = NULL;
  }
  Node() { next = NULL; }
};

class linkedList {
private:
  // Variaveis------------
  Node *head;
  Node *tail;

public:
  int size;
  // Variaveis------------
  // Cabeça da lista encadeada
  // Funções--------------
  // Mostra elementos da lista
  void show() {
    Node *node = head;
    if (empty())
      printf("List is Empty");
    else {
      while (node) // percorre a lista
      {
        printf("%i\n", node->getData());
        node = node->getNext();
      }
    }
  }
  // verifica se a lista está vazia
  inline bool empty() { return (head == NULL); }

  // insere no início
  void insert(int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode = new Node(val);
    if (empty()) {
      head = newNode;
      tail = newNode;
    } else {
      newNode->setNext(head);
      head = newNode;
    }
    size++;
  }

  // insere no final (semelhante a push_back da list)
  void push(int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode = new Node(val);

    if (empty()) {
      head = newNode;
      tail = newNode;
    } else {
      tail->setNext(newNode);
      tail = newNode;
    }
    size++;
  }

  int operator[](int keyIndex) {
    Node *node = (Node *)malloc(sizeof(Node));
    node = head;

    for (int index = 0; index < index; index++) {
      if (index == keyIndex)
        break;
      else if (node->getNext())
        node = node->getNext();
    }
    return node->getData();
    free(node);
  }

  bool remove(int val) {
    Node *node = head;

    for (int i = 0; i < size; i++) {
      if (node->getData() == val) {
        head = node->getNext();
        size--;
        return true;
        break;
      } else if (node->getNext()->getData() == val) {
        Node *nextNode = node->getNext();
        node->setNext(nextNode->getNext());
        size--;
        return true;
        break;
      } else if (tail == node->getNext()) {
        break;
      } else if (node->getNext()) {
        node = node->getNext();
      }
    }
    return false;
  }
  // Construtor
  linkedList() {
    size = 0;
    head = NULL;
    tail = NULL;
  }
  linkedList(int val) {
    // se passar elemento, então cria novo No
    head = new Node(val);
    tail = head;
    size = 1;
  }
};

int main() {

  linkedList enc;

  enc.insert(4);
  enc.insert(3);
  enc.insert(2);
  enc.insert(1);
  enc.push(5);
  enc.show();
  printf("%i", enc[1]);
  enc.show();

  return 0;
}