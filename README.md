# ft_printf

A 42 School project.
It's purpose is to reimplement the printf function from the stdio library.

This function isn't optimised and doesn't support all functionalities of the original printf.

Supports :
- '%c' (char)
- '%s' (string)
- '%p' (pointer)
- '%d' (int)
- '%i' (int)
- '%u' (unsigned int)
- '%x' (hex)
- '%X' (HEX)

- '%f' (float). /!\ Doesn't round exacly the same way as printf.
- '%e' (scientific notation) /!\ Doesn't round exacly the same way as printf.
- '%E' (scientific notation maj) /!\ Doesn't round exacly the same way as printf.
- '%g' (shortest of f or e) /!\ Incomplete.
- '%G' (shortest of f or e) /!\ Incomplete.

The following flags are supported :
- '-' Left justify
- '0' Padd with 0 instead of spaces.
- '.' Precision (maximum field width (string) & minimum digits used to represent the nbr (numeric)).
- '#' Various prefixes (not all options are implemented)
- ' ' space in front of positive numeric values.
- '+' + in front of positive numeric values.

This project has been build in a way that facilitates implementation of new flags and formats.
