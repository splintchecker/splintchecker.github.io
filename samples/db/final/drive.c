/* Part of a driver used to test dbase  */

/* Include those modules that export things that are used explicitly here */
 
# include <stdio.h>
# include <assert.h>
# include "bool.h"
# include "employee.h"
# include "empset.h"
# include "dbase.h"

int main (int argc, /*@unused@*/ char *argv[]) 
  /*@globals internalState, stderr, stdout@*/
  /*@modifies internalState, *stderr, *stdout@*/
{
  employee e;
  empset em1, em2, em3;
  char na[10000];
  char * sprintResult;
  int i;
  db_status status;
  db_q q;
  
  /* Initialize all of the LCL-specified modules that were included */
  bool_initMod();
  employee_initMod();
  empset_initMod();
  db_initMod();
  
  if (argc != 1) 
    {
      check (fprintf (stderr, "FormatPos: Wrong number of arguments. "
		      "Given %d needs 0.\n", argc - 1) >= 0);
      return 1;
    }
  
  /* Unit test empset */
  em1 = empset_create();

  if (!(empset_size(em1) == 0))
    {
      check (printf("Size should be 0.\n") >= 0);
    }

  for (i = 0; i < 500; i++) 
    {
      e.ssNum = i;
      e.salary = 100000;
      e.gen = MALE;
      e.j = MGR;
      (void) sprintf(na, "S.S. Doe %d", i);
      check (employee_setName(&e, na));
      empset_insert(em1, e);
    }

  if (!(empset_size(em1) == 500)) 
    {
      check (printf("Size should be 500.\n") >= 0);
    }

  for (i = 0; i < 250; i++) 
    {
      e.ssNum = i;
      e.salary = 100000;
      e.gen = MALE;
      e.j = MGR;
      (void) sprintf(na, "S.S. Doe %d", i);
      check (employee_setName(&e, na));
      empset_delete(em1, e);
    }

  if (!(empset_size(em1) == 250)) 
    {
      check (printf("Size should be 250.\n") >= 0);
    }

  em2 = empset_create();

  for (i = 0; i < 100; i++) 
    {
      e.ssNum = i;
      e.salary = 100000;
      e.gen = MALE;
      e.j = MGR;
      (void) sprintf(na, "S.S. Doe %d", i);
      check (employee_setName(&e, na));
      empset_insert(em2, e);
    }

  em3 = empset_union(em1, em2);

  if (!(empset_size(em3) == 350))
    {
      check (printf("Size should be 350.\n") >= 0);
    }

  empset_intersect(em3, em3);

  if (!(empset_size(em3) == 350))
    {
      check (printf("Size should be 350.\n") >= 0);
    }

  check (printf("Print two different employees:\n") >= 0);

  for (i = 0; i < 2; i++) 
    {
      e = empset_choose(em3);
      employee_sprint(na, e);
      check (printf("%s\n", &(na[0])) >= 0);
      empset_delete(em3, e);
    }
  
  /* Test dbase  */

  for (i = 0; i < 20; i++) 
    {
      e.ssNum = i;
      e.salary = 10 * i;

      if (i < 10) 
	{
	  e.gen = MALE; 
	}
      else 
	{
	  e.gen = FEMALE;
	}

      if (i < 15) 
	{
	  e.j = NONMGR; 
	}
      else
	{
	  e.j = MGR;
	}

      (void) sprintf(na, "J. Doe %d", i);
      check (employee_setName(&e, na));

      if ((i/2)*2 == i) 
	{
	  check (db_hire(e) == DBS_OK); 
	}
      else 
	{
	  db_uncheckedHire(e); status = db_hire(e);
	}
    }
  
  check (printf("Should print true: %s\n", 
		bool_unparse (/*@-usedef@*/ status == DBS_DUPLERR /*@=usedef@*/))
	 >= 0); 

  check (printf("Employees 0 - 19\n") >= 0);
  db_print();
  check (db_fire(17));
  q.g = FEMALE; q.j = JOB_UNKNOWN; q.l = 158; q.h = 185;
  check (printf("Employees 0 - 16, 18 - 19\n") >= 0);
  db_print();

  empset_final (em1);
  i = db_query(q, em1 = empset_create());
  sprintResult = empset_sprint(em1);
  check (printf("Should get two females: %d\n%s\n", i, sprintResult) >= 0);
  free(sprintResult);

  q.g = MALE; q.j = NONMGR; q.l = 0; q.h = 185;
  empset_final (em2);
  i = db_query(q, em2 = empset_create());
  empset_final (em3);
  em3 = empset_disjointUnion(em2, em1);
  sprintResult = empset_sprint(em3);
  i = empset_size(em3);
  check (printf("Should get two females and ten males: %d\n%s\n", i, sprintResult)
	 >= 0);
  free(sprintResult);
  
  empset_intersect(em1, em3);
  sprintResult = empset_sprint(em1);
  i = empset_size(em1);
  check (printf("Should get two females: %d\n%s\n", i, sprintResult) >= 0);
  free(sprintResult); 

  check (db_fire(empset_choose(em3).ssNum));
  check (printf("Should get 18 employees\n") >= 0);
  db_print();

  empset_final (em1);
  empset_final (em2);
  empset_final (em3);
  return 0;
}
