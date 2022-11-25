# myscript
My own scripting language. I'll think of a name later.

## Concepts

- Pipelines
    - Functions that operate on formatted input/output
        ```
        f | g | h
        ```
    - Parameters modify behavior
        ```
        f(a, b) | g(c) | h(d)
        ```
    - Pipeline input/output types are enforced
        ```
        f: _ -> s
        g: s -> t
        h: t -> _
        ```
    - Technically synctatic sugar for
        ```
        h(g(f(a, b), c), d)
        ```

- Expressions
    - Expressions return values, e.g.
        - Function calls
        - Arithmetic expressions
        - Variable names
    - Operators
        - Addition `+`
        - Subtraction `-`
        - Multiplication `*`
        - Division `/`
        - Modulo `%`
        - Logical and `&&`
        - Logical or `||`
        - Logical not `!`
        - Bitwise and `&`
        - Bitwise or `|`
        - Bitwise complement `~`
        - Pipe operator `|`
            - `f | g` is a pipe operator if `f: _ -> t` and `g: t -> _`
            - `f | g` is a bitwise or if `f: _ -> int` and `g: _ -> int` where
              `int` is an integral type

- Function declaration
    ```
    function_name: type_in -> type_out
    (parameter_a, parameter_b, parameter_c)
        expression;
        expression;
        ...
        return_expression
    ```

- Data types
    - Integer
        - Literal notation:
            ```
            19
            ```
    - String
        - Literal notation:
            ```
            "Plum"
            ```
    - Randomly accessible list
        - Accessible by index
        - Growable
        - Literal notation:
            ```
            [1, 2, 3, 4]
            ```
    - Parameter list
        - Accessible by name
        - Fixed size
        - Literal notation:
            ```
            (1, 2, 3)
            (a=1, b=2, c=3)
            ```
    - Map
        - Accessible by hashable key
        - Growable
        - Literal notation:
            ```
            {"Plum": 1, "Mango": 2, "Grape": 3}
            ```
