# Polygon Project

This project consist of a polygon calculator. You have some commands you can use to define polygons and operate with them, for instance, compute the area of the polygon, compute the intersection of two polygons, draw a set of polygons, etc.

The commands introduced, followed by its function and the specifications of its use are all listed in https://github.com/jordi-petit/ap2-poligons-2019. I have also introduced three complementary commands which are explained in the [Commands](#Commands) section.

In order to use the provided code it is necessary to first installate the library [pngwriter](https://github.com/pngwriter/pngwriter), the way it is explained in https://github.com/jordi-petit/ap2-imatges. If you have already installed the library in antoher path (i.e. not the way explained in jordi's github) then you can go to the [Paths](#Paths) section to see how to change the paths so that everything works.


# Structure

You will download a directory. This directory is the interface of the project and you are supposed to compile the makefile there. If you want to change that go to the [Paths](#Paths) section. This directory contains the makefile, this Readme, and four other directories: Files, Images, Code and Tests.

* **Files** is the directory where the files are created when doing save and where the files that are going to be read must be. That is, if you want to use the load command to read a file, that file must be there.

* **Images** is the directory where all the images you create with the draw or fulldraw commands are going to be stored.

* **Tests** is the directory where all the test cases are stored: for more information go to the [Tests](#Test) section.

* **Code** contains all the code of the project. It has the main.cc and three directories, Point, Polygon and commads (two classes and a header). Each one of those directories contains the specification .hh document and their implementation (which in some cases is distributed in more than one .cc file).

This structure has been thought to make things easier for the user and have everything in place. If for any reason you want to change the paths of the project (you want the pictures to go somwhere else, read files from somwhere else, compile the makefile from other directories, etc) go to [Paths](#Paths) section, where it is explained how to implement those changes.
   
# Commands

Aside from all the commands that our calculator has by default, that is, the ones explained in the description of this assignment, I implemented three more commands:

### The `fulldraw` command
The `fulldraw` command works exactly as the `draw` command, the only difference is that the polygons that are drawn are completely filled. To use it you must put the name of the command, the name of the file where you want to store the images and a set of polygons that are to be drawn.

### The `regular` command
The `regular` command reads a polygon and prints `yes` if the polygon is regular and `no` otherwise.

### The `in` command
The `in` command reads a polygon and a point and prints `yes` if the point is inside the polygon and `no` otherwise.

 
# Possible errors

The list of the errors that can appear and their meaning follows:

* **Unrecognized command** You have introduced a command which does not exist.

* **Invalid identifier** You have introduced the name of a polygon that does not exist.

* **Invalid declaration** You have introduced a line that does not match the specifications of the command, this error includes: giving an odd number of coordinates when declaring a polygon, giving more polygons than required, introducing strings when you should put doubles and introducing invalid numbers for the `setcol` commands (negative numbers or numbers greater than 1).

* **Lacking vertices** You are trying to use a command that requires an amount of vertices your polygon does not have, for instance computing the area of a point or the centroid of an empty polygon.

* **Missing parameters** You have not given enough parameters for the command, for instance, you are trying to do the intersection of just a polygon.

* **Document not found** You have tried to load a document that does not exist.

# Personal choices

* Though it might complicate the makefile, I decided to introduce subdirectories to have it all in place and make it understandable for the user, as explained before.

* Relate it with the previous point, I decided to avoid using the typical notation when doing the subdirectories, i.e. I decided not to do a directory named include with all the .hh, another one named source with the implementations and so on. Mainly because there are headers whose implementation is distributed in more than one file, and by separating the specification from the implementation it makes it harder to understand what each file is doing. So I think that it is easier for the user to understand the purpose of each program if all the .cc files that contain the implementation of the header are in a directory toghether with the specification of the header.

* I decided that polygons will only have an atribute, a vector of points. I have decided to implement it this way and not adding a string representing its id or a struct representing its color for many reasons: Firstly beacuse I want it to be a versatile class, that can be used in any other context with polygons, even if you don't work with colors or identifiers and,  the color of a polygon and/or its identifier are not intrinsic properties of a polygon, i.e. a polgyon could have no color, but must always have some points. Also, they don't need to be used in any method of the class, at least the way I implemented, so I don't think that is useful to assign the colors and id of the polygon in the same class.

* I decided that it wasn't necessary to create a struct or even a class for the colors, instead I just store them in a vector of three doubles. This choice has been made because I think that the colors are something complementary, hence, there is no reason to store them in a more sofisticated way. Furthermore, the way to acces the colors wouldn't practically change if they were stored in a struct. So the decision to design a class of store them in a struct would be, in my opinion, for elegance, but not really to ease the implementation of the project neither to make it more clear. 

* To store the polygons I decided to use a map from strings to polygons, such that to a polygon name it assigns its correspondent polygon. Similarly I decided to store the colors of the polygons using a map from string to vector of doubles. 

* I have decided that when redeclarating a polygon the color will not be changed again to black.

* I have decided that the area of a polygon with less than three points is meaningless (it will not be 0, it will print an error message if you try to calulate it), the same happens when computing the perimeter of polygons with less than two points, when computing the centroid of an empty polygon and when seeing if a polgyon with less than three vertices is regular.

* I decided to work with the infinity of c++ to avoid problems with vertical lines. Similarly at the Point.hh there is a constant named epsilon which is set to 1e-12. This constant is used when comparing doubles to avoid numerical problems. This means that points that differ by less than epsilon are consider equal, similarly, lines whose slope differs by less than epsilon are considered to be parallel. To change this tolerance, change the constant epsilon in the Point.hh (7th line).

* In order to draw a set of polygons, at least one of them needs to have more than a vertex, if not it prints error. Points are drawn as pixels and empty polygons are not drawn but give no error, similarly at least one of the polygons has to be not empty when using the bbox command.

* If more arguments than required are given, the program will not do the method called, instead it will print an error (i.e. it won't just omit the parameters that shouldn't have been given), as explained before.


# Details

* All the implemented functions are at most O(nlogn), which is the upperbound complexity for this project since the convexhull itself is already O(nlogn). In fact, the ConvexHull is the only method that is O(nlogn), any other method that is O(nlogn) is because it uses the ConvexHull method.

* Cases with empty polygons or points or lines have been properly considered, as well as aligned points, repeated ones, verticle lines and parallel ones.

* Due to the fact that we only print three decimal positions, when declaring a polygon whose points differ by less than 0.0005 but more than epsilon, when printing it, it seems that we are repeating points, but this is not true, since the points are different, if we increment the precission we will see the difference. This can be seen in test case 3, and it clearly shows that points that differ by less than epsilon won't be repeated since they are equal.

# Tests
There is a directory named tests that contains test cases. When you open it you will see that there are 6 directories more, each of them contains a test case. In each one you will find two directories named input and output. 

In the input directory there are two types of files, the input_terminal.txt which has the commads that must be put in the terminal, and other files, which are the ones that will be load in that particular test. **Important:** If you want to use this tests, you must copy those files in the directory named files (since all the files that have to be loaded must always be there). 

In the output directory there is everything that is outputed by the program, that is, files and images, also, there is a file named terminal_output.txt, which is the output that the program produces in the terminal. Each test case has been done to see if some specific things work. In particular:

* **Test 1** Is just a weak test to see if all functions do what they are supposed to do in non degenerate cases and with few points.

* **Test 2** This test case is done to see if parallel lines and vertical lines are well treated. Intersections of segments including one each other, vertical lines with horizontal ones and similar cases are treated here.

* **Test 3** In this test case we see that the calculator has no problem with polygons with very few points, that is, empty polygons, points and lines are well managed by the program. That is, the `union`, `intersection`, `inside` and other commands that could lead to errors when working with few points do their task.

* **Test 4** This case consists of mostly invalid commands. Its objective is to see if the program can detect properly any possible error that the user can introduce in the terminal.

* **Test 5** This case contains two cases, one named O(n^2) which is designed so that a program that has complexity O(n^2) can run quickly (couple of seconds at most). The other is named O(nlogn) which is designed so that a program that has complexity O(nlogn) can run within a couple of seconds (A program that has a method O(n^2) will take about 15 minutes to run). Both tests are also done to see if intersections of segments that are almost parallel and really small are well computed, as well as to check that everything works fine even with high amounts of vertices. 

* **Test 6** This case is designed to test the functions that I decided to introduced. That is, the `fulldraw`, the `in` and the `regular` commands.

# Paths

In this section we will see how to change some paths in case you don't like how the project is distributed.

* **Change pngwritter path** If you have not installed the pngwritter library as it is explained in jordi's github, you have to change the **$(HOME)/libs** in the lines 2 and 8 of the makefile for the path where you have stored the library.

* **Change files path** If you want to change where the files are stored you must go to ./Code/commands/files.cc and in line 20 change the "Files/" by the path you prefer. Also remember that if you remove the "Files/" then the files will be stored in the principal directory. To change where the files are read from, change the line 46 just as explained before.

* **Change images paths** If you want to change where the images are stored you have to go to ./Code/commands/pictures.cc and change the line 31, by substituting the "Images/" by the path you prefer.

* **Change the structure of the project** Any other changes about directories require to change the path in the makefile. First, in line 2 of the makefile you should introduce the directories where everything is stored. Also, when making reference to the document whose directory has been changed, don't forget to put the new path. It is very intuitive just seeing how the makefile is implemented (since, I introduced all the paths to make it easier to understand).

