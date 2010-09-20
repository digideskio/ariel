#!/usr/bin/env python

"""
/Profiler waf build script

(C) Copyright 2010 Bryce Lelbach

Use, modification and distribution of this software is subject to the Boost
Software License, Version 1.0, and the new BSD License.

Boost relative to repository root: /doc/BOOST_LICENSE_1_0.rst
Boost online: http://www.boost.org/LICENSE_1_0.txt
"""

def build(bld):
  bld.new_task_gen(
    features     = ['cxx'], 
    target       = 'plugin.o',

    includes     = [
      bld.srcnode.abspath(),
      bld.env.LLVMPATH,
      bld.env.CLANGPATH
    ],
    
    source       = [
      'impl/TIConsumer.cpp',
      'impl/TIAction.cpp',
      '../XML/impl/Document.cpp',
      '../XML/impl/Tree.cpp'
    ],

    defines      = [
      '__STDC_LIMIT_MACROS',
      '__STDC_CONSTANT_MACROS'
    ],
    
    cxxflags     = [
      '-fno-exceptions', '-fno-strict-aliasing', '-fno-rtti', '-fPIC',
      '-fdiagnostics-show-option', '-pedantic', '-Wall',
      '-MD', '-MP', '-MF', '%s/plugin.d' % bld.path.abspath(bld.env),
      '-MT', '%s/plugin.o' % bld.path.abspath(bld.env)
    ]
  );

  bld.new_task_gen(
    features     = ['cxx', 'cshlib'], 
    add_objects  = 'plugin.o',
    target       = 'arielProfiler',
    install_path = '${PREFIX}/lib/',
    vnum         = bld.env.ARIEL,
    libpath      = ['/usr/lib/', '/usr/local/lib/'],
    lib          = ['pthread', 'dl', 'm'],
    
    linkflags    = [
      '-Wl,-R', '-Wl,\'$ORIGIN\'',
      '-Wl,--version-script,%s/Profiler/plugin.exports.map'
      % bld.srcnode.abspath()
    ]
  );

if __name__ == '__main__':
  print '\033[91mError: Waf scripts should not be executed directly.'
  print 'Execute the Waf driver from the top of the repository instead.\033[0m'

