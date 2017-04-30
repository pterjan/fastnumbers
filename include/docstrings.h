#ifndef __DOCSTRINGS
#define __DOCSTRINGS

/*
 * Docstrings for the fastnumbers functions.
 *
 * Author: Seth M. Morton, August 2, 2014
 */
#include <Python.h>


PyDoc_STRVAR(fastnumbers__doc__, "Quickly convert strings to numbers.\n");


PyDoc_STRVAR(fast_real__doc__, 
"fast_real(x, default=None, raise_on_invalid=False, key=None, nan=None, inf=None, coerce=True)\n"
"Quickly convert input to an `int` or `float` depending on value.\n"
"\n"
"Any input that is valid for the built-in `float` or `int` functions will\n"
"be converted to either a `float` or `int`. An input of a single numeric\n"
"unicode character is also valid. The return value is guaranteed\n"
"to be of type `str`, `int`, or `float` (or `long` on Python2).\n"
"\n"
"If the given input is a string and cannot be converted to a `float` or\n"
"`int`, it will be returned as-is unless `default` or `raise_on_invalid`\n"
"is given.\n"
"\n"
"Parameters\n"
"----------\n"
"input : {str, float, int, long}\n"
"    The input you wish to convert to a real number.\n"
"default : optional\n"
"    This value will be returned instead of the input\n"
"    when the input cannot be converted. Has no effect if\n"
"    *raise_on_invalid* is *True*.\n"
"raise_on_invalid : bool, optional\n"
"    If *True*, a `ValueError` will be raised if string input cannot be\n"
"    converted to a `float` or `int`. If *False*, the string will be\n"
"    returned as-is. The default is *False*.\n"
"key : callable, optional\n"
"    If given and the *input* cannot be converted, the input will be\n"
"    passed to the callable object and its return value will be returned.\n"
"    The function must take one and only one required argument.\n"
"nan : optional\n"
"    If the input value is NAN or can be parsed as NAN, return this\n"
"    value instead of NAN.\n"
"inf : optional\n"
"    If the input value is INF or can be parsed as INF, return this\n"
"    value instead of INF.\n"
"coerce : bool, optional\n"
"    If the input can be converted to an `int` without loss of precision\n"
"    (even if the input was a `float` or float-containing `str`)\n"
"    coerce to an *int* rather than returning a `float`.\n"
"\n"
"Returns\n"
"-------\n"
"out : {str, float, int, long}\n"
"    If the input could be converted to an `int`, the return type will be\n"
"    `int` (or `long` on Python2 if the integer is large enough).\n"
"    If the input could be converted to a `float` but not an `int`, the\n"
"    return type will be `float`.  Otherwise, the input `str` will be\n"
"    returned as-is (if `raise_on_invalid` is *False*) or whatever value\n"
"    is assigned to `default` if `default` is not *None*.\n"
"\n"
"Raises\n"
"------\n"
"TypeError\n"
"    If the input is not one of `str`, `float`, or `int`\n"
"    (or `long` on Python2).\n"
"ValueError\n"
"    If `raise_on_invalid` is *True*, this will be raised if the input\n"
"    string cannot be converted to a `float` or `int`.\n"
"\n"
"See Also\n"
"--------\n"
"isreal\n"
"real\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import fast_real\n"
"    >>> fast_real('56')\n"
"    56\n"
"    >>> fast_real('56.0')\n"
"    56\n"
"    >>> fast_real('56.0', coerce=False)\n"
"    56.0\n"
"    >>> fast_real('56.07')\n"
"    56.07\n"
"    >>> fast_real('56.07 lb')\n"
"    '56.07 lb'\n"
"    >>> fast_real(56.07)\n"
"    56.07\n"
"    >>> fast_real(56.0)\n"
"    56\n"
"    >>> fast_real(56.0, coerce=False)\n"
"    56.0\n"
"    >>> fast_real(56)\n"
"    56\n"
"    >>> fast_real('invalid', default=50)\n"
"    50\n"
"    >>> fast_real('invalid', 50)  # 'default' is first optional positional arg\n"
"    50\n"
"    >>> fast_real('nan')\n"
"    nan\n"
"    >>> fast_real('nan', nan=0)\n"
"    0\n"
"    >>> fast_real('56.07', nan=0)\n"
"    56.07\n"
"    >>> fast_real('56.07 lb', raise_on_invalid=True) #doctest: +IGNORE_EXCEPTION_DETAIL\n"
"    Traceback (most recent call last):\n"
"      ...\n"
"    ValueError: could not convert string to float: '56.07 lb'\n"
"    >>> fast_real('invalid', key=len)\n"
"    7\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> def py_fast_real(input, default=None, raise_on_invalid=False,\n"
"    ...                  key=None, nan=None, inf=None):\n"
"    ...     import math\n"
"    ...     try:\n"
"    ...         a = float(input)\n"
"    ...     except ValueError:\n"
"    ...         if raise_on_invalid:\n"
"    ...             raise\n"
"    ...         elif key is not None:\n"
"    ...             return key(input)\n"
"    ...         elif default is not None:\n"
"    ...             return default\n"
"    ...         else:\n"
"    ...             return input\n"
"    ...     else:\n"
"    ...         if nan is not None and math.isnan(a):\n"
"    ...             return nan\n"
"    ...         elif inf is not None and math.isinf(a):\n"
"    ...             return inf\n"
"    ...         else:\n"
"    ...             return int(a) if a.is_integer() else a\n"
"    ... \n"
"\n");


