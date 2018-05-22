#!/bin/bash

gcc -g -fsanitize=address -I includes main.c libftprintf.a
