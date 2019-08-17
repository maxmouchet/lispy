project('lispy', 'c', default_options: ['c_std=c99', 'werror=true'])

# Don't warn on #pragma region ...
add_project_arguments('-Wno-unknown-pragmas', language : 'c')

inc_dir = include_directories(['include/'])
mpc_dep = declare_dependency(include_directories: inc_dir, sources: ['include/mpc.c'])

cc = meson.get_compiler('c')
m_dep = cc.find_library('m', required : false)

libedit_dep = dependency('libedit')

src = ['src/repl.c', 'src/parser.c', 'src/lval.c', 'src/lenv.c', 'src/builtins.c']
executable('repl', src, dependencies: [mpc_dep, libedit_dep, m_dep])