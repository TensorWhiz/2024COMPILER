#!/bin/bash
func_testcase_dir=$(realpath $(dirname "$0")/./tests/public)
#func_testcase_dir=$(realpath $(dirname "$0")/./tests/private)
test_single() {
	test_file=`realpath --relative-base=$func_testcase_dir $func_testcase_dir/$1.tea`	
	test_name=${test_file%.tea}
	
	echo -n $test_name
	echo ": "

	./build/compiler $func_testcase_dir/$test_name.tea
	if [ $? != 0 ]; then
		echo fail; exit 0
	fi
    llvm-link  $func_testcase_dir/$test_name.ll $func_testcase_dir/../sylib.ll -S -o ./output/ir/$test_name.ll
	if [ $? != 0 ]; then
		echo "fail to link"; exit 0
	fi
	if [ -f $func_testcase_dir/$test_name.in ]; then
    	lli  ./output/ir/$test_name.ll < $func_testcase_dir/$test_name.in > output/ir/$test_name.out
	else
    	lli  ./output/ir/$test_name.ll > ./output/ir/$test_name.out
	fi
	echo -e $? >> ./output/ir/$test_name.out
	diff -Bb ./output/ir/$test_name.out $func_testcase_dir/$test_name.out > ./output/ir/$test_name.txt
	if [ $? == 0 ]; then
        echo pass; 
	else
		echo fail;\
		# echo "Expect:";\
		# cat $func_testcase_dir/$test_name.out;\
		# echo "Got:";\
		# cat ./output/$test_name.out;\
		exit 0
	fi
}

main() {
	test_single $1
}

main $@
