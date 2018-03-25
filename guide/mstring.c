typedef /*@abstract@*/ /*@null@*/ char *mstring;

static /*@notnull@*/ mstring mstring_createNew (int x) ;

mstring mstring_space (void)
{
  mstring m = mstring_createNew (1);

  *m = ' '; *(m + 1) = '\0';
  return m;
}
