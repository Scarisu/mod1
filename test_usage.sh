make

printf "\033[1;34m-----------------------------------------\033[0;m\n"
printf "\033[1;34m		Usage \033[0;m\n"
printf "\033[1;34m-----------------------------------------\033[0;m\n"

	printf "\n[1] \033[4mToo many maps\033[0m: \033[38;5;8m[demo1.mod1 | demo2.mod1]\033[0m\n"
	read
	./mod1 ./resources/demo1.mod1 ./resources/demo2.mod1
	printf "\n[2] \033[4mNo file\033[0m:\n"
	read
	./mod1
	printf "\n[3] \033[4mFile doesn't exist\033[0m: \033[38;5;8m[falaise.mod1]\033[0m\n"
	read
	./mod1 ./resources/falaise.mod1
	printf "\n[4] \033[4mNo access file\033[0m: \033[38;5;8m[bad_access.mod1]\033[0m\n"
	read
	chmod 000 ./resources/bad_access.mod1
	./mod1 ./resources/bad_access.mod1
	chmod 644 ./resources/bad_access.mod1
	printf "\n[5] \033[4mInvalid format\033[0m: \033[38;5;8m[format_invalid.pdf]\033[0m\n"
	read
	./mod1 ./resources/format_invalid.pdf
	printf "\n[6] \033[4mMissing format\033[0m: \033[38;5;8m[format_missing]\033[0m\n"
	read
	./mod1 ./resources/format_missing
	printf "\n[7] \033[4mRandom file\033[0m: \033[38;5;8m[dev/random]\033[0m\n"
	read
	./mod1 /dev/random
	printf "\n[8] \033[4mZero file\033[0m: \033[38;5;8m[/dev/zero]\033[0m\n"
	read
	./mod1 /dev/zero
	printf "\n[8] \033[4mNull file\033[0m: \033[38;5;8m[/dev/null]\033[0m\n"
	read
	./mod1 /dev/null
