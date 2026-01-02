= The lexical grammars of Python and Haskell are not _regular_. What does that mean, and why aren't they?

The grammars of Python and Haskell are not regular because they can't be expressed with a regular expression.

= Aside from separating tokens--distinguishing `print foo` from `printfoo`--spaces aren't used for much in most languages. However, in a couple of dark corners, a space _does_ affect how code is parsed in CoffeeScript, Ruby, and the C preprocessor. Where and what effect does it have in each of those languages?

- CoffeeScript
  - Uses significant whitespace to delimit blocks of code, like Python!
  - https://coffeescript.org/ under \#Language Reference

- Ruby
  - Ruby has two different operators concerning `*`. Given `args *10` and `args * 10`, the `*10` is the unary splat operator for converting arrays into multiple parameters and `* 10`  is an overridable binary operator for regular multiplication.
- https://stackoverflow.com/questions/50543569/is-ruby-whitespace-sensitive-in-certain-cases

- C preprocessor
  - When using the `#define` macro in C, the invocation `#define function_mac() something` is different than `#define function_mac () something`. The former being a regular function macro and the latter being an object macro defining `function_mac` as `() something`.
  - https://blog.robertelder.org/7-weird-old-things-about-the-c-preprocessor/

= Our scanner here, like most, discards comments and whitespace since those aren't needed by the parser. Why might you want to write a scanner that does _not_ discard those? What would it be useful for?

- In Rust, documentation is written in structured comments that includes Rust code in them itself. By parsing the comments through the scanner, you can do error checking on the Rust code example blocks. Additionally, you'd have a AST of the comments themselves, e.g what parameters there are, return type, etc for generating that documentation.

- For languages like CoffeeScript and Python, whitespace is used to delimit code blocks.
