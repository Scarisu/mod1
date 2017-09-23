make

printf "\n\033[1;34m-----------------------------------------\033[0;m\n"
printf "\033[1;34m		Valid\033[0;m\n"
printf "\033[1;34m-----------------------------------------\033[0;m\n"

	printf "\n[1] \033[4mDune\033[0m: (1p) \033[38;5;8m[demo1.mod1]\033[0m\n"
	read
	./mod1 ./resources/demo1.mod1
	printf "\n[2] \033[4mHill\033[0m: (3p) \033[38;5;8m[demo2.mod1]\033[0m\n"
	read
	./mod1 ./resources/demo2.mod1
	printf "\n[3] \033[4mLandscape\033[0m: (12p) \033[38;5;8m[demo3.mod1]\033[0m\n"
	read
	./mod1 ./resources/demo3.mod1
	printf "\n[4] \033[4mTank\033[0m: (5p) \033[38;5;8m[demo4.mod1]\033[0m\n"
	read
	./mod1 ./resources/demo4.mod1
	printf "\n[5] \033[4mBroken Tank\033[0m: (21p) \033[38;5;8m[demo5.mod1]\033[0m\n"
	read
	./mod1 ./resources/demo5.mod1