PyDoc_STRVAR(fast_float__doc__, 
"fast_float(x, default=None, raise_on_invalid=False, key=None, nan=None, inf=None)\n"
"Quickly convert input to a `float`.\n"
"\n"
"Any input that is valid for the built-in `float` function will\n"
"be converted to a `float`. An input of a single numeric\n"
"unicode character is also valid. The return value is guaranteed\n"
"to be of type `str` or `float`.\n"
"\n"
"If the given input is a string and cannot be converted to a `float`\n"
"it will be returned as-is unless `default` or `raise_on_invalid`\n"
"is given.\n"
"\n"
"Parameters\n"
"----------\n"
"input : {str, float, int, long}\n"
"    The input you wish to convert to a `float`.\n"
"default : optional\n"
"    This value will be returned instead of the input\n"
"    when the input cannot be converted. Has no effect if\n"
"    *raise_on_invalid* is *True*.\n"
"raise_on_invalid : bool, optional\n"
"    If *True*, a `ValueError` will be raised if string input cannot be\n"
"    converted to a `float`.  If *False*, the string will be\n"
"    returned as-is.  The default is *False*.\n"
"key : callable, optional\n"
"    If given and the *input* cannot be converted, the input will be\n"
"    passed to the callable object and its return value will be returned.\n"
"    The function must take one and only one required argument.\n"
"nan : optional\n"
"    If the input value is NAN or can be parsed as NAN, return this\n"
"    value instead of NAN.\n"
"inf : optional\n"
"    If the input value is INF or can be parsed as INF, return this\n"
"    value instead of INF.\n"
"\n"
"Returns\n"
"-------\n"
"out : {str, float}\n"
"    If the input could be converted to a `float` the return type will\n"
"    be `float`. Otherwise, the input `str` will be returned as-is\n"
"    (if `raise_on_invalid` is *False*) or whatever value\n"
"    is assigned to *default* if *default* is not *None*.\n"
"\n"
"Raises\n"
"------\n"
"TypeError\n"
"    If the input is not one of `str`, `float`, or `int`\n"
"    (or `long` on Python2).\n"
"ValueError\n"
"    If `raise_on_invalid` is *True*, this will be raised if the input\n"
"    string cannot be converted to a `float`.\n"
"\n"
"See Also\n"
"--------\n"
"isfloat\n"
"float\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import fast_float\n"
"    >>> fast_float('56')\n"
"    56.0\n"
"    >>> fast_float('56.0')\n"
"    56.0\n"
"    >>> fast_float('56.07')\n"
"    56.07\n"
"    >>> fast_float('56.07 lb')\n"
"    '56.07 lb'\n"
"    >>> fast_float(56.07)\n"
"    56.07\n"
"    >>> fast_float(56)\n"
"    56.0\n"
"    >>> fast_float('invalid', default=50)\n"
"    50\n"
"    >>> fast_float('invalid', 50)  # 'default' is first optional positional arg\n"
"    50\n"
"    >>> fast_float('nan')\n"
"    nan\n"
"    >>> fast_float('nan', nan=0.0)\n"
"    0.0\n"
"    >>> fast_float('56.07', nan=0.0)\n"
"    56.07\n"
"    >>> fast_float('56.07 lb', raise_on_invalid=True) #doctest: +IGNORE_EXCEPTION_DETAIL\n"
"    Traceback (most recent call last):\n"
"      ...\n"
"    ValueError: could not convert string to float: '56.07 lb'\n"
"    >>> fast_float('invalid', key=len)\n"
"    7\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> def py_fast_float(input, default=None, raise_on_invalid=False,\n"
"    ...                   key=None, nan=None, inf=None):\n"
"    ...     try:\n"
"    ...         x = float(input)\n"
"    ...     except ValueError:\n"
"    ...         if raise_on_invalid:\n"
"    ...             raise\n"
"    ...         elif key is not None:\n"
"    ...             return key(input)\n"
"    ...         elif default is not None:\n"
"    ...             return default\n"
"    ...         else:\n"
"    ...             return input\n"
"    ...     else:\n"
"    ...         if nan is not None and math.isnan(x):\n"
"    ...             return nan\n"
"    ...         elif inf is not None and math.isinf(x):\n"
"    ...             return inf\n"
"    ...         else:\n"
"    ...             return x\n"
"    ... \n"
"\n");


