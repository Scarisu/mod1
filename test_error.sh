make

printf "\n\033[1;34m-----------------------------------------\033[0;m\n"
printf "\033[1;34m		Map error \033[0;m\n"
printf "\033[1;34m-----------------------------------------\033[0;m\n"

	printf "\n[1] \033[4mCharacter invalid 1\033[0m: \033[38;5;8m[character_invalid_1.mod1]\033[0m\n"
	read
	./mod1 ./resources/character_invalid_1.mod1
	printf "\n[2] \033[4mCharacter invalid 2\033[0m: \033[38;5;8m[character_invalid_2.mod1]\033[0m\n"
	read
	./mod1 ./resources/character_invalid_2.mod1
	printf "\n[3] \033[4mInfo invalid 1\033[0m: \033[38;5;8m[info_invalid_1.mod1]\033[0m\n"
	read
	./mod1 ./resources/info_invalid_1.mod1
	printf "\n[4] \033[4mInfo invalid 2\033[0m: \033[38;5;8m[info_invalid_2.mod1]\033[0m\n"
	read
	./mod1 ./resources/info_invalid_2.mod1
	printf "\n[5] \033[4mNumber too long\033[0m: \033[38;5;8m[number_too_long.mod1]\033[0m\n"
	read
	./mod1 ./resources/number_too_long.mod1
