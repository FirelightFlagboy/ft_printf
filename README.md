# ft_printf
project recode function **printf**

>work like **printf**

### see projet's pdf for more info
* **[link to pdf](https://cdn.intra.42.fr/pdf/pdf/20/ft_printf.pdf)**

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
* {magenta}
* {black}
* {white}
