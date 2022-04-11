gcc -o mysleep mysleep.c
gcc -c sleep.c
gcc -shared -o libmylib.so.1.0.1 sleep.o
echo "./mysleep ..."
./mysleep
echo "set LD_PRELOAD=./libmylib.so.1.0.1"
export LD_PRELOAD=./libmylib.so.1.0.1
echo "./mysleep ..."
./mysleep
echo "unset LD_PRELOAD"
unset LD_PRELOAD
echo "./mysleep ..."
./mysleep