PyDoc_STRVAR(fast_int__doc__, 
"fast_int(x, default=None, raise_on_invalid=False, key=None, base=10)\n"
"Quickly convert input to an `int`.\n"
"\n"
"Any input that is valid for the built-in `int` (or `long` on Python2)\n"
"function will be converted to a `int` (or `long` on Python2). An input\n"
"of a single digit unicode character is also valid. The return value\n"
"is guaranteed to be of type `str` or `int` (or `long` on Python2).\n"
"\n"
"If the given input is a string and cannot be converted to an `int`\n"
"it will be returned as-is unless `default` or `raise_on_invalid`\n"
"is given.\n"
"\n"
"Parameters\n"
"----------\n"
"input : {str, float, int, long}\n"
"    The input you wish to convert to an `int`.\n"
"default : optional\n"
"    This value will be returned instead of the input\n"
"    when the input cannot be converted. Has no effect if\n"
"    *raise_on_invalid* is *True*.\n"
"raise_on_invalid : bool, optional\n"
"    If *True*, a `ValueError` will be raised if string input cannot be\n"
"    converted to an `int`. If *False*, the string will be\n"
"    returned as-is. The default is *False*.\n"
"key : callable, optional\n"
"    If given and the *input* cannot be converted, the input will be\n"
"    passed to the callable object and its return value will be returned.\n"
"    The function must take one and only one required argument.\n"
"base : int, optional\n"
"    Follows the rules of Python's built-in :func:`int`; see it's\n"
"    documentation for your Python version. If given, the input\n"
"    **must** be of type `str`.\n"
"\n"
"Returns\n"
"-------\n"
"out : {str, int, long}\n"
"    If the input could be converted to an `int`, the return type will be\n"
"    `int` (or `long` on Python2 if the integer is large enough).\n"
"    Otherwise, the input `str` will be returned as-is\n"
"    (if `raise_on_invalid` is *False*) or whatever value\n"
"    is assigned to *default* if *default* is not *None*.\n"
"\n"
"Raises\n"
"------\n"
"TypeError\n"
"    If the input is not one of `str`, `float`, or `int`\n"
"    (or `long` on Python2).\n"
"ValueError\n"
"    If `raise_on_invalid` is *True*, this will be raised if the input\n"
"    string cannot be converted to an `int`.\n"
"\n"
"See Also\n"
"--------\n"
"fast_forceint\n"
"isint\n"
"int\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import fast_int\n"
"    >>> fast_int('56')\n"
"    56\n"
"    >>> fast_int('56.0')\n"
"    '56.0'\n"
"    >>> fast_int('56.07 lb')\n"
"    '56.07 lb'\n"
"    >>> fast_int(56.07)\n"
"    56\n"
"    >>> fast_int(56)\n"
"    56\n"
"    >>> fast_int('invalid', default=50)\n"
"    50\n"
"    >>> fast_int('invalid', 50)  # 'default' is first optional positional arg\n"
"    50\n"
"    >>> fast_int('56.07 lb', raise_on_invalid=True) #doctest: +IGNORE_EXCEPTION_DETAIL\n"
"    Traceback (most recent call last):\n"
"      ...\n"
"    ValueError: could not convert string to int: '56.07 lb'\n"
"    >>> fast_int('invalid', key=len)\n"
"    7\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> def py_fast_int(input, default=None, raise_on_invalid=False, key=None):\n"
"    ...     try:\n"
"    ...         return int(input)\n"
"    ...     except ValueError:\n"
"    ...         if raise_on_invalid:\n"
"    ...             raise\n"
"    ...         elif key is not None:\n"
"    ...             return key(input)\n"
"    ...         elif default is not None:\n"
"    ...             return default\n"
"    ...         else:\n"
"    ...             return input\n"
"    ... \n"
"\n");


