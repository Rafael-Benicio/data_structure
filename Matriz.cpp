#include <malloc.h>
#include <stdio.h>

#define KEY_TYPE int

class Node {
public:
  KEY_TYPE value;
  int coluna;
  Node *next;
};

class Matriz {
public:
  Node **A;
  int rows;
  int cols;

  Matriz(int line, int cols) {
    this->rows = line;
    this->cols = cols;
    this->A = (Node **)malloc(line * sizeof(Node *));
    for (int i = 0; i < line; i++) {
      this->A[i] = NULL;
    }
  }

  bool insert(int line, int column, KEY_TYPE value) {
    // checa se esta dentro do range de possibilidades de insert
    if (line < 0 || line >= this->rows || column < 0 || column >= this->cols)
      return false;
    Node *before = NULL;
    Node *current = this->A[line];
    while (current != NULL && current->coluna < column) {
      before = current;
      current = current->next;
    }

    if (current != NULL && current->coluna == column) {
      if (value == 0) {
        if (before == NULL)
          this->A[line] = current->next;
        else
          before->next = current->next;
        free(current);
      } else
        current->value = value;
    } else {
      Node *novo = (Node *)malloc(sizeof(Node));
      novo->coluna = column;
      novo->value = value;
      novo->next = current;
      if (before == NULL)
        this->A[line] = novo;
      else
        before->next = novo;
    }
    return true;
  }

  KEY_TYPE valueMatriz(int line, int column) {
    if (line < 0 || line >= this->rows || column < 0 || column >= this->cols)
      return 0;
    Node *current = this->A[line];
    while (current != NULL && current->coluna < column) {
      current = current->next;
    }
    if (current != NULL && current->coluna == column)
      return current->value;
    return 0;
  }

  void show() {
    for (int row = 0; row < this->rows; row++) {
      Node *current = this->A[row];
      for (int col = 0; col < this->cols; col++) {
        if (current != NULL)
          printf(" %i |", valueMatriz(row, col));
        current = current->next;
      }
      printf("\n");
    }
  }
};

int main() {
  Matriz my_matriz = Matriz(3, 2);
  my_matriz.insert(0, 0, 1);
  my_matriz.insert(1, 1, 0);
  my_matriz.insert(0, 1, 1);
  my_matriz.insert(1, 0, 0);
  my_matriz.insert(2, 0, 1);
  my_matriz.insert(2, 1, 0);
  my_matriz.show();
  /* code */
  return 0;
}