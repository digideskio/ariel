//===-----------------------------------------------------------*- C++ -*-===//
// (C) Copyright 2010 Bryce Lelbach
//
// Use, modification and distribution of this software is subject to the Boost
// Software License, Version 1.0.
//
// Relative to repository root: /credit/BOOST_LICENSE_1_0.rst
// Online: http://www.boost.org/LICENSE_1_0.txt
//===----------------------------------------------------------------------===//

#if !defined(ARIEL_PROFILER_NULL_WRITER_HXX)
#define ARIEL_PROFILER_NULL_WRITER_HXX

#include <ariel/ir/node.hxx>

#include <ariel/profiler/traits.hxx>
#include <ariel/profiler/writers/writer_builder.hxx>

namespace ariel {
namespace profiler {

ARIEL_WRITER_PARAMS(Filter)
class null_writer: public Filter<null_writer<Filter> > {
 public:
  typedef production_traits<null_writer> traits;

  typedef typename traits::writer_type   writer_type;
  typedef typename traits::filter_type   filter_type;
  typedef typename traits::consumer_type consumer_type;

  template<class ClangContext>
  void call (ClangContext& clang_ctx, ir::context& ariel_ctx) { }
};

} // profiler
} // ariel

#endif // ARIEL_PROFILER_NULL_WRITER_HXX