PyDoc_STRVAR(fast_forceint__doc__, 
"fast_forceint(x, default=None, raise_on_invalid=False, key=None)\n"
"Quickly convert input to an `int`, truncating if is a `float`.\n"
"\n"
"Any input that is valid for the built-in `int` (or `long` on Python2)\n"
"function will be converted to a `int` (or `long` on Python2). An input\n"
"of a single numeric unicode character is also valid. The return value\n"
"is guaranteed to be of type `str` or `int` (or `long` on Python2).\n"
"\n"
"In addition to the above, any input valid for the built-in `float` will\n"
"be parsed and the truncated to the nearest integer; for example, '56.07'\n"
"will be converted to `56`.\n"
"\n"
"If the given input is a string and cannot be converted to an `int`\n"
"it will be returned as-is unless `default` or `raise_on_invalid`\n"
"is given.\n"
"\n"
"Parameters\n"
"----------\n"
"input : {str, float, int, long}\n"
"    The input you wish to convert to an `int`.\n"
"default : optional\n"
"    This value will be returned instead of the input\n"
"    when the input cannot be converted. Has no effect if\n"
"    *raise_on_invalid* is *True*\n"
"raise_on_invalid : bool, optional\n"
"    If *True*, a `ValueError` will be raised if string input cannot be\n"
"    converted to an `int`.  If *False*, the string will be\n"
"    returned as-is.  The default is *False*.\n"
"key : callable, optional\n"
"    If given and the *input* cannot be converted, the input will be\n"
"    passed to the callable object and its return value will be returned.\n"
"    The function must take one and only one required argument.\n"
"\n"
"Returns\n"
"-------\n"
"out : {str, int, long}\n"
"    If the input could be converted to an `int`, the return type will be\n"
"    `int` (or `long` on Python2 if the integer is large enough).\n"
"    Otherwise, the input `str` will be returned as-is\n"
"    (if `raise_on_invalid` is *False*) or whatever value\n"
"    is assigned to *default* if *default* is not *None*.\n"
"\n"
"Raises\n"
"------\n"
"TypeError\n"
"    If the input is not one of `str`, `float`, or `int`\n"
"    (or `long` on Python2).\n"
"ValueError\n"
"    If `raise_on_invalid` is *True*, this will be raised if the input\n"
"    string cannot be converted to an `int`.\n"
"\n"
"See Also\n"
"--------\n"
"fast_int\n"
"isintlike\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import fast_forceint\n"
"    >>> fast_forceint('56')\n"
"    56\n"
"    >>> fast_forceint('56.0')\n"
"    56\n"
"    >>> fast_forceint('56.07')\n"
"    56\n"
"    >>> fast_forceint('56.07 lb')\n"
"    '56.07 lb'\n"
"    >>> fast_forceint(56.07)\n"
"    56\n"
"    >>> fast_forceint(56)\n"
"    56\n"
"    >>> fast_forceint('invalid', default=50)\n"
"    50\n"
"    >>> fast_forceint('invalid', 50)  # 'default' is first optional positional arg\n"
"    50\n"
"    >>> fast_forceint('56.07 lb', raise_on_invalid=True) #doctest: +IGNORE_EXCEPTION_DETAIL\n"
"    Traceback (most recent call last):\n"
"      ...\n"
"    ValueError: could not convert string to float: '56.07 lb'\n"
"    >>> fast_forceint('invalid', key=len)\n"
"    7\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> def py_fast_forceint(input, default=None, raise_on_invalid=False, key=None):\n"
"    ...     try:\n"
"    ...         return int(input)\n"
"    ...     except ValueError:\n"
"    ...         try:\n"
"    ...             return int(float(input))\n"
"    ...         except ValueError:\n"
"    ...             if raise_on_invalid:\n"
"    ...                 raise\n"
"    ...             elif key is not None:\n"
"    ...                 return key(input)\n"
"    ...             elif default is not None:\n"
"    ...                 return default\n"
"    ...             else:\n"
"    ...                 return input\n"
"    ... \n"
"\n");


