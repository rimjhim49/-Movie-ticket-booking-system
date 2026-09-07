🎬 Movie Ticket Booking System

A simple console-based Movie Ticket Booking System in C++ developed
as a System Design assignment.

📌 Features

View movies and shows

Display seat layout and availability

Book one or more seats

Prevent booking of already booked seats

Calculate price by seat type

Pay using UPI, Card or Cash

Generate and print ticket

Cancel booking and release seats

Handle invalid input and failed payments

💰 Seat Pricing

Seat Type     Price

Silver         ₹150
Gold           ₹250
Platinum       ₹400

🏗️ System Architecture

The main booking flow is:

Customer
   ↓
BookingService
   ↓
Movie → Show → Screen → Seat
              ↓
           ShowSeat
              ↓
       PriceCalculator
              ↓
           Payment
        ↙     ↓     ↘
      UPI    Card    Cash
              ↓
           Booking
              ↓
        TicketPrinter

BookingService coordinates the booking process, while individual
classes handle specific responsibilities such as seat management, price
calculation, payment, booking, and ticket printing.

📊 UML & Design Diagrams

The project includes several diagrams to explain the system design from
requirements to implementation.

1. Functional Requirements

Shows the main functions provided by the system, including:

Viewing movies

Selecting shows

Viewing seats

Booking tickets

Making payments

Printing tickets

Cancelling bookings

2. Non-Functional Requirements

Describes the quality requirements of the system, such as:

Modularity -- separate classes with clear responsibilities

Extensibility -- easy addition of new payment methods

Input Validation -- invalid inputs are handled safely

Maintainability -- meaningful names and organized
responsibilities

3. Noun--Verb Analysis

The noun--verb analysis is used to identify important classes
(nouns) and operations (verbs) from the problem statement.

For example:

Nouns → Movie, Show, Seat, Booking, Customer, Payment
Verbs → Book, Pay, Cancel, Calculate, Print

This helps decide what the classes represent and what responsibilities
they should have.

4. Class Diagram

The class diagram shows the overall structure of the system.

It contains:

Classes and their attributes

Methods and visibility

Multiplicities

Relationships between classes

Abstract Payment class

Payment inheritance hierarchy

Main relationships include:

Composition → Cinema–Screen, Screen–Seat, Show–ShowSeat
Aggregation → Show–Movie
Association → Booking–Customer, Booking–Payment
Inheritance → Payment → UPI/Card/Cash

The diagram gives a structural view of how the different objects are
connected.

5. Sequence Diagram

The sequence diagram shows the step-by-step interaction when a customer
books a seat and pays using UPI.

Customer
   ↓
BookingService
   ↓
Show / ShowSeat
   ↓
PriceCalculator
   ↓
Payment
   ↓
Booking
   ↓
TicketPrinter

It explains the order in which objects communicate during the booking
process, from seat selection to ticket generation.

6. Relationship Table

The relationship table identifies the important relationships between
classes and explains why each relationship is:

Composition

Aggregation

Association

Inheritance

The justification is based on the object lifetime / ownership test
where applicable.

7. SOLID Mapping

The SOLID diagram shows how design principles are applied to the
project.

Examples:

SRP: PriceCalculator only calculates prices.

OCP: New payment types can be added through the Payment
abstraction.

LSP: UPI, Card, and Cash payments can be used through Payment.

ISP: Payment-related operations are kept focused.

DIP: Booking logic can work with the Payment abstraction.

🧠 OOP Concepts Used

Encapsulation -- private data members with public methods

Abstraction -- abstract Payment class

Inheritance -- UPI, Card, and Cash derive from Payment

Runtime Polymorphism -- payment selected through the Payment
interface

Compile-Time Polymorphism -- constructor overloading

Static Members -- booking ID generation

this Keyword -- used to refer to the current object

Composition -- strong ownership relationships

Aggregation -- independent object relationships

Association -- objects interacting with each other

📂 Project Structure

Movie-Ticket-Booking/
├── main.cpp
├── movie.cpp
├── seat.cpp
├── screen.cpp
├── cinema.cpp
├── show.cpp
├── showSeat.cpp
├── customer.cpp
├── booking.cpp
├── payment.cpp
├── paymentType.cpp
├── PriceCalculator.cpp
├── ticketPrinter.cpp
├── bookingService.cpp
└── README.md

🎟️ Booking Flow

1. Select Movie
       ↓
2. Select Show
       ↓
3. Select Seat(s)
       ↓
4. Validate Seats
       ↓
5. Calculate Price
       ↓
6. Select Payment
       ↓
7. Make Payment
       ↓
8. Confirm Booking
       ↓
9. Print Ticket

⚠️ Edge Cases

Already Booked Seat

Seat is already BOOKED.
Booking rejected.

Invalid Seat

Invalid seat.
Please enter a valid seat number.

Failed Payment

Payment failed.
Selected seats are released.

Cancellation

Booking cancelled successfully.
Seats are AVAILABLE again.

⚙️ How to Run

Prerequisites

C++ compiler

GCC / MinGW

C++17 or later

Compile

g++ -std=c++17 main.cpp -o moviebooking

Run on Windows

.\moviebooking.exe

Run on Linux/macOS

./moviebooking

Note: The project uses .cpp files according to its current
file-inclusion structure rather than a traditional .h/.cpp header
structure.

🚫 Deliberately Not Implemented

A database / persistent storage system is not included.

The project is intentionally scoped as a small, single-cinema console
application focused on:

Movies
Shows
Seats
Booking
Payment
Ticket Printing
Cancellation

🎯 Learning Outcomes

This project demonstrates practical understanding of:

System Design

Requirement Analysis

UML

Object-Oriented Programming

SOLID Principles

C++ Modular Design

Class Relationships

Booking and Payment Flow

Input Validation

👨‍💻 Author

Rimjhim Kumari

B.Tech CSE -- Semester 5

System Design Assignment -- 1
