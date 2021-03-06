//===-----------------------------------------------------------*- C++ -*-===//
// (C) Copyright 2010 Bryce Lelbach
//
// Use, modification and distribution of this software is subject to the Boost
// Software License, Version 1.0.
//
// Relative to repository root: /credit/BOOST_LICENSE_1_0.rst
// Online: http://www.boost.org/LICENSE_1_0.txt
//===----------------------------------------------------------------------===//

#if !defined(ARIEL_PP_FOREACH_HXX)
#define ARIEL_PP_FOREACH_HXX

#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/punctuation.hpp>

// for LLVM/Clang containers that prefix begin()/end()
#define ARIEL_LLVM_FOREACH(IterType, It, End, Container, Prefix)  \
  for (IterType It = Container. BOOST_PP_CAT(Prefix, begin)       \
                  BOOST_PP_LPAREN() BOOST_PP_RPAREN(),            \
                  End = Container. BOOST_PP_CAT(Prefix, end)      \
                  BOOST_PP_LPAREN() BOOST_PP_RPAREN();            \
       It != End; ++It)                                           \
  /**/

#endif // ARIEL_PP_FOREACH_HXX