PyDoc_STRVAR(isreal__doc__, 
"isreal(x, str_only=False, num_only=False, allow_inf=False, allow_nan=False)\n"
"Quickly determine if a string is a real number.\n"
"\n"
"Returns *True* if the input is valid input for the built-in `float` or\n"
"`int` functions, or is a single valid numeric unicode character.\n"
"\n"
"The input may be whitespace-padded.\n"
"\n"
"Parameters\n"
"----------\n"
"input :\n"
"    The input you wish to test if it is a real number.\n"
"str_only : bool, optional\n"
"    If *True*, then any non-`str` input will cause this function to return\n"
"    *False*. The default is *False*.\n"
"num_only : bool, optional\n"
"    If *True*, then any `str` input will cause this function to return\n"
"    *False*. The default is *False*.\n"
"allow_inf : bool, optional\n"
"    If *True*, then the strings 'inf' and 'infinity' will also return *True*.\n"
"    This check is case-insensitive, and the string may be signed (i.e. '+/-').\n"
"    The default is *False*.\n"
"allow_nan : bool, optional\n"
"    If *True*, then the string 'nan' will also return *True*.\n"
"    This check is case-insensitive, and the string may be signed (i.e. '+/-').\n"
"    The default is *False*.\n"
"\n"
"Returns\n"
"-------\n"
"result : bool\n"
"    Whether or not the input is a real number.\n"
"\n"
"See Also\n"
"--------\n"
"fast_real\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import isreal\n"
"    >>> isreal('56')\n"
"    True\n"
"    >>> isreal('56.07')\n"
"    True\n"
"    >>> isreal('56.07', num_only=True)\n"
"    False\n"
"    >>> isreal('56.07 lb')\n"
"    False\n"
"    >>> isreal(56.07)\n"
"    True\n"
"    >>> isreal(56.07, str_only=True)\n"
"    False\n"
"    >>> isreal(56)\n"
"    True\n"
"    >>> isreal('nan')\n"
"    False\n"
"    >>> isreal('nan', allow_nan=True)\n"
"    True\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> import re\n"
"    >>> def py_isreal(input, str_only=False, num_only=False,\n"
"    ...               allow_nan=False, allow_inf=False):\n"
"    ...     if str_only and type(input) != str:\n"
"    ...         return False\n"
"    ...     if num_only and type(input) not in (float, int):\n"
"    ...         return False\n"
"    ...     try:\n"
"    ...         x = bool(re.match(r'[-+]?\\d*\\.?\\d+(?:[eE][-+]?\\d+)?$', input))\n"
"    ...     except TypeError:\n"
"    ...         return type(input) in (float, int)\n"
"    ...     else:\n"
"    ...         if x:\n"
"    ...             return True\n"
"    ...         elif allow_inf and input.lower().strip().lstrip('-+') in ('inf', 'infinity'):\n"
"    ...             return True\n"
"    ...         elif allow_nan and input.lower().strip().lstrip('-+') == 'nan':\n"
"    ...             return True\n"
"    ...         else:\n"
"    ...             return False\n"
"    ... \n"
"\n");


