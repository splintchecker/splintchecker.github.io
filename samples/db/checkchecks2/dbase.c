# include <strings.h>
# include "dbase.h"

typedef enum
{
  mMGRS, fMGRS, mNON, fNON
} employeeKinds;

/*@constant static employeeKinds firstERC;@*/
# define firstERC mMGRS

/*@constant static employeeKinds lastERC;@*/
# define lastERC fNON

/*@constant static int numERCS;@*/
# define numERCS (/*@+enumint@*/ (lastERC - firstERC + 1) /*@=enumint@*/)

typedef /*@only@*/ erc o_erc;
static o_erc db[numERCS];

/*@iter employeeKinds_all (yield employeeKinds ek); @*/
# define employeeKinds_all(m_ek) \
  { employeeKinds m_ek; for (m_ek = firstERC; m_ek <= lastERC; m_ek++) {

# define end_employeeKinds_all }}

static bool initDone = FALSE;

void db_initMod (void)
  /*@globals initDone, undef db@*/
  /*@modifies initDone, db@*/
{
  if (initDone)
    {
      return;
    }
  
  bool_initMod ();
  employee_initMod ();
  eref_initMod ();
  erc_initMod ();
  empset_initMod ();
  
  employeeKinds_all (ek)
    {
      db[(int)ek] = erc_create ();
    } end_employeeKinds_all ;
  
  initDone = TRUE;
}

static eref db_ercKeyGet(erc c, int key) 
{
  erc_elements(c, er)
    {
      if (eref_get(er).ssNum == key) return (er);
    } end_erc_elements ;

  return erefNIL;
}

static eref db_keyGet (int key)
{
  eref er;
  
  employeeKinds_all (ek)
    {
      er = db_ercKeyGet (db[(int) ek], key);
      if (!eref_equal (er, erefNIL))
	{
	  return er;
	}
    } end_employeeKinds_all ;
  
  return erefNIL;
}

static int db_addEmpls (erc c, int l, int h, empset s)
  /*@modifies s@*/
{
  employee e;
  int numAdded;
  numAdded = 0;
  
  erc_elements (c, er) 
    {
      e = eref_get(er);
      if ((e.salary >= l) && (e.salary <= h)) 
	{
	  empset_insert(s, e);
	  numAdded++;
	}
    } end_erc_elements ;

  return numAdded;
}

db_status hire (employee e)
{
  if (e.gen == gender_ANY)
    return genderERR;

  if (e.j == job_ANY)
    return jobERR;

  if (e.salary < 0)
    return salERR;

  if (!eref_equal (db_keyGet (e.ssNum), erefNIL))
    return duplERR;

  uncheckedHire (e);
  return db_OK;
}

void uncheckedHire (employee e)
   /*@globals db@*/
{
  eref er;
  
  er = eref_alloc ();
  eref_assign (er, e);
  
  if (e.gen == MALE)
    if (e.j == MGR)
      erc_insert (db[(int) mMGRS], er);
    else
      erc_insert (db[(int) mNON], er);
  else
    if (e.j == MGR)
      erc_insert (db[(int) fMGRS], er);
    else
      erc_insert (db[(int) fNON], er);
}

bool fire (int ssNum)
  /*@globals db@*/
{
  employeeKinds_all (ek)
    {
      erc_elements (db[(int) ek], er)
	{
	  if (eref_get(er).ssNum == ssNum) 
	    {
	      erc_delete (db[(int) ek], er);
	      return TRUE;
	    } 
	} end_erc_elements ;
    } end_employeeKinds_all ;
  
  return FALSE;
}

bool promote (int ssNum)
  /*@globals db@*/
{
  eref er;
  employee e;
  gender g;
  
  g = MALE;
  er = db_ercKeyGet (db[(int) mNON], ssNum);
  
  if (eref_equal (er, erefNIL))
    {
      er = db_ercKeyGet (db[(int) fNON], ssNum);
      if (eref_equal (er, erefNIL))
	return FALSE;
      g = FEMALE;
    }
  
  e = eref_get (er);
  e.j = MGR;
  eref_assign (er, e);
  
  if (g == MALE)
    {
      erc_delete (db[(int) mNON], er);
      erc_insert (db[(int) mMGRS], er);
    } 
  else
    {
      erc_delete (db[(int) fNON], er);
      erc_insert (db[(int) fMGRS], er);
    }
  
  return TRUE;
}

db_status setSalary (int ssNum, int sal)
{
  eref er;
  employee e;
  
  if (sal < 0)
    {
      return salERR;
    }

  er = db_keyGet (ssNum);

  if (eref_equal (er, erefNIL))
    {
      return missERR;
    }

  e = eref_get (er);
  e.salary = sal;
  eref_assign (er, e);

  return db_OK;
}

int query (db_q q, empset s)
  /*@globals db@*/
{
  int numAdded;
  int l, h;

  l = q.l;
  h = q.h;

  switch (q.g)
    {
    case gender_ANY:
      switch (q.j)
	{
	case job_ANY:
	  numAdded = 0;

	  employeeKinds_all (ek)
	    {
	      numAdded += db_addEmpls (db[(int) ek], l, h, s);
	    } end_employeeKinds_all

	  return numAdded;
	case MGR:
	  numAdded = db_addEmpls (db[(int) mMGRS], l, h, s);
	  numAdded += db_addEmpls (db[(int) fMGRS], l, h, s);
	  return numAdded;
	case NONMGR:
	  numAdded = db_addEmpls (db[(int) mNON], l, h, s);
	  numAdded += db_addEmpls (db[(int) fNON], l, h, s);
	  return numAdded;
	}
    case MALE:
      switch (q.j)
	{
	case job_ANY:
	  numAdded = db_addEmpls (db[(int) mMGRS], l, h, s);
	  numAdded += db_addEmpls (db[(int) mNON], l, h, s);
	  return numAdded;
	case MGR:
	  return db_addEmpls (db[(int) mMGRS], l, h, s);
	case NONMGR:
	  return db_addEmpls (db[(int) mNON], l, h, s);
	}
    case FEMALE:
      switch (q.j)
	{
	case job_ANY:
	  numAdded = db_addEmpls (db[(int) fMGRS], l, h, s);
	  numAdded += db_addEmpls (db[(int) fNON], l, h, s);
	  return numAdded;
	case MGR:
	  return db_addEmpls (db[(int) fMGRS], l, h, s);
	case NONMGR:
	  return db_addEmpls (db[(int) fNON], l, h, s);
	}
    }
}

void db_print (void)
  /*@globals db@*/
{
  char *printVal;
  
  printf ("Employees:\n");

  employeeKinds_all (ek)
    {
      printVal = erc_sprint (db[(int) ek]);
      printf ("%s", printVal);
      free (printVal);
    } end_employeeKinds_all ;
}
