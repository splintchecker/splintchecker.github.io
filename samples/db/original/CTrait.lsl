% Skeleton CTrait.lsl 

%      This version of CTrait introduces operators on four sorts (int, double, 
% char, and String), but does not axiomatize the properties of those operators.
% Axioms can be obtained from the LSL Handbook using the following complete
% version of CTrait.

%    CTrait: trait
%      includes 
%        Integer(int for Int),
%        FloatingPoint(double for F),
%	 FloatingPoint(float for F),
%        cstring

% In an LCL specification, these four sorts provide semantics for the five C
% data types int, double, float, char, and char[].  

CTrait: trait
  % includes Integer(int for Int)
  includes DecimalLiterals(int for N)
  introduces
    succ:     int      -> int
    pred:     int      -> int
    - __:     int      -> int
    __ + __:  int, int -> int
    __ - __:  int, int -> int
    __ * __:  int, int -> int
    __ < __:  int, int -> Bool
    __ > __:  int, int -> Bool
    __ <= __: int, int -> Bool
    __ >= __: int, int -> Bool
    abs:      int      -> int
    div:      int, int -> int
    mod:      int, int -> int
    min:      int, int -> int
    max:      int, int -> int
  % includes FloatingPoint(double for F)
    0:                        -> double
    1:                        -> double
    - __:      double         -> double
    __ \inv:   double         -> double
    __ + __:   double, double -> double
    __ - __:   double, double -> double
    __ * __:   double, double -> double
    __ / __:   double, double -> double
    __ < __:   double, double -> Bool
    __ > __:   double, double -> Bool
    __ <= __:  double, double -> Bool
    __ >= __:  double, double -> Bool
  % includes FloatingPoint(float for F)
    0:                      -> float
    1:                      -> float
    - __:      float        -> float
    __ \inv:   float        -> float
    __ + __:   float, float -> float
    __ - __:   float, float -> float
    __ * __:   float, float -> float
    __ / __:   float, float -> float
    __ < __:   float, float -> Bool
    __ > __:   float, float -> Bool
    __ <= __:  float, float -> Bool
    __ >= __:  float, float -> Bool
  % includes String(char, String)
    empty: ->       String
    __ |- __:       String, char     -> String
    __ -| __:       char, String     -> String
    __ || __:       String, String   -> String
    __ [ __ ]:      String, int      -> char
    __ \in __:      char, String     -> Bool
    { __ }:         char             -> String
    count:          char, String     -> int
    head:           String           -> char
    init:           String           -> String
    isEmpty:        String           -> Bool
    last:           String           -> char
    len:            String           -> int
    prefix:         String, int      -> String
    removePrefix:   String, int      -> String
    substring:      String, int, int -> String
    tail:           String           -> String
  % includes cstring
    null:                            -> char
    nullTerminated: String           -> Bool
    throughNull:    String           -> String
    sameStr:        String, String   -> Bool
    lenStr:         String           -> int
