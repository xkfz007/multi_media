    X264_FILE="x264-snapshot-20160829-2245-stable.tar.bz2"
    X264_CMD='./configure --prefix="`pwd`" --disable-cli --enable-static --disable-shared'
    #X264_PC='x264.pc'
    compile_lib "$X264_FILE" "$X264_CMD" #"$X264_PC"