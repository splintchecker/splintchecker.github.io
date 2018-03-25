emp_list add_employees(emp_list lst);

int main()
{
  emp_record *zim = malloc(sizeof(*zim));
  emp_list test_list = emp_list_create();
  
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
