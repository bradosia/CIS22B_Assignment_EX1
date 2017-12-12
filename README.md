De Anza College<BR>
Dr. Ira Oldham<BR>
Fall 2017<BR>
CIS 22B Intermediate Programming Methodologies in C++<BR>

# Instructions
Copy the solution from problem D2 and make the name OEC1. <BR>
Keep the same order of the functions as in problem D2. <BR>
We will keep the public interface to the StringOfCars. <BR>
We will change the implementation of the StringOfCars. <BR>
So keep all the public function prototypes in the StringOfCars. <BR>
Discard all the private data and the implementation of the member functions from the StringOfCars class; we will rebuild all of these.<BR>

Do not change anything outside the StringOfCars class.<BR>

In the StringOfCars class implementation:<BR>

Replace the private data with an STL vector of Car objects, and nothing else.<BR>

Change the default constructor so it does nothing.<BR>

Change the copy constructor so it uses the assignment operator to assign the old vector object to the vector object being constructed.<BR>

The destructor should do nothing.<BR>

Change the output function so it uses the vector size function and prints the Car objects from the vector.<BR>

Change the push function so it uses the vector push_back function to add a Car to the vector.<BR>

Change the pop function.<BR>
Use the vector back function to make a copy of the last Car object.<BR>
Use the vector pop_back function to remove the last Car object.<BR>
Put the Car object removed into the reference parameter.<BR>

Use the same tests as in problem D2.<BR>

# Outcome
Not Graded Yet