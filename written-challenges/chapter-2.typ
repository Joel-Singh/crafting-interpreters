= Pick an open source implementation of a language you like. Download the source code and poke around in it. Try to find the code that implements the scanner and parser. Are they handwritten, or generated using tools like Lex and Yacc? (`.l` or `.y` files usually imply the latter.)

For Rust, the scanner and parser are written directly in Rust.

= Just-in-time compilation tends to be the fastest way to implement dynamically typed languages, but not all of them use it. What reasons are there to not JIT?

Despite the speed of JIT, it is more complicated to implement.

= Most Lisp implementation that compile to C also contain an interpreter that lets them execute Lisp code on the fly as well? Why?

The interpreter allows for a programming approach where expressions are
executed as you write code for an incredibly fast iteration cycle.
