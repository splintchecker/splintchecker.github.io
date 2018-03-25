employeeConstants: trait
  assumes CTrait
  introduces
    maxEmployeeName, employeePrintSize: -> int
  asserts equations
    maxEmployeeName > 0 /\ maxEmployeeName <= 20;
    employeePrintSize > 0 /\ employeePrintSize <= 80
