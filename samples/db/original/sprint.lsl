sprint(T, String): trait
  includes cstring
  introduces
    parse: String -> T
    unparse: T -> String
    isSprint: String, T -> bool
  asserts \forall t: T, s: String
    parse(unparse(t)) == t;
    isSprint(s, t) ==
        parse(s) = t /\ nullTerminated(s)
  implies T partitioned by unparse
