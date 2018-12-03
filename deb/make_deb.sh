#/bin/sh

# update version number in deb control file
version=$(cat ../version | tr -d "\r" | tr -d "\n")
echo $version
echo "Package: comedi-k8055-bash-interface" > comedi-K8055-bash-interface/DEBIAN/control
echo "Version: $version" >> comedi-K8055-bash-interface/DEBIAN/control
echo "Maintainer: James Harwood" >> comedi-K8055-bash-interface/DEBIAN/control
if [ $(uname -r | grep -c "amd64" | tr -d "\r" | tr -d "\n") -eq 0 ]; then
 echo "Architecture: i386" >> comedi-K8055-bash-interface/DEBIAN/control
 dr="i386"
else
 echo "Architecture: amd64" >> comedi-K8055-bash-interface/DEBIAN/control
 dr="amd64"
fi
echo "Depends: libcomedi0 | libcomedi-dev" >> comedi-K8055-bash-interface/DEBIAN/control
echo "Description: Command line utilities to read/write Velleman k8055 cards from bash using comedi kernel drivers. https://github.com/jamesharwood/comedi-K8055_bash_interface" >> comedi-K8055-bash-interface/DEBIAN/control

# copy up to date compiled programs to deb build dir
cp ../bin/* ./comedi-K8055-bash-interface/usr/local/bin
rm ./comedi-K8055-bash-interface/usr/local/bin/*.sh
cp ../bin/*.sh ./comedi-K8055-bash-interface/usr/share/doc/comedi-K8055_bash_interface/examples

# make deb file
dpkg-deb --build comedi-K8055-bash-interface comedi-K8055-bash-interface_$version-$dr.deb