PyDoc_STRVAR(isfloat__doc__, 
"isfloat(x, str_only=False, num_only=False, allow_inf=False, allow_nan=False)\n"
"Quickly determine if a string is a `float`.\n"
"\n"
"Returns *True* if the input is valid input for the built-in `float`\n"
"function, is already a valid `float`, or is a single valid numeric unicode\n"
"character. It differs from `isreal` in that an `int` input will return\n"
"*False*.\n"
"\n"
"The input may be whitespace-padded.\n"
"\n"
"Parameters\n"
"----------\n"
"input :\n"
"    The input you wish to test if it is a `float`.\n"
"str_only : bool, optional\n"
"    If *True*, then any non-`str` input will cause this function to return\n"
"    *False*. The default is *False*.\n"
"num_only : bool, optional\n"
"    If *True*, then any `str` input will cause this function to return\n"
"    *False*. The default is *False*.\n"
"allow_inf : bool, optional\n"
"    If *True*, then the strings 'inf' and 'infinity' will also return *True*.\n"
"    This check is case-insensitive, and the string may be signed (i.e. '+/-').\n"
"    The default is *False*.\n"
"allow_nan : bool, optional\n"
"    If *True*, then the string 'nan' will also return *True*.\n"
"    This check is case-insensitive, and the string may be signed (i.e. '+/-').\n"
"    The default is *False*.\n"
"\n"
"Returns\n"
"-------\n"
"result : bool\n"
"    Whether or not the input is a `float`.\n"
"\n"
"See Also\n"
"--------\n"
"fast_float, isreal\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import isfloat\n"
"    >>> isfloat('56')\n"
"    True\n"
"    >>> isfloat('56.07')\n"
"    True\n"
"    >>> isreal('56.07', num_only=True)\n"
"    False\n"
"    >>> isfloat('56.07 lb')\n"
"    False\n"
"    >>> isfloat(56.07)\n"
"    True\n"
"    >>> isfloat(56.07, str_only=True)\n"
"    False\n"
"    >>> isfloat(56)\n"
"    False\n"
"    >>> isfloat('nan')\n"
"    False\n"
"    >>> isfloat('nan', allow_nan=True)\n"
"    True\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> import re\n"
"    >>> def py_isfloat(input, str_only=False, num_only=False,\n"
"    ...                allow_nan=False, allow_inf=False):\n"
"    ...     if str_only and type(input) != str:\n"
"    ...         return False\n"
"    ...     if num_only and type(input) != float:\n"
"    ...         return False\n"
"    ...     try:\n"
"    ...         x = bool(re.match(r'[-+]?\\d*\\.?\\d+(?:[eE][-+]?\\d+)?$', input))\n"
"    ...     except TypeError:\n"
"    ...         return type(input) == float\n"
"    ...     else:\n"
"    ...         if x:\n"
"    ...             return True\n"
"    ...         elif allow_inf and input.lower().strip().lstrip('-+') in ('inf', 'infinity'):\n"
"    ...             return True\n"
"    ...         elif allow_nan and input.lower().strip().lstrip('-+') == 'nan':\n"
"    ...             return True\n"
"    ...         else:\n"
"    ...             return False\n"
"\n");


PyDoc_STRVAR(isint__doc__, 
"isint(x, str_only=False, num_only=False)\n"
"Quickly determine if a string is an `int`.\n"
"\n"
"Returns *True* if the input is valid input for the built-in `int`\n"
"function, is already a valid `int`, or is a single valid digit unicode\n"
"character. It differs from `isintlike` in that a `float` input will\n"
"return *False* and that `int`-like strings (i.e. '45.0') will return\n"
"*False*.\n"
"\n"
"The input may be whitespace-padded.\n"
"\n"
"Parameters\n"
"----------\n"
"input :\n"
"    The input you wish to test if it is an `int`.\n"
"str_only : bool, optional\n"
"    If *True*, then any non-`str` input will cause this function to return\n"
"    *False*. The default is *False*.\n"
"num_only : bool, optional\n"
"    If *True*, then any `str` input will cause this function to return\n"
"    *False*. The default is *False*.\n"
"\n"
"Returns\n"
"-------\n"
"result : bool\n"
"    Whether or not the input is an `int`.\n"
"\n"
"See Also\n"
"--------\n"
"fast_int, isintlike\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import isint\n"
"    >>> isint('56')\n"
"    True\n"
"    >>> isint('56', num_only=True)\n"
"    False\n"
"    >>> isint('56.07')\n"
"    False\n"
"    >>> isint('56.07 lb')\n"
"    False\n"
"    >>> isint(56.07)\n"
"    False\n"
"    >>> isint(56)\n"
"    True\n"
"    >>> isint(56, str_only=True)\n"
"    False\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> import re\n"
"    >>> def py_isint(input, str_only=False, num_only=False):\n"
"    ...     if str_only and type(input) != str:\n"
"    ...         return False\n"
"    ...     if num_only and type(input) != int:\n"
"    ...         return False\n"
"    ...     try:\n"
"    ...         return bool(re.match(r'[-+]?\\d+$', input))\n"
"    ...     except TypeError:\n"
"    ...         return False\n"
"    ... \n"
"\n");


