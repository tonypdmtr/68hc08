**My Own Assembly Language Coding Conventions**

The following are general naming conventions which older code may not yet follow precisely.

* Tabs are never used.
* End of line spaces are remove (automatically by the editor or a separate utility as required).
* End-of-line is Linux style (LF) even under Windows.
* Label begin in column 1.
* Instructions and non-conditional directives begin in column 21.
* Conditional directives outside a code block begin in column 1.
* Conditional directives inside a code block begin in column 11.
* Each nested conditional directive is indented by 2 spaces.
* Instruction opcodes begin in column 21.
* Instruction operands begin in column 31.
* End of line comments begin in column 51 unless a long operand pushes them further to the right, in which case at lease one space separates the comment from the operand.
* All comments begin with semi-colon.
* Stand-alone comments begin in column 1.
* In-line proc comments begin in column 11 or follow a dotted line (`;---`) that begins in column 11 and runs to column 78, leaving column 79 blank, then a semi-colon in column 80 followed by the comment text.
* Dot-ending names (`XXX.`) indicate a unique bit by position number (0 thru 7).
* Underscore-ending names (`XXX_`) indicate a bit mask (possibly including multiple bits).
* Underscore surrounded names (`_XXX_`) indicate special system symbols such as `CCR` offsets, etc.
* All constants are uppercase and use underscores to separate words as needed (`MY_CONSTANT`).
* All variables are lowercase and use underscores to separate words as needed (e.g., `my_var`).
* All pointer variables begin with a point/dot (`.xxx`).
* Code labels use `CamelCase`.
* File-local labels begin with `?` (a question mark).  This is an ASM8 requirement.
* Proc-local labels end with `@@` (although ASM8 allows `@@` to be anywhere inside the label).
* Macro-local labels end with `$$$` (although ASM8 allows `$$$` to be anywhere inside the label).
* Subroutines always begin a `proc` pseudo-op to mark the beginning of the subroutine.  This allows proc-local symbols to be used inside the subroutine without worrying about name collisions with other subroutine symbols.
* Subroutines normally use `#spauto` mode with optional `:ab` offset when the proc may reference caller-level stack variables.
* Local (stack) variables defined near the beginning of the subroutine either directly (with `AIS #-nn`) or with the use of the `local` macro which follow an `#AIS` directive.  These variables are de-allocated using the `AIS #:AIS` instruction.
* Each subroutine is separated from the previous one with an 80-column semi-colon beginning comment line full of asterisks (i.e., `;***...`).
* File-local subroutines begin with `?` as required by ASM8 to keep local to that file.
* File-local subroutines end with an `RTS` instruction.  They are called with either `JSR` or `BSR` instructions.
* Global subroutines end with an `RTC` instruction.  They are called with `CALL` instructions.
* Very small and clear purpose subroutines usually have no spaces between instructions.
* Regular subroutines separate each block of related assembly language instructions with a single blank line, or a dotted comment line (see earlier).
* Segments are used to separate object code into distinct areas.  Segment `#RAM` is used for zero-page RAM variables that may need `B[R]SET` or `B[R]CLR` instruction access. Segment `#XRAM` is used for all other variables.
* File inclusion is done with the `#Uses` directive.  `#Include` is only used when the same file must be included more than once (where `#Uses` would fail), or when we need to be sure the inclusion point is at the `#Include` directive.
* All file inclusion paths are relative and depend on the assembler's default include path search.
* Ad-hoc `?` macros are used to simplify repeated sequential coding of complicated expressions or coding patterns.
