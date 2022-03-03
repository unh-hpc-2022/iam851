
#include "linear_algebra.h"

#include <stdlib.h>
#include <stdio.h>

void vector_construct(struct vector* v, int n)
{
  v->data = calloc(n, sizeof(*v->data));
  v->n = n;
}

void vector_destruct(struct vector* v)
{
  free(v->data);
  // The below isn't necessary, but may help make certain bugs more obvious.
  // v->data = NULL;
  // v->n = 0;
}

void vector_print(const struct vector* v)
{
  printf("{");
  for (int i = 0; i < v->n; i++) {
    printf(" %g", VEC(v, i));
  }
  printf(" }\n");
}
