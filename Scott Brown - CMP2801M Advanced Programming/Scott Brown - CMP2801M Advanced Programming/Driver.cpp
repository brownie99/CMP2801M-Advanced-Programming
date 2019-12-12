/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment 
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file. 
During marking, we will use the exact same notation 
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't 
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK! 

------------------------------------------------------ */

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"
#include "Error.h"

#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands


	while (userCommand.compare("exit") != 0) 
	{
		cout << "Enter the command: ";
		
		getline(cin, userCommand);

		char * cstr = new char[userCommand.length() + 1];
		
		strcpy_s(cstr, userCommand.length()+1, userCommand.c_str());
		
		// implement a string tokenizer to populate the parameters vector 
		// check function strtok_s
		char * nextToken;
		char * token = strtok_s(cstr, " ", &nextToken);
		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok_s(NULL, " ", &nextToken);
		}

		// as a result of the process, parameters[0] should hold your command, followed by your parameters 
		string command = parameters[0];


		// in the following code, consider checking for the arguments.
		// in case of too few arguments, you may remind the user the correct format
		try
		{
			if (command.compare("addR") == 0) {
				if (parameters.size() == 5)
				{
					// get parameters in the correct order
					// The following four lines have a type mismatch error
					// note that the the parameters vector contains ascii values
					// HINT: stoi function converts from string to int
					int x = stoi(parameters[1].c_str()); // fix me! also note that x is not previously defined :(
					int y = stoi(parameters[2].c_str());
					if (stoi(parameters[3].c_str()) <= 0 || stoi(parameters[4].c_str()) <= 0)
						throw errorClass("Invalid Radius");
					int h = stoi(parameters[3].c_str());
					int w = stoi(parameters[4].c_str());


					Rectangle* r = new Rectangle(x, y, h, w);
					shapes.push_back(r);
					cout << r; /* instead of this, you may implement operator overloadig and
											use cout << r which will give you additional points */
				}
				else
				{
					throw errorClass("Incorrect Number of Parameters");
				}
			}
			else if (command.compare("addS") == 0) {
				if (parameters.size() == 4)
				{
					// get parameters
					int x = stoi(parameters[1].c_str()); // fix me! also note that x is not previously defined :(
					int y = stoi(parameters[2].c_str());
					if (stoi(parameters[3].c_str()) <= 0)
						throw errorClass("Invalid Edge Size");
					int e = stoi(parameters[3].c_str());
					// ...
					Square* s = new Square(x, y, e);
					shapes.push_back(s);
					cout << s;
				}
				else
				{
					throw errorClass("Incorrect Number of Parameters");
				}
			}

			else if (command.compare("addC") == 0) {
				// get parameters
				if (parameters.size() == 4)
				{
					int x = stoi(parameters[1].c_str()); // fix me! also note that x is not previously defined :(
					int y = stoi(parameters[2].c_str());
					if (stoi(parameters[3].c_str()) <= 0)
						throw errorClass("Invalid Radius");
					int r = stoi(parameters[3].c_str());
					// ...
					Circle* c = new Circle(x, y, r);
					shapes.push_back(c);
					cout << c;
				}
				else
				{
					throw errorClass("Incorrect Number of Parameters");
				}
			}
			else if (command.compare("scale") == 0) {
				// scale object at index... the scaling needs to be isotropic in case of circle and square 
				// you may want to check if the index exists or not!

				// Multiple inhertitance is tricky! The Shape class does nto have a scale function, the Movable does!
				// As a result all your derived classes have scale functions... 
				// You may need to use type casting wisely to use polymorphic functionality!

				int pos = stoi(parameters[1].c_str() - 1);

				int xScale = stoi(parameters[2].c_str());
				int yScale = stoi(parameters[3].c_str());

				if (pos < shapes.size() - 1 && pos >= 0)
				{
					dynamic_cast<Movable*>(shapes[pos])->scale(xScale, yScale);
				}
				else
				{
					throw errorClass("Invalid Shape Position");
				}

				/*if (typeid(shapes[pos]).name == "Circle")
				{
					dynamic_cast<Circle*>(shapes[pos])->scale(xScale, yScale);
				}
				else if (typeid(shapes[pos]).name == "Square")
				{
					dynamic_cast<Square*>(shapes[pos])->scale(xScale, yScale);
				}
				else if (typeid(shapes[pos]).name == "Rectangle")
				{
					dynamic_cast<Rectangle*>(shapes[pos])->scale(xScale, yScale);
				}*/
			}
			else if (command.compare("move") == 0) {
				// move object at index 
				int shapeNo = stoi(parameters[1].c_str()); // read from parameters
				int x = stoi(parameters[2].c_str());
				int y = stoi(parameters[3].c_str());
				// you may want to check if the index exists or not!

				if (shapeNo <= shapes.size() && shapeNo >= 0)
				{
					// Study the following code. A Shape object is not Movable, but all derived classes are...
					// you can't automatically type cast from a Shape to a Movable, but you can force a downcasting
					Movable *m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);
					m->move(x, y);
					// scale should work similarly...

					// note that here you should see the corresponding toString output for the derived classes...
					// if toString is not a virtual function, you may see the base class functionality :(
					cout << shapes[shapeNo - 1]->toString();
				}
				else
				{
					throw errorClass("Invalid Shape Position");
				}
			}
			else if (command.compare("display") == 0) {
				// this is not given in our example, but why don't you implement a display function which shows all objects stored in shapes?
				std::vector<Shape*>::iterator ptr;
				for (ptr = shapes.begin(); ptr < shapes.end(); ptr++)
				{
					cout << (*ptr)->toString() << std::endl;
				}
			}
			// do any necessary postprocessing at the end of each loop...
			// yes, there is some necessary postprocessing...
			cout << endl << endl;
			if (command != "exit")
			{
				userCommand.clear();
				command.clear();
				parameters.clear();
			}
		}
		catch (errorClass e)
		{
			cout << e.getErrMsg() << std::endl;
			userCommand.clear();
			command.clear();
			parameters.clear();
		}
		
	}

	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}
