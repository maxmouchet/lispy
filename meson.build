project('lispy', 'c')

inc_dir = include_directories(['include/'])
mpc_dep = declare_dependency(include_directories: inc_dir, sources: ['include/mpc.c'])

libedit_dep = dependency('libedit')

src = ['src/repl.c', 'src/parser.c', 'src/lval.c', 'src/builtins.c']
executable('repl', src, dependencies: [mpc_dep, libedit_dep])