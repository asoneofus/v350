####Prerequisites
For general Android prerequisites, see http://source.android.com/

1. Download the whole Android code tree from source.android.com, use the TAG of this code base (android-2.3.7_r1)

2. Suppose the work directory of step #1 is /home/prj/
    export MYPKGTOP=/home/prj
    cd ${MYPKGTOP}

3. Decompress modules to your work directory
    kernel.tar.gz
    external.tar.gz
    bionic.tar.gz
    system.tar.gz
    build.tar.gz
4. Run the following commands to build
    $ source build/envsetup.sh
    $ lunch full-user (or lunch full-eng)
    $ make