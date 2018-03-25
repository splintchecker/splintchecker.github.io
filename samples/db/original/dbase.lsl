dbase: trait
  assumes dbaseAssumptions
  includes Set(db for C, employee for E, new for {},
               hire for insert)
  db_q tuple of g:gender, j: job, l: int, h: int
  db_status enumeration of db_OK, salERR, genderERR,
                           jobERR, duplERR
introduces
   query: db, db_q -> empset
   match: gender, gender -> bool
   match: job, job -> bool
   fire, promote: db, int -> db
   setSal: db, int, int -> db
   find: db, int -> employee
   employed: db, int -> bool
   numEmployees: db -> int
asserts
   \forall e: employee, k: int, g, gq: gender,
              j, jq: job, q: db_q, sal: int, d: db
     query(new, q) == { };
     query(hire(e, d), q) ==
       if match(q.g, e.gen) /\ match(q.j, e.j)
          /\ q.l <= e.salary /\ e.salary <= q.h
         then insert(e, query(d, q)) else query(d, q);
     match(gq, g) == gq = gender_ANY \/ g = gq;
     match(jq, j) == jq = job_ANY \/ j = jq;
     fire(new, k) == new;
     fire(hire(e, d), k) ==
       if e.ssNum = k
         then fire(d, k) else hire(e, fire(d, k));
     promote(new, k) == new;
     promote(hire(e, d), k) ==
       if e.ssNum = k
         then hire(set_j(e, MGR), promote(d, k)) 
         else hire(e, promote(d, k));
     setSal(new, k, sal) == new;
     setSal(hire(e, d), k, sal) ==
       if e.ssNum = k
         then hire(set_salary(e, sal),
                   setSal(d, k, sal))
         else hire(e, setSal(d, k, sal));
     employed(d, k)
       => (find(d, k).ssNum = k /\ find(d, k) \in d);
     employed(new, k) == false;
     employed(hire(e, d), k) ==
       e.ssNum = k \/ employed(d, k);
     numEmployees(new) == 0;
     numEmployees(hire(e, d)) == numEmployees(d)
        + (if employed(d, e.ssNum) then 0 else 1);
