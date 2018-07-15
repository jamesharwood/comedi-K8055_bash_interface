# comedi-K8055_bash_interface
Simple bash command line utilities to read/write K8055 cards using comedi kernel modules. Aimed at hobbyists like myself. 

A kernel with comedi and VMK80xx modules must be used (Most recent Debian 3.X kernels will have these by default).

To build/install on Debian based systems:<br>
apt-get install libcomedi-dev libcomedi0<br>
./make.sh<br>
cd deb<br>
./make_deb.sh<br>
dpkg -i comedi-K8055-bash-interface<br>

A precompiled .deb file is also included in the deb directory if you dont want to compile from source.

All program files are installed to /usr/local/bin
Example scripts are in /usr/share/doc/comedi-K8055_bash_interface/examples

Run /usr/local/bin/k8055-help for descriptions of programs and usage.

Run programs as root unless you have access rights to /dev/comediX

09/07/2018 James Harwood
