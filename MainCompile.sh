# java程序的编译脚本，适用于linux平台
PROJECT_DIR=/home/ysxiang/workspace/java_project/algorithm
# clean target directory
rm -rf $PROJECT_DIR/target/*

# prepare arg files
find $PROJECT_DIR/src -name "*.java">$PROJECT_DIR/target/javaFiles.txt
echo "-d $PROJECT_DIR/target" >$PROJECT_DIR/target/javaOptions.txt
# compile
javac @$PROJECT_DIR/target/javaOptions.txt @$PROJECT_DIR/target/javaFiles.txt

# clean temp files
rm -rf $PROJECT_DIR/target/javaOptions.txt $PROJECT_DIR/target/javaFiles.txt% 