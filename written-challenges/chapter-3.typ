= Write some sample Lox programs and run them (you can use the implementations of Lox in my repository). Try to come up with edge case behavior I didn't specify here. Does it do what you expect? Why or why not?

- Control flow with if is mentioned but not else if, it does exactly as expected
- Tried putting a semi colon on the next line, rather than the same and it compiled. Lox is not whitespace sensitive.
- Are super class constructors implicitly called like in Java? They are not, you can have a sub class inherit a super class and have the super constructor never called.

= This informal introduction leaves a lot unspecified. List several open questions you have about the language's syntax and semantics. What do you think the answers should be?

- Are fields in classes all private / are all object properties accessible?
  - I assume yes? Though that seems a little odd... how do you do any sort of encapsulation?

- Is there a module system?
  - Presumably no since it wasn't mentioned but it really hammers in how much of a toy language lox is and how it's meant for learning.

- When does garbage collection run?
  - Most likely on some sort of timer / randomly like Java because I know the JVM Garbage Collector can cause programs to freeze. Or maybe there's a smarter time to run it.

= Lox is a pretty tiny language. What features do you think it is missing that would make it annoying to use for real programs? (Aside from the standard library of course.)

- Module system
- Private fields/properties on classes/objects
- Lox (atleast `jlox`) is not a self contained binary. I couldn't arbitrarily move it to a different directory
- Lox can't be built on Windows (atleast not easily)
- No user input
