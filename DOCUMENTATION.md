# C++ Module 05 - Repetition and Exceptions

This module focuses on learning how to handle exceptions in C++, which is a crucial part of robust software development. It follows the story of a bureaucratic system with different levels of permissions and forms.

## Table of Contents
- [Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!](#exercise-00-mommy-when-i-grow-up-i-want-to-be-a-bureaucrat)
- [Exercise 01: Form up, maggots!](#exercise-01-form-up-maggots)
- [Exercise 02: No, you need form 28B, not 28C...](#exercise-02-no-you-need-form-28b-not-28c)
- [Exercise 03: At least this beat coffee-making](#exercise-03-at-least-this-beat-coffee-making)

---

## Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!
**Goal:** Introduction to custom exceptions.

### Key Concepts:
- **Bureaucrat Class:** Represents a person with a constant `name` and a `grade` ranging from 1 (highest) to 150 (lowest).
- **Exceptions:**
  - `GradeTooHighException`: Thrown if the grade is < 1.
  - `GradeTooLowException`: Thrown if the grade is > 150.
- **Functionality:** 
  - Ability to increment/decrement the grade (throwing exceptions if bounds are exceeded).
  - Overloaded `<<` operator to print bureaucrat status.

---

## Exercise 01: Form up, maggots!
**Goal:** Interaction between different classes and exceptions.

### Key Concepts:
- **Form Class:** Represents a document that needs to be signed.
- **Attributes:**
  - `name` (constant)
  - `isSigned` (boolean)
  - `gradeRequiredToSign` (constant)
  - `gradeRequiredToExecute` (constant)
- **Functionality:**
  - `beSigned(Bureaucrat&)`: Changes the status to signed if the bureaucrat's grade is high enough; otherwise, throws a `GradeTooLowException`.
  - `Bureaucrat::signForm(Form&)`: A wrapper that attempts to sign a form and prints a success or failure message.

---

## Exercise 02: No, you need form 28B, not 28C...
**Goal:** Abstract classes and concrete form types.

### Key Concepts:
- **AForm (Abstract Form):** The base class becomes abstract. It adds an `execute(Bureaucrat const & executor)` method.
- **Concrete Forms:**
  1. **ShrubberyCreationForm (Grades: Sign 145, Exec 137):** Creates a file `<target>_shrubbery` and writes ASCII trees to it.
  2. **RobotomyRequestForm (Grades: Sign 72, Exec 45):** Makes drilling noises and has a 50% chance of successfully "robotomizing" the target.
  3. **PresidentialPardonForm (Grades: Sign 25, Exec 5):** Announces that the target has been pardoned by Zaphod Beeblebrox.
- **Functionality:**
  - Forms can only be executed if they are signed and the executor's grade is high enough.
  - `Bureaucrat::executeForm(AForm const & form)`: Attempts to execute the form and provides feedback.

---

## Exercise 03: At least this beat coffee-making
**Goal:** Factory pattern implementation.

### Key Concepts:
- **Intern Class:** A class that creates forms without needing to know their specific types.
- **Functionality:**
  - `makeForm(std::string formName, std::string target)`: Takes a form name (e.g., "robotomy request") and a target, then returns a pointer to the correct form object.
  - Uses a lookup system (like an array of function pointers or a switch-like logic) to avoid long `if/else` chains.
  - If the form name doesn't exist, it prints an error message.

---

## Technical Requirements
- **C++ Standard:** C++98.
- **Canonical Form:** All classes must implement the Orthodox Canonical Class Form (Default constructor, Copy constructor, Copy assignment operator, Destructor).
- **Memory Management:** No memory leaks allowed.
- **Exception Handling:** All exceptions should be caught using `try/catch` blocks in the main tests.
