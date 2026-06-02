*This project has been created as part of the 42 curriculum by vmeharia.*

##Description
The goal of this project is to program a C function, get_next_line, which reads text from a given file descriptor and returns it one line at a time. This function handles repeated calls dynamically, allowing sequential reading of an entire text file until the end of the file is reached or an error occurs.  

###Algorithm Explanation & Justification
To fulfill the requirements efficiently while strictly staying within the 25-line function limit imposed by the Norm, the project uses a modular, three-part algorithm engineered around a static variable:  

The Accumulator (read_and_stash): This phase handles the low-level data fetching. It reads data from the file descriptor in blocks defined by BUFFER_SIZE and dynamically appends them into a static buffer (the "stash"). The loop terminates as soon as a newline character is detected within the stash or if the end of the file is reached.  

The Harvester (extract_line): Once the reading loop stops, this helper scans the accumulated stash from the beginning up to and including the first newline character. It allocates a clean string using malloc, copies the exact line content, caps it properly with a null-terminator, and prepares it to be returned to the user.  

The Scrubber (clean_stash): Because the read buffer can inadvertently grab extra characters belonging to the subsequent line, this phase cleans up the static stash. It discards the line that was just harvested and reallocates the remaining leftover text back into the static pointer, preserving it safely for the next call.  

Justification: Utilizing a static pointer is essential because standard local variables lose their data once a function terminates. The static variable bridges subsequent calls to get_next_line, keeping track of leftover text without resorting to forbidden global variables. Breaking the process into separate logical units guarantees structural clarity, safe memory lifecycle tracking to eliminate leaks, and full compliance with the strict line limits.  

##Instructions
###Compilation
The code must be compiled with the standard compiler flags (-Wall -Wextra -Werror) along with an external macro definition flag (-D BUFFER_SIZE=n) to specify the buffer size for the internal read operations.  Compilation is executed at the root of the repository by invoking the compiler with the flags for Wall, Wextra, and Werror, passing the macro flag accompanied by the chosen numerical buffer value, followed by the target C source files. For example, compiling with a buffer size of 42 requires passing the -D flag set to 42 alongside get_next_line.c and get_next_line_utils.c.  The project must compile successfully both with and without the external buffer size flag explicitly declared during invocation. If omitted, the code utilizes a fallback default value defined inside the header file.  ExecutionTo use the function in an external program, the header file get_next_line.h must be included at the top of the C source file. The function is then called within a loop, passing a valid, open file descriptor—or 0 for standard input—as the primary argument. The loop sequentially captures each line until the function returns NULL, signaling that the end of the file has been reached or an error was encountered.  

##Resources
###Documentation & References
Input/Output Operations: System call documentation for read (man 2 read).  
Memory Management: Dynamic allocation and deallocation manuals for malloc and free (man 3 malloc, man 3 free).  
C Semantics: Storage class specifiers and the behavior of variables initialized in the BSS segment (Static Variables).  

AI Disclosure & Usage Tracking
In accordance with the 42 AI learning guidelines, artificial intelligence was utilized strictly as a conceptual and architectural guide during development to avoid shortcuts and anchor real technical foundations.  Tasks Handled by AI: AI tools were leveraged to clarify memory mechanics regarding the segment where static variables live, to troubleshoot tracking ownership of pointers during multiple reallocations to prevent dynamic leaks, and to establish the architectural division of the helper functions to comply with the 25-line limit.  Parts of the Project Affected: The logical design layout of the management engine in get_next_line.c and the structural mapping within this documentation file. No direct code generation or copy-pasting shortcuts were utilized, preserving the baseline reasoning, engineering constraints, and mandatory defense readiness. 
