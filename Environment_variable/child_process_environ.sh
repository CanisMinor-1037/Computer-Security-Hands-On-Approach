strings /proc/$$/environ | grep LOGNAME
LOGNAME2=alice
export LOGNAME3=bob
env | grep LOGNAME
unset LOGNAME
env | grep LOGNAME