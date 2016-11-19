    X265_FILE="x265_2.0.tar.gz"
    X265_CMD='cmake -G "Unix Makefiles" "`pwd`/source" -DCMAKE_INSTALL_PREFIX="`pwd`" -DENABLE_STATIC:bool=on -DENABLE_SHARED:bool=off -DENABLE_CLI:bool=off'
    #X265_PC='x265.pc'
    compile_lib "$X265_FILE" "$X265_CMD" #"$X265_PC"