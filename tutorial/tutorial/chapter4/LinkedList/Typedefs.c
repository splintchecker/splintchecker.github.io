typedef struct emp_rec
{
  char LastName[MAX_LENGTH];
  char FirstName[MAX_LENGTH];
  double Salary;
  struct emp_rec *next;
}  emp_record;


typedef emp_record *emp_list;
