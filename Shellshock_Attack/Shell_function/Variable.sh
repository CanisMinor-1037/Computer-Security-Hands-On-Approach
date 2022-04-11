foo='() { echo "hello world"; }'
echo $foo
declare -f foo
export foo
../image_www/bash_shellshock
foo
declare -f foo
echo $foo