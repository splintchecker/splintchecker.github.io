#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"
#include "assert.h"

#define MAX_LENGTH 20


/*!Begin Typedefs!*/
typedef struct emp_rec
{
  char LastName[MAX_LENGTH];
  char FirstName[MAX_LENGTH];
  double Salary;
  struct emp_rec *next;
}  emp_record;


typedef emp_record *emp_list;
/*!End Typedefs!*/



/*!Begin copy_record!*/
void copy_record(/*@out@*/ emp_record *a, emp_record *b)
{
  strncpy(a->LastName, b->LastName, MAX_LENGTH);
  strncpy(a->FirstName, b->FirstName, MAX_LENGTH);
  a->Salary = b->Salary;
  a->next = b->next;
}
/*!End copy_record!*/


void print_record(emp_record *e)
{
  printf("Last Name: %s\n", e->LastName);
  printf("First Name: %s\n", e->FirstName);
  printf("Salary: %.2f\n", e->Salary);
}
  

/*!Begin emp_list_create!*/
/*@null@*/ emp_list emp_list_create()
{
  return NULL;
}
/*!End emp_list_create!*/

/*!Begin insert_record!*/
emp_list insert_record(emp_list lst, emp_record *e)
{
  emp_record *new_record;
  emp_record *curr = lst;
  emp_record *prev = NULL;

  for(; curr != NULL; prev=curr, curr=curr->next)
    {
      if (strcmp(e->LastName, curr->LastName) <= 0)
	break;
    }
  new_record = malloc(sizeof(*new_record));
  assert(new_record != NULL);  
  copy_record(new_record, e); 
  new_record->next = curr; 
  if (prev == NULL)  /* inserting at the beginning */
      lst = new_record;
  else               /* inserting at the middle or end*/
    prev->next = new_record;
  return lst;
}
/*!End insert_record!*/

emp_list delete_record(emp_list lst, char* lastname)
{
 
  emp_record *curr = lst;
  emp_record *prev = NULL;

  for(; curr != NULL; prev=curr, curr=curr->next)
    {
      if (strcmp(curr->LastName, lastname) == 0)
	break;
    }

  if (curr == NULL)
    {
      printf("delete_record: Employee named %s not found\n", lastname);
      return lst;
    }

  if (prev == NULL) 
      lst = lst->next;   
  else
      prev->next = prev->next->next;
  free(curr);
  return lst;
}    
  


emp_record* find_record(emp_list lst, char* lastname)
{
  
  emp_record *curr = lst;
  emp_record *prev = NULL;

  for(; curr != NULL; prev=curr, curr=curr->next)
    {
      if (strcmp(curr->LastName, lastname) == 0)
	return curr;
    }
  
  printf("find_record: Employee named %s not found\n", lastname);
  return NULL;  
}


void print_list(emp_list lst)
{
  
  emp_record *curr = lst;
  emp_record *prev = NULL;

  for(; curr != NULL; prev=curr, curr=curr->next)
    {    
      print_record(curr); 
      printf("\n");
    }
}


/*!Begin test_bench!*/
emp_list add_employees(emp_list lst);

int main()
{
  emp_record *zim = malloc(sizeof(*zim));
  emp_list test_list = emp_list_create();
  assert(zim != NULL);

  printf("Adding employees...\n\n"); 
  test_list = add_employees(test_list);
  printf("Employee list:\n");
  print_list(test_list);  

  printf("Removing from the middle...\n\n");
  test_list = delete_record(test_list, "Hatton");
  printf("Employee list:\n");
  print_list(test_list);

  printf("Removing the first...\n\n");
  test_list = delete_record(test_list, "Bodycombe");
  printf("Employee list:\n");
  print_list(test_list);

  printf("Inserting an employee at the end...\n\n");
  strncpy(zim->LastName,"Zimmerman", MAX_LENGTH);
  strncpy(zim->FirstName, "Phillip", MAX_LENGTH);
  zim->Salary = 8000.50;
  zim->next = NULL;
  test_list = insert_record(test_list, zim);
  printf("Employee list:\n");
  print_list(test_list);
  
  printf("Finding salary of employee Smullyan...\n\n");
  free(zim);
  zim = find_record(test_list, "Smullyan");
  printf("Salary of Smullyan is: %.2f\n", zim->Salary);


  printf("Revmoing the last employee(Zimmerman)...\n\n");
  test_list = delete_record(test_list, "Zimmerman");
  printf("Employee list:\n");
  print_list(test_list);
  

  return 0;

}


emp_list add_employees(emp_list lst)
{
  emp_record *e = malloc(sizeof(*e));

  FILE *fp = fopen("emp_data.txt", "r");
  char ln[MAX_LENGTH];
  char fn[MAX_LENGTH];
  float sal;

  char Line[3*MAX_LENGTH];
  assert (e != NULL);
  assert (fp != NULL);
  while(fgets(Line, 3*MAX_LENGTH+1, fp))
    {
      sscanf(Line, "%s%s%f", ln, fn, &sal);  
      strncpy(e->LastName, ln, MAX_LENGTH);
      strncpy(e->FirstName, fn, MAX_LENGTH);
      e->Salary=sal;
      lst = insert_record(lst, e);
    }
  return lst;
}
/*!End test_bench!*/


