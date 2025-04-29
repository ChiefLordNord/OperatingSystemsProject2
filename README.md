# OperatingSystemsProject2
Bankers_Algorithm

In this programming assignment, you are required to provide the source codes, documents, and examples in detail on github. You only need to submit your GitHub project to me.  

Requirements:

    You are required to use C/C++ in Linux/Unix. You can consider installing virtualBox in your non-Linux environment.
    Programs must succeed in compilation and execution as required (80 points)
    Readme, documentation, and example are required (20 points).

Banker’s Algorithm for deadlock avoidance.

Considering a system with five processes P0 through P4 and three resources of type A, B, C. Resource type A has 10 instances, B has 5 instances and type C has 7 instances. 

Implement the Banker’s algorithm to answer the following question： Is the system in a safe state? If Yes, then what is the safe sequence?

What should be included in the submission:

    Source codes (C/C++)
    Input file (you should create an input file, e.g., .txt, with your customized format that stores the data that is provided in the table).  
    Your code should print out the safe sequence if the system is safe.
    Documents and readme.

---------------------------------------------------------------

Banker's Algorithm

The Banker's Algorithm is a resource allocation and deadlock avoidance algorithm used in operating systems. It ensures that a system remains in a safe state by carefully allocating resources to processes while avoiding deadlocks.

How It Works

The algorithm uses the following data structures:

    Available: The number of available instances of each resource type.
    Maximum: The maximum demand of each process for each resource type.
    Allocation: The number of resources currently allocated to each process.
    Need: The remaining resource need of each process

Compile

g++ -o Bankers_Alg Bankers_Alg.cpp

Execute

./Bankers_Alg