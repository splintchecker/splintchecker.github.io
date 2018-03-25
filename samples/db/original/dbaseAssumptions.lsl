dbaseAssumptions: trait
  includes Set(employee for E, empset for C)
  gender enumeration of MALE, FEMALE, gender_ANY
  job enumeration of MGR, NONMGR, job_ANY
  employee tuple of ssNum: int,
                    name: employee_name,
                    salary: int,
                    gen: gender,
                    j: job
