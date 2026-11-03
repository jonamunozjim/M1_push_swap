*This project was created as part of the 42 curriculum by jmunoz-j and fejimene.*

<div align="right">
  <strong>Languages:</strong>
  <a href="README.md">English</a> ｜ 
  <a href="README_es.md">Español</a>
</div>

# Push_swap

## Description
Push_swap is an algorithms project from the 42 Common Core. The goal is to sort a stack of integers (`stack a`) using an auxiliary stack (`stack b`) and a very limited set of allowed operations. The true challenge of the project lies in optimization: it is not just about sorting the data, but doing so using the fewest possible moves, evaluating different levels of algorithmic complexity, and calculating the initial disorder index to apply the optimal strategy in each case.

## Compilation and Execution Instructions
The project includes a standard `Makefile`.

**To compile the project:**
```bash
make
```

**To execute the program:**
Pass a list of integers as arguments. The program will output the list of operations needed to sort them.
```bash
./push_swap 4 67 3 87 23
```

**Available Flags (Strategy Selector):**
-   `--simple`: Forces the $O(n^2)$ complexity algorithm.
-   `--medium`: Forces the $O(n\sqrt{n})$ complexity algorithm.
-   `--complex`: Forces the $O(n \log n)$ complexity algorithm.
-   `--adaptive`: (Default) Automatically selects the strategy based on the disorder index.
-   `--bench`: Displays sorting statistics via the standard error output (`stderr`).

## Bonus: Evaluator (Checker)
The project includes an additional program called `checker`, developed as part of the *bonus* section of the *subject*. Its function is to validate whether a sequence of operations correctly sorts the provided stack.

**To compile the bonus:**
```bash
make bonus
```

**To run the checker manually:**
```bash
./checker 4 67 3 87 23
```
*(The program will wait for instructions on the standard input. You can type commands like `sa`, `pb`, `ra`, pressing Enter after each one. To end the input, press `Ctrl+D`).*

**To automatically evaluate push_swap (using pipes):**
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

**Evaluation Results:**
The `checker` executes the moves in absolute silence. Once it finishes reading, it checks the state of the stacks and prints to the standard output:
-   `OK`: If *stack a* is perfectly sorted from lowest to highest and *stack b* is empty.
-   `KO`: If the stacks are not sorted correctly at the end.
-   `Error`: If an invalid instruction is introduced, or if the initial arguments contain errors (non-numeric, duplicates, beyond the `int` limit). This message is always sent to the standard error output (`stderr`).

## Algorithm Justification
To meet the complexity requirements, we have implemented the following strategies:

### 1. Simple Algorithm - $O(n^2)$
**Implemented in:** `ft_simple_sort.c` / `ft_sort_small.c`
It consists of sequentially finding the minimum number in `stack a`, rotating it to the top, and pushing it to `stack b`. Finally, everything is returned to `a`. This nested loop (finding the smallest by iterating over the remaining elements) represents the classic $O(n^2)$ complexity, ideal for cases with very few numbers.

### 2. Intermediate Algorithm - $O(n\sqrt{n})$
**Implemented in:** `ft_medium_sort.c`
**Justification:** We implemented an algorithm based on *Chunks*. The list is indexed, and the numbers are sent to stack B divided into small ranges or portions. This significantly reduces the amount of searching compared to the simple algorithm, bringing the mathematical performance closer to $O(n\sqrt{n})$ complexity.

### 3. Complex Algorithm - $O(n \log n)$
**Implemented in:** `ft_complex_sort.c`
**Algorithm:** Radix Sort (Base 2)
**Justification:** For the highest algorithmic complexity requirement, we implemented a Base-2 Radix Sort. Before starting, the stack is indexed (from $0$ to $N-1$) to normalize the values and avoid issues with negative numbers. The algorithm evaluates the binary representation of each index bit by bit. If the evaluated bit is $0$, the node is pushed to stack B (`pb`); if it is $1$, it is rotated in stack A (`ra`). Once all nodes for a specific bit are processed, everything is returned from B to A. This non-comparative and highly predictable approach guarantees a time complexity that fits the required $O(n \log n)$ model.

### 4. Adaptive Algorithm (Thresholds)
**Implemented in:** `main.c` (`ft_adaptive` function)
**Justification:** The program calculates the disorder index by evaluating how many pairs of numbers are in the wrong position. 
-   **Disorder < 0.2 (Low):** Falls back to simple algorithms ($O(n^2)$) since the stack is almost sorted and requires few corrections.
-   **0.2 <= Disorder < 0.5 (Medium):** Uses the Chunks algorithm ($O(n\sqrt{n})$).
-   **Disorder >= 0.5 (High):** Activates the Radix Sort ($O(n \log n)$) to ensure stability and performance against absolute chaos.

## Team Contributions
This project was developed collaboratively. **Although there was an initial division of tasks, the functionality of each function was later debugged and refined together.** The task distribution is detailed below:

-   **jmunoz-j:**
    *   Basic movement management and rotation optimization: `ft_swap.c`, `ft_push.c`.
    *   Algorithms for small and simple lists: `ft_sort_small.c`, `ft_simple_sort.c`.
    *   Input validation and robust parsing (error shielding): `ft_push_input_check.c`.
    *   Memory management, initialization, and linked list cleanup: `ft_init_free.c`, `ft_dlstclear.c`.
-   **fejimene:**
    *   Rotation and reverse rotation logic: `ft_rotate.c`, `ft_reverse_rotate.c`.
    *   Intermediate algorithm (Chunk Sort): `ft_medium_sort.c`.
    *   Complex algorithm (Radix Sort): `ft_complex_sort.c`.
    *   Calculation of the mathematical disorder index: `ft_disorder.c`.
    *   Implementation and logic of the metrics system (Benchmark): `ft_bench.c`.
-   **Joint Development (jmunoz-j & fejimene):**
    *   Main architecture, adaptive flows, and strategy selectors: `main.c`.
    *   Evaluator program and dynamic reading (Bonus): `checker.c`.
    *   Node population from the parser: `ft_fill_nodes.c`.
    *   Build configuration and project rules: `Makefile`.
    *   Definition of main structures, prototypes, and macros: `push_swap.h`, `checker.h`.

## Resources and Artificial Intelligence

-   **Classic Resources:** Consultations of articles on algorithmic complexity (Big-O Notation) and comparisons of sorting algorithms in linear data structures.

-   **Use of Artificial Intelligence:** AI assistance was used strictly as a tutoring, consultation, and debugging tool. No base code was generated blindly; instead, it was applied in the following key areas:

    *   **Algorithmic understanding:** To understand and assimilate the mathematical logic behind complex algorithms (such as *Radix Sort* and the *Chunk Sort*), as well as their direct impact on time complexity ($O(n \log n)$, $O(n\sqrt{n})$).

    *   **Memory management and security:** To visually track memory flow, prevent dangling pointers, and ensure the resolution of memory leaks in edge cases, such as parsing failures or read errors in the evaluator (`checker`).
    
    *   **Documentation:** Assistance in structuring and writing this `README.md` file to ensure that the presentation of our work meets all the requirements of the *subject* in a professional and clear manner.