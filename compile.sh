#!/bin/bash

#make re

gcc -Wall -Werror -Wextra -g -fsanitize=address -I includes main.c libftprintf.a