PyDoc_STRVAR(isintlike__doc__, 
"isintlike(x, str_only=False, num_only=False)\n"
"Quickly determine if a string (or object) is an `int` or `int`-like.\n"
"\n"
"Returns *True* if the input is valid input for the built-in `int`\n"
"function, is already a valid `int` or `float`, or is a single valid\n"
"numeric unicode character. It differs from `isintlike` in that `int`-like\n"
"floats or strings (i.e. '45.0') will return *True*.\n"
"\n"
"The input may be whitespace-padded.\n"
"\n"
"Parameters\n"
"----------\n"
"input :\n"
"    The input you wish to test if it is a `int`-like.\n"
"\n"
"Returns\n"
"-------\n"
"result : bool\n"
"    Whether or not the input is an `int`.\n"
"str_only : bool, optional\n"
"    If *True*, then any non-`str` input will cause this function to return\n"
"    *False*. The default is *False*.\n"
"num_only : bool, optional\n"
"    If *True*, then any `str` input will cause this function to return\n"
"    *False*. The default is *False*.\n"
"\n"
"See Also\n"
"--------\n"
"fast_forceint\n"
"\n"
"Examples\n"
"--------\n"
"\n"
"    >>> from fastnumbers import isintlike\n"
"    >>> isintlike('56')\n"
"    True\n"
"    >>> isintlike('56', num_only=True)\n"
"    False\n"
"    >>> isintlike('56.07')\n"
"    False\n"
"    >>> isintlike('56.0')\n"
"    True\n"
"    >>> isintlike('56.07 lb')\n"
"    False\n"
"    >>> isintlike(56.07)\n"
"    False\n"
"    >>> isintlike(56.0)\n"
"    True\n"
"    >>> isintlike(56.0, str_only=True)\n"
"    False\n"
"    >>> isintlike(56)\n"
"    True\n"
"\n"
"Notes\n"
"-----\n"
"It is roughly equivalent to (but much faster than)\n"
"\n"
"    >>> import re\n"
"    >>> def py_isintlike(input, str_only=False, num_only=False):\n"
"    ...     if str_only and type(input) != str:\n"
"    ...         return False\n"
"    ...     if num_only and type(input) not in (int, float):\n"
"    ...         return False\n"
"    ...     try:\n"
"    ...         if re.match(r'[-+]?\\d+$', input):\n"
"    ...             return True\n"
"    ...         elif re.match(r'[-+]?\\d*\\.?\\d+(?:[eE][-+]?\\d+)?$', input):\n"
"    ...             return float(input).is_integer()\n"
"    ...         else:\n"
"    ...             return False\n"
"    ...     except TypeError:\n"
"    ...         if type(input) == float:\n"
"    ...             return input.is_integer()\n"
"    ...         elif type(input) == int:\n"
"    ...             return True\n"
"    ...         else:\n"
"    ...             return False\n"
"    ... \n"
"\n");


PyDoc_STRVAR(fastnumbers_int__doc__,
"int(x=0, base=10)\n"
"Drop-in but faster replacement for the built-in *int*.\n"
"\n"
"Behaves identically to the built-in *int* except for the following:\n"
"\n"
"    - Cannot convert from the ``__trunc__`` special method of an object.\n"
"    - Is implemented as a function, not a class, which means it cannot be\n"
"      sub-classed, and has no *from_bytes* classmethod.\n"
"\n");


PyDoc_STRVAR(fastnumbers_float__doc__,
"float(x=0)\n"
"Drop-in but faster replacement for the built-in *float*.\n"
"\n"
"Behaves identically to the built-in *float* except for the following:\n"
"\n"
"    - Is implemented as a function, not a class, which means it cannot be\n"
"      sub-classed, and has no *fromhex* classmethod.\n"
"    - A *ValueError* will be raised instead of a *UnicodeEncodeError*\n"
"      if a partial surrogate is given as input.\n"
"\n");


PyDoc_STRVAR(fastnumbers_real__doc__,
"real(x=0.0, coerce=True)\n"
"Convert to *float* or *int*, whichever is most appropriate.\n"
"\n"
"If an *int* literal or string containing an *int* is provided,\n"
"then an *int* will be returned. If a *float* literal or a string\n"
"containing a non-*int* and non-*complex* number is provided,\n"
"a *float* will be returned.\n"
"\n"
"If *coerce* is *True* (the default), then if a *float* is given\n"
"that has no decimal places after conversion or only zeros after\n"
"the decimal point, it will be returned as an *int* instead of a\n"
"*float*.\n"
"\n");

#endif /* __DOCSTRINGS */
