#include <stdio.h>

#define MAX 50

typedef int KEY_TYPE;

class Register {
public:
  KEY_TYPE key;
};

class DoubleStack {
public:
  Register stackRegisters[MAX];
  int top1;
  int top2;

  DoubleStack() {
    this->top1 = -1;
    this->top2 = MAX;
  }

  int lenght() { return this->top1 + 1 + MAX - this->top2; }

  bool show(int stack) {
    if (stack < 1 || stack > 2)
      return false;
    printf("stack %i: ", stack);
    int i;
    if (stack == 1)
      for (i = this->top1; i >= 0; i--)
        printf("%i ", this->stackRegisters[i].key);
    else
      for (i = this->top2; i < MAX; i++)
        printf("%i ", this->stackRegisters[i].key);
    printf("\n");
    return true;
  }

  bool insert(KEY_TYPE reg, int stack) {
    if (stack < 1 || stack > 2)
      return false;
    if (this->top1 + 1 == this->top2)
      return false;
    if (stack == 1) {
      this->top1 = this->top1 + 1;
      this->stackRegisters[this->top1] = Register{reg};
    } else {
      this->top2 = this->top2 - 1;
      this->stackRegisters[this->top2] = Register{reg};
    }
    return true;
  }

  bool pop(Register *reg, int stack) {
    if (stack < 1 || stack > 2)
      return false;
    if (stack == 1) {
      if (this->top1 == -1)
        return false;
      *reg = this->stackRegisters[this->top1];
      this->top1 = this->top1 - 1;
    } else {
      if (this->top2 == MAX)
        return false;
      *reg = this->stackRegisters[this->top2];
      this->top2 = this->top2 + 1;
    }
    return true;
  }

  void reinicialize() {
    this->top1 = -1;
    this->top2 = MAX;
  }
};

int main() {
  DoubleStack my_stack;
  my_stack.show(1);
  my_stack.show(2);
  my_stack.insert(1, 1);
  my_stack.insert(6, 1);
  my_stack.insert(5, 2);
  my_stack.insert(4, 2);
  my_stack.insert(8, 1);
  my_stack.show(1);
  my_stack.show(2);
  printf("lenght: %i \n", my_stack.lenght());
  Register my_register;
  my_stack.pop(&my_register, 1);
  printf("POPED VALUE : %i \n", my_register.key);
  my_stack.pop(&my_register, 2);
  printf("POPED VALUE : %i \n", my_register.key);
  my_stack.show(1);
  my_stack.show(2);
  my_stack.reinicialize();
  my_stack.show(1);
  my_stack.show(2);
  return 0;
}