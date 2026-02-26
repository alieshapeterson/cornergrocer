"# cornergrocer" 
Summarize the project and what problem it was solving.

This project required me to create a C++ console program that reads grocery item data from a text file and generates reports based on how often each item appears. 
The program allows the user to search for a specific item, display all item frequencies, and view a histogram that represents the frequency of each item using 
asterisks. It also creates a backup file that stores the calculated frequency data. The problem this project solves is generating accurate and up-to-date reports 
from data that may be updated outside of the program. Instead of storing values permanently, the program reads the input file each time a report is requested to 
ensure the information reflects the current data. 

What did you do particularly well?

I did particularly well in designing and implementing the GroceryItem class. I made sure the class properly encapsulated the grocery item’s name and quantity. The 
class does not contain any input or output operations, which makes it reusable in other applications. I also separated the file handling and menu logic from the 
data model. This improved the organization of the program and followed object-oriented programming principles. I included input validation to prevent invalid menu 
choices, which makes the program more reliable and user friendly. 

Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

One area for improvement is efficiency. The program currently uses a vector and performs a linear search to find items. This works well for small data sets but 
could become slower with larger files. Using a more efficient searching method or sorting the data before searching would improve performance. I could also 
improve the program by making searches case insensitive so that user input does not have to match capitalization exactly. Adding more advanced error handling 
would also improve security and stability. These improvements would make the program more efficient, more user friendly, and more robust in a real-world setting. 

Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

The most challenging part of this project was understanding how file handling works in Visual Studio and ensuring the program could correctly locate and read the 
input file. It was also challenging to design the class so that it followed proper encapsulation rules and did not include console operations. I overcame these 
challenges by testing the program step by step, using debugging tools in Visual Studio, and reviewing course materials about file input and object-oriented 
design. I also used C++ reference documentation to better understand vectors and file streams. These resources will continue to be part of my support network for 
future projects. 

What skills from this project will be particularly transferable to other projects or course work?

This project helped strengthen my understanding of object-oriented programming, file input and output, data structures, and input validation. These skills are 
transferable to many other programming projects because most applications require reading data, organizing it efficiently, and presenting it in a clear format. 
Learning how to separate data models from program logic is especially important for larger software systems and future coursework. 

How did you make this program maintainable, readable, and adaptable?

I made the program maintainable and readable by using clear variable and function names and by organizing the code into separate files for the class and the main 
program. I added comments to explain the purpose of important sections of code. I avoided hardcoding values when possible and structured the program so that new 
features could be added without major changes. The GroceryItem class can easily be expanded to include additional information, such as price or category, which 
makes the program adaptable for future use.
