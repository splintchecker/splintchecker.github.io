# ifndef EREF_H
# define EREF_H

# include "employee.h"

typedef int eref;

/* Private typedefs used in macros  */
typedef enum { used, avail } eref_status;
typedef struct {
  /*@reldef@*/ /*@only@*/ employee *conts;
  /*@only@*/ eref_status *status;
  int size;
} eref_ERP;

# include "eref.lh"

# define erefNIL -1
# define eref_equal(er1, er2) ((er1) == (er2))

# endif
