foo() { echo "hello world"; }
declare -f foo
foo
export -f foo
bash
declare -f foo
foo``