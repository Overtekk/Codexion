#!/bin/bash

RED='\033[0;31m'
NC='\033[0m'

PROG="./codexion"

if [ -z "$1" ]; then
    echo -e "${RED}Missing test number.${NC}"
    echo "Usage: ./tester.sh <1>"
    exit 1
fi

VALGRIND=""
if [ "$2" == "mem" ]; then
    VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes"
fi

run_test() {
	echo -e "Test $1 : $2\n"
	$VALGRIND $PROG $2
}

#  <number_of_coders>
#  <time_to_burnout> <time_to_compile> <time_to_debug> <time_to_refactor>
#  <number_of_compiles_required>
#  <dongle_cooldown> <scheduler>


case "$1" in
	1)
		run_test basic_fifo "4 800 200 200 200 5 10 fifo" # Should burn out
		;;
	2)
		run_test basic_edf "4 800 200 200 200 5 10 edf" #
		;;
	3)
		run_test success_fifo "10 10000 100 100 100 5 50 fifo" # Should success
		;;
	big)
		run_test big_test "100 10000 66 24 87 10 10 fifo" # Should success
		;;
	one_compiler)
		run_test one_compiler "1 1000 200 200 200 5 50 fifo" # Should burn out
		;;
	toomany_compiler)
		run_test toomany_compiler "999 1000 200 200 200 5 50 fifo" # Managed like an error
		;;
	*)
		echo -e "${RED}Unkown test.${NC}"
		;;
esac
