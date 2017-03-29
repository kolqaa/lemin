# lemin
Your program will receive the data describing the ant farm from the standard output
in the following format:

number_of_ants
the_rooms
the_links

• The ant farm is defined by the following links:
##start
1 23 3
2 16 7
#comment
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
5
• Which corresponds to the following representation:
_______________
/ \
______[5]----[3]----[1] |
/ | / |
[6]-----[0]----[4] / |
\ _________/ | / |
\ / [2]/_______/
[7]_________/

• There are two parts:
 The rooms, which are defined by: name coord_x coord_y
 The links, which are defined by: name1-name2
 "All of it is broken by comments, which start with #"

"The rooms’ names won’t necessarily be numbers, and they won’t
necessarily be in the right and continuous order (we will find rooms
with names such as zdfg, qwerty, etc...) But most importantly, a
room will never start with the character L nor the character #"

The rooms’ coordinates will always be integers.

• Lines that start with ## are commands modifying the properties of the line that
comes right after.
• For example, ##start signals the ant farm’s entrance and ##end its exit.
Any unknown command will be ignored.
• Any non compliant or empty lines will automatically stop the ant farm’s reading
as well as the orderly processing of the acquired data.
• If there isn’t enough data to process normally you must display ERROR
