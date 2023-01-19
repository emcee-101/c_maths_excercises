// Niklas Herzog
// 19.01.2023
// "Implement a Text search using the algorithm of Broyer, Moore and Horspool."


#include <iostream>
#include <string>




int main() {

	std::string myString = "Eine Nadel im Heuhaufen finden";
	std::string stringToFind = "finden";

	int lengthBig = myString.length();
	int lengthSmall = stringToFind.length();

	bool running = true;
	int position = 1;

	while (running) {

		// check every character
		for (int i = 0; i < lengthSmall; i++) {

		
			std::cout << "checked out " << stringToFind[lengthSmall-1 - i] << " vs " << myString[position + (lengthSmall - i) - 2] << "\n";

		

			if (myString[position + (lengthSmall - i) -2] == stringToFind[lengthSmall-1 - i]) {

				// run this if the full phrase is found - when the loop ran without a "break" (the index of the String to be found being 0)
				if (0 == lengthSmall-1 - i) {
					std::cout << "Found at Pos " << position << " in " << myString;
					running = false;
				}

			}
			else {

				// break and add the skippable number of characters to the position when there is a mismatch 
				position += (lengthSmall - i);

				// end the algorithm if end of text is reached and nothing is found
				if (position + lengthSmall > lengthBig) running = false;

				// go to the new position and try matching the string again
				break;
			}


		};

	}

	return 0;
}