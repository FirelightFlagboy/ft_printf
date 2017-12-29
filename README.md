# ft_printf
project recode function **printf**

>work like **printf**
***
### see projet's pdf for more info
* **[link to pdf](https://cdn.intra.42.fr/pdf/pdf/20/ft_printf.pdf)**
### see man printf
* **[man printf](http://manpagesfr.free.fr/man/man3/printf.3.html)**

***
### Includes
* **wchar.h**
for `wchat_t` type
* **string.h**
for `size_t` def
* **limit.h**
for `OPEN_MAX` and `INT64_MAX`
* **unistd.h**
for `write()`
* **stdlib.h**
for `NULL` and `MB_CURL_MAX`
* **stdarg.h**
for `va_list`, `va_start()`, `va_copy()` and `va_end()`
***
### Constante
* `BUFF_SIZE_PRINTF` : the buffer size of ft_printf when it full it flush
* `NB_FC` : the number of function alias number of working flags
* `NB_COLOR` : the number of color and type
***
#### **Use**
```C
ft_printf("food", bar);
ft_dprintf(FileDescriptor, "foo", bar);
ft_vfprintf(FileDescriptor, "foo", va_list); //<<you can't get it
```

```C
ft_printf(char const *s, ...);
ft_dprintf(int fd, char const *s, ...);
ft_vfprintf(int fd, char const *s, va_list ap);
```
**work also with color**

#### Color
* {red}
* {cyan}
* {green}
* {blue}
* {yellow}
* {magenta}
* {black}
* {white}

#### Style
* {bold}
* {dim}
* {underline}
* {blink}
* {inverted}
* {hidden}

#### Use
* use the balise color like that :
 * `ft_printf("{color|style you want}text+flags", ...);`
***
