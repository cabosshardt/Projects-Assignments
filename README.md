# Projects-Assignments

This repository contains C++ programming projects and assignments completed during my coursework. These projects demonstrate my understanding of fundamental programming concepts including data structures, file I/O, dynamic memory management, and algorithm implementation.

## Projects

### Movie Database Organizer (movies-1.cpp)
**Course:** COP3014 0006 - Foundations of Computer Science  
**Assignment:** Homework 7

A command-line application that manages a movie database with the following features:

- **Dynamic Memory Management**: Uses dynamic arrays with proper memory allocation and deallocation
- **File I/O**: Reads movie data from text files and exports results to separate files
- **Data Structures**: Implements a custom `Movies` structure with multiple fields (genre, title, year, runtime, rating)
- **Sorting Algorithms**: Sorts movies by year using bubble sort algorithm
- **Data Filtering**: Filters and displays movies by rating category
- **Menu-Driven Interface**: Interactive command-line menu system

#### Features:
1. Load movie data from file
2. Calculate and display total database runtime
3. View movies filtered by rating (G, PG, PG-13, R)
4. Export movies by genre to separate text files
5. Clear currently loaded database
6. Sort and display movies by year

#### Test Data Files:
- `movies1.txt` - Sample dataset with 20 movies
- `movies2.txt` - Sample dataset with 15 movies

#### Technical Highlights:
- Demonstrates proper use of C++ Standard Library (iostream, fstream, string)
- Implements pass-by-reference for efficient data handling
- Uses pointers and dynamic memory allocation
- Includes input validation and error handling

## How to Compile and Run

```bash
# Compile the program
g++ -o movies movies-1.cpp

# Run the program
./movies
```

When prompted, enter the filename (e.g., `movies1.txt` or `movies2.txt`) to load the movie database.

## Skills Demonstrated

- C++ Programming
- Object-Oriented Programming Concepts
- Dynamic Memory Management
- File Input/Output Operations
- Algorithm Implementation (Sorting, Searching)
- Data Structure Design
- User Interface Design
- Problem Solving