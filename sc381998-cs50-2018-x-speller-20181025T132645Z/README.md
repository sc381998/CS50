# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?


## According to its man page, what does `getrusage` do?

getrusage() returns resource usage measures.

## Per that same man page, how many members are in a variable of type `struct rusage`?

16 variables.

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

TODO

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

A for loop is a repetition control structure that allows you to efficiently write a loop that needs to execute a specific number of times. If it is false, the body of the loop does not execute and the flow of control jumps to the next statement just after the 'for' loop. After the body of the 'for' loop executes, the flow of control jumps back up to the increment statement. This statement allows you to update any loop control variables.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

TODO

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

TODO
