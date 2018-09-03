# Simple Lexical Analyzer Using Flex
A simple lexical analyzer built using Flex, following the tutorial on https://www.youtube.com/watch?v=54bo1qaHAfk&amp;t=517s

The lexical analyzer will tokenize the config.in file into tokens and myscanner.c will read the file and perform a basic syntax analysis with error handling.

### How to run
Generate the lexical analyzer using lex <br>
<code>
lex myscanner.l
</code>

Complie the program <br>
<code>
gcc myscanner.c lex.yy.c -o myscanner
</code>

To test, you can provide input using stdin <br>
<code>
./myscanner < config.in
</code>

## Credits
The source code is implemented based on https://www.youtube.com/watch?v=54bo1qaHAfk&t=517s
