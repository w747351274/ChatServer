#!/bin/bash

basepath=$(cd `dirname $0`;pwd)
echo "basepath ->"$basepath;
des_path='/Headers/'
header_path=$basepath$des_path

echo "des_path->"${des_path}
echo "header_path->"$header_path

mkdir $des_path

cd $header_path

#拷贝一份 Library ，然后删除里面的所有的 .m文件
#
cp -rf  $basepath/ $header_path

find -L ${header_path} -name "*.m" -exec rm -rf {} \;

find -L ${header_path} -name "*.mm" -exec rm -rf {} \;

find -L ${header_path} -name "*.c" -exec rm -rf {} \;

find -L ${header_path} -name "*.cc" -exec rm -rf {} \;

find -L ${header_path} -name "*.proto" -exec rm -rf {} \;

find -L ${header_path} -name "*.h" -print \;

