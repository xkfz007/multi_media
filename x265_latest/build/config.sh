#!/bin/bash
current_dir=`pwd`
build_dir=$current_dir/builds
if [ ! -e $build_dir ];then
    mkdir -p $build_dir
fi
source_dir=`readlink -f $current_dir/../source`
echo $source_dir
CMD="cmake -G \"Unix Makefiles\" $source_dir -DCMAKE_INSTALL_PREFIX=$build_dir -DENABLE_STATIC:bool=on -DENABLE_SHARED:bool=off -DENABLE_CLI:bool=off"
cd $build_dir
echo $CMD
eval $CMD
make && make install
cd -
