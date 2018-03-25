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
  copy_record(new_record, e); 
  new_record->next = curr; 
  if (prev == NULL)  /* inserting at the beginning */
      lst = new_record;
  else               /* inserting at the middle or end*/
    prev->next = new_record;
  return lst;
}
