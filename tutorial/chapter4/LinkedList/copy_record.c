void copy_record(emp_record *a, emp_record *b)
{
  strncpy(a->LastName, b->LastName, MAX_LENGTH);
  strncpy(a->FirstName, b->FirstName, MAX_LENGTH);
  a->Salary = b->Salary;
  a->next = b->next;
}
