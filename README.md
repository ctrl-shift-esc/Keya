Keya
====

This is an esoteric programming language I'm working on. This language is based on Brainfuck. I have tried to keep the commands as simplistic as possible. Some commands have been preserved from Brainfuck.

Layout
====

The momry in Keya is seen as a `N * N` grid of `chars`. The value of `N` can be changed in the source code of the interpreter. Initially the grid is initialized to `0` and the pointer points to the first cell. This looks something like this:

` ptr                                         `
`  ^                                          `
`---------------------------------------------`
`|        |           |           |          |`
`|        |           |           |          |`
`|        |           |           |          |`
`|        |           |           |          |`
`---------------------------------------------`
`|        |           |           |          |`
`|        |           |           |          |`
`|        |           |           |          |`
`|        |           |           |          |`
`---------------------------------------------`
`|        |           |           |          |`
`|        |           |           |          |`
`|        |           |           |          |`
`|        |           |           |          |`
`---------------------------------------------`
`|        |           |           |          |`
`|        |           |           |          |`
`|        |           |           |          |`
`|        |           |           |          |`
`---------------------------------------------`

Commands
====

Movement
----

`8` : Move one row up 
`2` : Move one row down 
`4` : Move one cell to the left
`6` : Move one cell to the right

Input/Output
----
`.` : Output the data at pointer
`,` : Input data at pointer

Data Manipulation
----
`+` : Increment byte at the pointer
`-` : Decrement byte at the pointer

`>` : Copy data and paste it to one cell right of pointer
`<` : Copy data and paste it to one cell left of pointer
`^` : Copy data and paste it to one row above of pointer
`_` : Copy data and paste it to one row below of pointer

Additional Commands
----
`[` : if the byte at the pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.
`]` : if the byte at the pointer is nonzero, then instead of moving the instruction pointer forward to the next command, jump it back to the command after the matching [ command.

Note: The above two commands are similar to the ones from Brainfuck.

Known Bugs
====
1. Nested loops are not working