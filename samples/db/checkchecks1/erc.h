# ifndef ERC_H
# define ERC_H

# include <assert.h>
# include "eref.h"

typedef struct _elem { eref val; /*@null@*/ struct _elem *next; } ercElem;
typedef ercElem *ercList;
typedef struct { /*@null@*/ ercList vals; int size; } ercInfo;
typedef ercInfo *erc;

# include "erc.lh"

# define erc_size(c) ((c)->size)

# define erc_initMod() \
    do { bool_initMod(); employee_initMod();\
         eref_initMod(); } while (0)

# define erc_elements(c, m_x) \
  { erc m_c = (c); ercElem *m_ec = (m_c)->vals; int m_i = 0; \
    while (m_i < (m_c)->size) { \
      eref m_x; assert (m_ec != NULL); m_x = m_ec->val; m_ec = m_ec->next; m_i++; 

# define end_erc_elements }}

# endif
