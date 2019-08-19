# Lispy

[![Build Status](https://travis-ci.com/maxmouchet/lispy.svg?token=4sJeU7PhwNeabe27p5Qz&branch=master)](https://travis-ci.com/maxmouchet/lispy)

My own attempt at [_Build Your Own Lisp_](http://www.buildyourownlisp.com).  
_WIP._

```bash
# Debug configuration
export CC=clang
meson -Db_sanitize=address debug
ninja -C debug

# Release configuration
meson -Dbuildtype=release release
ninja -C release
```

```bash
ninja scan-build # requires clang-analyser
valgrind --leak-check=yes ./repl
clang-format -style=Google -i src/*
```

## Other resources

http://norvig.com/lispy.html
