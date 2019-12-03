#include <deepstate/DeepState.hpp>
using namespace deepstate;

#define SIZE 64
#define LENGTH 128

int stack[SIZE];
int top = 0;

void clear() {
  top = 0;
}

void push(int x) {
  assert(top < SIZE);
  stack[top++] = x;
}

int pop() {
  if (top > 0) {
    return stack[--top];
  } else {
    return -1;
  }
}

void pop_n(unsigned n) {
  if (top >= n) {
    top -= n;
  } else {
    top = 0;
  }
}

int get_top()  {
  if (top > 0) {
    return stack[top-1];
  } else {
    return -1;
  }
}

TEST(Stack, PushPop) {
  clear();
  for (int i = 0; i < LENGTH; i++) {
    OneOf(
	  [&] {
	    LOG(TRACE) << "STEP #" << i << ": " << "clear()";
	    clear();
	  },
	  [&] {
	    int v = DeepState_Int();
	    LOG(TRACE) << "STEP #" << i << ": " << "push(" << v << ")";
	    push(v);
	  },
	  [&] {
	    LOG(TRACE) << "STEP #" << i << ": " << "pop()";
	    pop();
	  },
	  [&] {
	    unsigned n = DeepState_UInt();
	    LOG(TRACE) << "STEP #" << i << ": " << "pop_n(" << n << ")";
	    pop_n(n);
	  },
	  [&] {
	    LOG(TRACE) << "STEP #" << i << ": " << "get_top() = " << get_top();
	  });
  }
}
