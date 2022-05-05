
#ifndef PARAMS_H
#define PARAMS_H

#include <mpi.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

enum param_type {
  PT_INT,
  PT_BOOL,
  PT_DOUBLE,
  PT_STRING,
};

#define PARAM_INT(x)    PT_INT,    .u = { .ini_int = (x), }
#define PARAM_BOOL(x)   PT_BOOL,   .u = { .ini_bool = (x), }
#define PARAM_DOUBLE(x) PT_DOUBLE, .u = { .ini_double = (x), }
#define PARAM_STRING(x) PT_STRING, .u = { .ini_string = (x), }

union param_u {
  int u_int;
  bool u_bool;
  double u_double;
  const char *u_string;
};

struct param {
  const char *name;
  void *var;
  enum param_type type;
  union {
    int    ini_int;
    int    ini_bool;
    double ini_double;
    const char *ini_string;
  } u;
};

void params_init(int argc, char **argv);
void params_print_all(MPI_Comm comm);
void params_parse_cmdline(void *p, struct param *params, const char *title,
			  MPI_Comm comm);
void params_print(void *p, struct param *params, const char *title,
		  MPI_Comm comm);

// hack that allows to print a message only on the first proc

#define mpi_printf(comm, args...) do { int __rank; MPI_Comm_rank(comm, &__rank); if (__rank == 0) { printf(args); } } while(0)

#ifdef __cplusplus
}
#endif

#endif
