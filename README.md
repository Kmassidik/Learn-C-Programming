# 📝 The C Programming Language (K&R 2nd Edition) — Exercise Checklist

## 📘 Chapter 1: A Tutorial Introduction (24 Exercises)

[x] 1-1: Run "hello world"; experiment with leaving out parts to observe errors.  
[x] 1-2: Experiment to find out what happens when printf's argument string contains \c.  
[x] 1-3: Modify the temperature conversion program to print a heading above the table.  
[x] 1-4: Write a program to print the Celsius to Fahrenheit table.  
[x] 1-5: Modify the temperature program to print the table in reverse order.  
[x] 1-6: Verify that the expression getchar() != EOF is 0 or 1.  
[x] 1-7: Write a program to print the value of EOF.  
[x] 1-8: Write a program to count blanks, tabs, and newlines.  
[x] 1-9: Replace strings of blanks with a single blank.  
[x] 1-10: Make tabs, backspaces, and backslashes visible.  
[x] 1-11: Devise good test cases for the word count program.  
[x] 1-12: Print input one word per line.  
[x] 1-13: Print a histogram of word lengths.  
[x] 1-14: Print a histogram of character frequencies.  
[x] 1-15: Rewrite temperature conversion using a function.  
[x] 1-16: Fix longest-line program to handle arbitrarily long lines.  
[x] 1-17: Print all input lines longer than 80 characters.  
[x] 1-18: Remove trailing blanks/tabs and delete blank lines.  
[x] 1-19: reverse(s): reverse each input line.  
[x] 1-20: detab: replace tabs with proper number of spaces.  
[ ] 1-21: entab: replace spaces with minimal tabs+spaces.  
[ ] 1-22: Fold long input lines.  
[ ] 1-23: Remove all comments from a C program.  
[ ] 1-24: Check rudimentary syntax errors (unbalanced braces, etc.).

---

## 🧮 Chapter 2: Types, Operators, and Expressions (10 Exercises)

[ ] 2-1: Determine ranges of basic types.  
[ ] 2-2: Rewrite for-loop without && or ||.  
[ ] 2-3: htoi(s): convert hex string to int.  
[ ] 2-4: squeeze(s1, s2): delete chars from s1 present in s2.  
[ ] 2-5: any(s1, s2): find first location of any s2 char in s1.  
[ ] 2-6: setbits(x,p,n,y): set n bits at p to rightmost n of y.  
[ ] 2-7: invert(x,p,n): invert n bits starting at p.  
[ ] 2-8: rightrot(x,n): rotate x right by n positions.  
[ ] 2-9: Explain x&=(x−1) trick; faster bitcount.  
[ ] 2-10: Rewrite lower(c) using conditional expression.

---

## 🌀 Chapter 3: Control Flow (6 Exercises)

[ ] 3-1: Rewrite binary search with one test.  
[ ] 3-2: escape(s,t) and reverse escape.  
[ ] 3-3: expand(s1,s2): expand shorthand notations like a-z.  
[ ] 3-4: Modify itoa for largest negative number.  
[ ] 3-5: itob(n,s,b): integer to base-b string.  
[ ] 3-6: itoa with minimum field width (left padded).

---

## 🧭 Chapter 4: Functions and Program Structure (14 Exercises)

[ ] 4-1: strrindex(s,t): rightmost occurrence.  
[ ] 4-2: Extend atof for scientific notation.  
[ ] 4-3: Extend RPN calculator for %, negatives.  
[ ] 4-4: Add stack commands (print, dup, swap, clear).  
[ ] 4-5: Add math funcs (sin, exp, pow).  
[ ] 4-6: Add variables (26 + last printed).  
[ ] 4-7: ungets(s): push back string.  
[ ] 4-8: Simplify getch/ungetch (1-char pushback).  
[ ] 4-9: Handle EOF correctly in getch/ungetch.  
[ ] 4-10: Buffer-based input for calculator.  
[ ] 4-11: Remove need for ungetch in getop.  
[ ] 4-12: Recursive itoa (printd).  
[ ] 4-13: Recursive reverse(s).  
[ ] 4-14: Macro swap(t,x,y).

---

## 🧭 Chapter 5: Pointers and Arrays (20 Exercises)

[ ] 5-1: Fix getint to push back sign correctly.  
[ ] 5-2: Write getfloat.  
[ ] 5-3: Pointer version of strcat.  
[ ] 5-4: strend(s,t): t at end of s?.  
[ ] 5-5: strncpy, strncat, strncmp.  
[ ] 5-6: Rewrite previous programs with pointers.  
[ ] 5-7: Rewrite readlines to use array from main.  
[ ] 5-8: Add error checking to day_of_year / month_day.  
[ ] 5-9: Rewrite day_of_year & month_day with pointers.  
[ ] 5-10: expr: reverse Polish evaluator.  
[ ] 5-11: entab/detab with tab stop args.  
[ ] 5-12: entab -m +n shorthand.  
[ ] 5-13: tail: print last n lines.  
[ ] 5-14: sort -r flag.  
[ ] 5-15: sort -f flag (case fold).  
[ ] 5-16: sort -d (directory order).  
[ ] 5-17: sort by fields.  
[ ] 5-18: Make dcl recover from errors.  
[ ] 5-19: Fix undcl redundant parentheses.  
[ ] 5-20: Extend dcl for function args & const.

---

## 🧱 Chapter 6: Structures (6 Exercises)

[ ] 6-1: Improve getword (underscores, strings, comments, preproc).  
[ ] 6-2: Print groups of variable names identical in first K chars.  
[ ] 6-3: Cross-referencer: word list with line numbers.  
[ ] 6-4: Print distinct words sorted by decreasing frequency.  
[ ] 6-5: undef(): remove name from lookup/install table.  
[ ] 6-6: Simple #define processor (no args).

---

## 🖨️ Chapter 7: Input and Output (9 Exercises)

[ ] 7-1: Case conversion depending on argv[0].  
[ ] 7-2: Print arbitrary input sensibly (non-graphic → octal/hex).  
[ ] 7-3: Improve minprintf.  
[ ] 7-4: minscanf: simple scanf clone.  
[ ] 7-5: Rewrite postfix calc using scanf/sscanf.  
[ ] 7-6: Compare two files, print first differing line.  
[ ] 7-7: Pattern finder reading named files.  
[ ] 7-8: Print files with title, page count.  
[ ] 7-9: Optimize isupper (space vs time).

---

## 🧰 Chapter 8: The UNIX System Interface (8 Exercises)

[ ] 8-1: Rewrite cat using read/write/open/close.  
[ ] 8-2: Rewrite fopen and \_fillbuf with fields.  
[ ] 8-3: Implement \_flushbuf, fflush, fclose.  
[ ] 8-4: Implement fseek like lseek.  
[ ] 8-5: Print full file info using stat.  
[ ] 8-6: calloc(n,size): zero-initialized malloc.  
[ ] 8-7: Improve malloc/free checks.  
[ ] 8-8: bfree(p,n): free arbitrary block into free list.
