# Day 1

The task was about Elves and about the calorie levels on their food stock. I was given a list where every food items calorie level was stored.
Each item was seperated by a newline, and each there was a blank line seperation for each elf.

## Task 1
Find the elf with the highest sum of calories. I solved this by first reading from the file and summing up each elves calories and adding it to an array.
Each array entry was then a sum of the calories. To find the largest I decided to do this:

``c
  int highestCalorieIndex = 0;
  for (int i = 0; i < elfCount; i++) {

    if (elfCalories[i] > elfCalories[highestCalorieIndex]) {
      highestCalorieIndex = i;
    }
  }

``
This loop stored the index of the currently largest sum, and compared each item to the value. This made it so that I got the largest sum.


## Task 2
- Get the top three largest sums and sum them together

Since I haven't tried a sorting algorithm in C before, I decided to solve this issue by implementing the quicksort algorithm.
I sorted the array in descending order, and summed the first 3 indexes in the array together and got the answer
