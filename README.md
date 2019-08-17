# Lispy

http://www.buildyourownlisp.com/contents


```bash
meson build
CC=clang meson build -Db_sanitize=address

# build/
ninja
ninja scan-build # requires clang-analyser
```

## Other resources

http://norvig.com/lispy.html
