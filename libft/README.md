# Libft - Unified C Library

A complete implementation of the C standard library, expanded with printf functionality and file reading capabilities. This project consolidates the functionalities of **libft**, **ft_printf**, and **get_next_line** into a single robust and efficient library.

## About the Project

**Libft** is a custom C library that reimplements essential functions from the standard library, adding extra functionalities like output formatting and line-by-line file reading. Developed following the strict standards of **42 School**.

## Project Structure

```
libft/
├── Makefile
├── libft.h
├── README.md
└── src/
    ├── basic/          # Original libft functions
    │   ├── ft_*.c
    │   └── ft_*_bonus.c
    ├── printf/         # ft_printf formatting system
    │   ├── ft_printf.c
    │   └── ft_*_utils.c
    └── gnl/           # Get Next Line
        └── get_next_line_bonus.c
```

## 🔧 Compilation and Usage

### Compile the library:
```bash
make
```

### Clean object files:
```bash
make clean
```

### Clean everything:
```bash
make fclean
```

### Recompile:
```bash
make re
```

### Check norminette:
```bash
make norminette
```

### Use in your project:
```c
#include "libft.h"

int main(void)
{
    // Use libft functions
    char **words = ft_split("Hello World", ' ');
    
    // Use ft_printf
    ft_printf("First word: %s\n", words[0]);
    
    // Use get_next_line
    int fd = open("file.txt", O_RDONLY);
    char *line = get_next_line(fd);
    
    return (0);
}
```

## Available Functions

### Character Functions
- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- `ft_toupper`, `ft_tolower`

### String Functions
- `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strncmp`
- `ft_strchr`, `ft_strrchr`, `ft_strnstr`, `ft_strdup`
- `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`
- `ft_strmapi`, `ft_striteri`

### Memory Functions
- `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`
- `ft_memchr`, `ft_memcmp`, `ft_calloc`

### Conversion Functions
- `ft_atoi`, `ft_itoa`

### File Descriptor Functions
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Linked List Functions (Bonus)
- `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`
- `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`
- `ft_lstiter`, `ft_lstmap`

### Printf Functions
- `ft_printf` - Supports: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`

### Get Next Line
- `get_next_line` - Reads files line by line with support for multiple file descriptors

## Configuration

### Buffer Size (Get Next Line)
You can customize the buffer size during compilation:
```bash
make CFLAGS="-Wall -Wextra -Werror -D BUFFER_SIZE=42"
```

## Usage Examples

### String Manipulation
```c
char *str = ft_strjoin("Hello, ", "World!");
char **words = ft_split(str, ' ');
char *trimmed = ft_strtrim("   spaces   ", " ");
```

### Output Formatting
```c
ft_printf("Number: %d, Hex: %x, String: %s\n", 42, 255, "Hello");
ft_printf("Pointer: %p, Char: %c\n", &str, 'A');
```

### File Reading
```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)))
{
    ft_printf("Line: %s", line);
    free(line);
}
close(fd);
```

## 42 School Standards

This project follows all 42 School coding standards:
- ✅ **Norminette** compliant
- ✅ No memory leaks
- ✅ Proper error handling
- ✅ Forbidden functions avoided
- ✅ 25-line function limit

## Features

- **Unified Library**: Single `.a` file with all functionalities
- **Memory Safe**: Proper allocation and deallocation
- **Multiple FD Support**: get_next_line handles multiple file descriptors
- **Optimized**: Efficient algorithms and memory usage
- **Modular**: Clean separation between different functionalities

## Performance

- **ft_split**: O(n) time complexity with optimized memory management
- **get_next_line**: Configurable buffer size for optimal I/O performance  
- **ft_printf**: Fast formatting without external dependencies

## Technical Details

- **Language**: C (C99 standard)
- **Compiler**: gcc with `-Wall -Wextra -Werror`
- **Archive**: Created with `ar rcs`
- **Dependencies**: Only system calls (`write`, `read`, `malloc`, `free`)

---

**Made with ❤️ at 42 School**
