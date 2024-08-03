# What it does
This project takes in a list of items, in this case items sold in a grocery store, from a separate file and tallies up how many times each item appeared in the list, or was sold. The user can input options on how they view that data. This will loop until the user enters the command to exit

### Option One:
The user can chose to print out a list of every unique item in the list and how many times that item was sold

### Option Two:
The user can enter in an item that the believe is in the list and that item and the corresponding amount of times it was sold is printed to the user

### Option Three:
The program makes a new file containing the results of **Option One**. It then reads the file and creates a visual model (histogram) of each item and how many times it has sold

# Things I did Well
I think I was able to look up resources for this project very well, such as file handling, in which I had no problems. This project overall felt much easier than the others we had this term and it was the one I felt the most confident in.

# Improving the code
Something needed to enhance this code and make it more usable for a company setting would be better input validation. Making sure the user's selection of options falls within the range works great, so long as the user enters a value of int type. Any other type would result in an infinite loop. While this was fine for the project to turn in, it would likely need to be revised if it were to be used for some sort of business. 
The other area of the program where this applies would be when the user enters a certain item they are looking for. This could be improved by searching for the item without capitalization and maybe displaying a more unique message than 'itemNotFound was sold 0 time/s'

# Challenging Pieces
The only real challenging bit for me in this project was deciding which input validation method to use and why. I decided on a do-while loop with conditional statements instead of something like throwing exceptions and a try-catch block just because conditionals are a bit more comfortable to me. The challenging bit came when trying to improve the functional implementation I already had. I wasn't able to improve much with my deadline getting closer, so that's why it became a part that needs improving

# Transferable Skills
Handling files and using multiple languages are skills I feel will be the most useful to me as a begin to apply them to other, larger projects and setting rather than just 'school assignment'

# Upkeep
My descriptive commenting is the largest contributor to keeping my code readable and maintainable. I largely think about comments just as if I make a mental note on what is going on then I will typically comment it on the document such as the conditions of a loop or where I'm getting a section of data from
