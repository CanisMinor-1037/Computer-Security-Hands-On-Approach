FOO=bar
echo $FOO
unset FOO
echo $FOO

strings /proc/$$/environ | grep LOGNAME
echo $LOGNAME
LOGNAME=bob
echo $LOGNAME
unset LOGNAME
echo $LOGNAME
strings /proc/$$/environ | grep LOGNAME