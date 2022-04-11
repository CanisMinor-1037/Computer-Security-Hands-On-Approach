foo() { echo "Insider Function"; }
declare -f foo
foo
unset -f foo
declare -f foo
