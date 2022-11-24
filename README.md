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
        f: p -> q
        g: q -> r
        h: r -> s
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
