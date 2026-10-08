# DynamicArray

A C++ dynamic array library built from scratch, designed to explore how a fixed-size array can evolve into a more flexible and reusable array abstraction.

> **Development status:** Under development  
> **Current version:** `v1.5.3`  
> **Production status:** Not production-ready yet

## Overview

DynamicArray is a personal C++ library for experimenting with dynamic storage, array manipulation, and the design of a higher-level array abstraction over manually managed memory.

The library separates the idea of **logical length** from **allocated capacity**, allowing an array to grow beyond its initial size while exposing operations such as insertion, deletion, searching, replacement, merging, and resizing.

The long-term goal is to evolve DynamicArray into a more complete and flexible C++ array library while keeping the implementation understandable and grounded in the underlying data-structure mechanics.

## Why I Built It

DynamicArray started while I was studying **Data Structures** and had just learned about arrays.

Because I had already worked with Python, I became curious about a simple question:

> What if I could take the fixed-size array I was learning in C++ and push it toward the flexibility of the dynamic sequences I was used to in Python?

That question turned into a personal implementation experiment.

A colleague encouraged me to continue with the idea, and I spent several weeks iterating on it: designing operations, changing the internal behavior, breaking things, fixing them, and gradually turning the original experiment into a small C++ array library.

The work eventually reached **version 1.5.3**. Development was then paused so I could return to C++ and Data Structures with a stronger foundation before continuing the library further.

This repository preserves that stage of the library's development while keeping the door open for substantial future improvements.

## What the Library Explores

DynamicArray currently explores:

- Dynamic storage backed by manually allocated memory
- Separation between logical length and allocated capacity
- Array growth and resizing
- Insertion and deletion operations
- Searching and replacement
- Merging arrays
- Filling and displaying array contents
- Internal shifting of elements
- Basic array state checks such as empty/full detection

## Current API Surface

The `v1.5.3` implementation contains the following implemented operations and concepts:

| Operation | Purpose |
| --- | --- |
| `Array(int newSize = 5)` | Create an array with an initial capacity |
| `getlength()` | Read the current logical length |
| `getSize()` | Read the current allocated capacity |
| `fill()` | Fill the array from standard input |
| `display()` | Display elements using range and step parameters |
| `Delete()` | Remove elements from the array |
| `push()` | Add an element at the end |
| `shift()` | Shift elements to make room for insertion |
| `reverseShift()` | Shift elements left after deletion |
| `enLarge()` | Resize the allocated storage |
| `replace()` | Replace an element at an index |
| `search()` | Search for an element and return its index |
| `insert()` | Insert an element at a requested index |
| `merge()` | Merge another `Array` into the current one |
| `isEmpty()` | Check whether the logical length is zero |
| `isFull()` | Check whether the logical length reaches capacity |

The public header also contains planned or still-evolving operations such as `append()`, `sort()`, and `pop()`. These are part of the library's ongoing development rather than a claim of a finished API.

## Design Direction

At its core, DynamicArray is built around two important pieces of state:

- **Capacity** — the amount of storage currently allocated.
- **Logical length** — the number of elements currently considered part of the array.

The implementation currently uses a raw dynamically allocated `int` buffer and exposes array operations through a custom `Array` class.

The library is intentionally evolving. Future versions are expected to improve the internal invariants, memory ownership model, copy semantics, resizing behavior, API consistency, validation, and test coverage.

## Current State and Limitations

`v1.5.3` should be considered a **development snapshot**, not a production release.

The repository currently has no mature automated test suite, and some public API members are still unfinished or evolving. Memory ownership, copy behavior, bounds handling, resizing strategy, and API completeness are areas planned for future work.

This is intentional: the repository records the state reached during an earlier development stage while providing a foundation for future iterations.

## Building the Library

The current repository contains a Visual Studio C++ project.

### Requirements

- Visual Studio with C++ development tools
- A C++ compiler supported by the Visual Studio project

### Build

1. Clone the repository.
2. Open `ArrayLibrary.slnx` in Visual Studio.
3. Build the solution.
4. Use `main.cpp` as the current development/demo entry point.

DynamicArray is currently distributed as source code rather than as a packaged library or package-manager release.

## Repository Structure

```text
DynamicArray/
├── ArrayLibrary.h              # Public Array class interface
├── ArrayLibrary.cpp            # Array implementation
├── main.cpp                    # Development/demo entry point
├── ArrayLibrary.slnx           # Visual Studio solution
├── ArrayLibrary.vcxproj        # Visual Studio C++ project
├── ArrayLibrary.vcxproj.filters
└── .gitignore
```

## Version History

The repository contains the earlier development history of the library as well as the restored `v1.5.3` development state.

The `v1.5.3` tag marks the version that was reached before development was temporarily paused.

Future releases will continue from this point rather than treating `v1.5.3` as a final design.

## Roadmap

The library is expected to evolve substantially. Planned directions include:

- Completing and stabilizing the public API
- Improving memory ownership and copy semantics
- Strengthening bounds checks and internal invariants
- Improving resizing and growth behavior
- Adding automated tests
- Improving documentation and examples
- Cleaning up naming and API consistency
- Packaging the library for easier reuse
- Expanding the data-structure capabilities while keeping the implementation understandable

## Philosophy

DynamicArray is driven by a simple idea:

> **Understand the abstraction by building it from the underlying mechanics.**

The library is not intended to hide the data structure completely. Its purpose is also educational and exploratory: to understand what a dynamic array needs to manage, what guarantees it should provide, and how a reusable abstraction can grow from a simple manually managed buffer.

## Author

**Ahmed Sayed**  
Frontend Engineer interested in browser engineering, web performance, systems, data structures, and building software from first principles.
