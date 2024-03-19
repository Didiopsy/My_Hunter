##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makes mylib
##



csfml = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

NAME = my_paint

all: my_paint

my_paint:
	gcc *.c -o my_paint -I../includes -W -Wall -Wextra $(csfml)
	chmod 755 my_paint

clean:
	rm -f $(NAME)

re: clean all
