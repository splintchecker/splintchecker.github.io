erc: trait
  assumes CTrait
  includes Bag(eref, ercElems)
  erc tuple of val:ercElems, activeIters: int
  ercIter tuple of toYield: ercElems, eObj: ercObj
  introduces
    {}: -> erc
    yielded: eref, ercIter, ercIter -> bool
    startIter: erc -> erc
    endIter: erc -> erc
  asserts
    \forall e: eref, it1, it2: ercIter, c: erc
      {} == [{}, 0];
      yielded(e, it1, it2) == e \in it1.toYield
          /\ it2 = [delete(e, it1.toYield), it1.eObj];
      startIter(c) == [c.val, c.activeIters + 1];
      endIter(c) == [c.val, c.activeIters - 1]
