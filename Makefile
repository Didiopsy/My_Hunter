##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makes mylib
##



csfml = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

NAME = my_hunter

all: my_hunter

my_hunter:
	gcc ./src/*.c -o my_hunter -W -Wall -Wextra $(csfml)
	chmod 755 my_hunter

clean:
	rm -f $(NAME)

re: clean all
