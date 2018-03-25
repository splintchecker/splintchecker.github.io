# include <stdlib.h>
# include "erc.h"

static size_t int_toSize (int x)
{
  if (x < 0)
    {
      fprintf (stderr, "Error: int_toSize is negative: %d", x);
      return 0;
    }
  else
    {
      return (size_t) x;
    }
}

erc erc_create (void) 
{
  erc c;

  c = (erc) malloc (sizeof (ercInfo));

  if (c == 0) 
    {
      printf ("Malloc returned null in erc_create\n");
      exit (EXIT_FAILURE);
    }
  
  c->vals = 0;
  c->size = 0;
  return c;
}

void erc_clear (erc c) 
{
  ercList elem;
  ercList next;

  for (elem = c->vals; elem != 0; elem = next) 
    {
      next = elem->next;
      free (elem);
    }
  
  c->vals = 0;
  c->size = 0;
}

void erc_final (erc c) 
{
  erc_clear (c);
  free (c); 
}

bool erc_member (eref er, erc c) 
{
  ercList tmpc;

  for (tmpc = c->vals; tmpc != 0; tmpc = tmpc->next)
    if (eref_equal (tmpc->val, er)) return TRUE; 

  return FALSE;
}

void erc_insert (erc c, eref er) 
{
  ercList newElem;
  newElem = (ercElem *) malloc (sizeof (ercElem));

  if (newElem == 0) 
    {
      printf ("Malloc returned null in erc_insert\n");
      exit (EXIT_FAILURE);
    }

  newElem->val = er;
  newElem->next = c->vals;
  c->vals = newElem;
  c->size++;
}

bool erc_delete (erc c, eref er) 
{
  ercList elem = c->vals;

  if (elem != NULL)
    {
      if (eref_equal (elem->val, er))
	{
	  c->vals = elem->next;
	  free (elem);
	  c->size--;
	  return TRUE;
	}
      else
	{
	  ercList prev = elem;
	  elem = elem->next;

	  for (; elem != 0; prev = elem, elem = elem->next) 
	    {
	      if (eref_equal (elem->val, er))
		{ 
		  assert (prev != NULL);
		  prev->next = elem->next;
		  free (elem); 
		  c->size--;
		  return TRUE;
		}
	    }
	}
    }
  
  return FALSE;
}

void erc_join (erc c1, erc c2) 
{
  ercList tmpc;

  for (tmpc = c2->vals; tmpc != 0; tmpc = tmpc->next)
    erc_insert (c1, tmpc->val);
}

char *erc_sprint (erc c)
{
  int len;
  char *result;

  result = (char *) 
    malloc (int_toSize (erc_size (c) * (employeePrintSize + 1) + 1));

  if (result == 0) 
    {
      printf ("Malloc returned null in erc_sprint\n");
      exit (EXIT_FAILURE);
    }

  len = 0;

  erc_elements(c, er)
    {
      employee_sprint(&(result[len]), eref_get(er));
      len += employeePrintSize;
      result[len++] = '\n';
    } end_erc_elements;

  result[len] = '\0';
  return result;
}

eref erc_choose (erc c) 
{
  assert (c->vals != NULL);
  return c->vals->val;
}
