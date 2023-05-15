# alphanumsort

`alphanumsort` is a simple C/C++ function which compares strings that can have both and alphabetic and a numeric part.
Alphabetic sort makes the numbers ordering non natural, e.g.
```
$ ls -1 /dev/tty*
/dev/tty
/dev/tty0
/dev/tty1
/dev/tty10
/dev/tty11
/dev/tty12
/dev/tty13
/dev/tty14
/dev/tty15
/dev/tty16
/dev/tty17
/dev/tty18
/dev/tty19
/dev/tty2
/dev/tty20
/dev/tty3
/dev/tty4
/dev/tty5
/dev/tty6
/dev/tty7
/dev/tty8
/dev/tty9
```

`alphanumsort` take cares of the numeric part and orders them by their numeric value:

```
$ ./alphanumsort_c /dev/tty*
/dev/tty
/dev/tty0
/dev/tty1
/dev/tty2
/dev/tty3
/dev/tty4
/dev/tty5
/dev/tty6
/dev/tty7
/dev/tty8
/dev/tty9
/dev/tty10
/dev/tty11
/dev/tty12
/dev/tty13
/dev/tty14
/dev/tty15
/dev/tty16
/dev/tty17
/dev/tty18
/dev/tty19
/dev/tty20
```

## Usage
Just copy the function `alphanumsort` from the corresponding `.c` or `.cpp` file and use as custom sor function.  
In C do it like:
```c
char *strings[];
qsort(strings, num_strings, sizeof(*strings), alphanumsort);
```
In C++:
```cpp
std::vector<std::string> strings;
std::sort(strings.begin(), strings.end(), alphanumsort);
```
