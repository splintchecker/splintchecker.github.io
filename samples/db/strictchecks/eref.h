# ifndef EREF_H
# define EREF_H

# include "employee.h"

typedef int eref;

/* Private typedefs used in macros  */
typedef enum { ST_USED, ST_AVAIL } erefStatus;
typedef struct {
  /*@reldef@*/ /*@only@*/ employee *conts;
  /*@only@*/ erefStatus *status;
  int size;
} erefTable;

# include "eref.lh"

# define eref_undefined -1

# define eref_isDefined(e)    ((e) != eref_undefined)
# define eref_equal(er1, er2) ((er1) == (er2))

# endif

