# Leak report

Judging by the hints written in the MD file, I looked at the is_clean function and determined that the string (character array) cleaned does not free itself after its use.  

I then ran valgrind on check_whitepspace_test, and used the hint of giving functions variable declarations and applied that logic to the strip() tests. I also found a source online stating that declaring a pointer to be null afterwards is good programming (and Thatcher also told me it's a good idea), so I did that.

I then went back to the check_whitespace.c file, and fixed an error within lines 30-32 that caused a lack of a pointer by typecasting it to (char* const) and giving it a calloc() with one character (since it's just one char value) and the sizeof(char) because said char value is of the char type