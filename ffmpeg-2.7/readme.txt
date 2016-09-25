 -i "e:/QQDownload/angry.birds.ts" -map 0:v -c copy -f tee "[hls_wrap=0:hls_time=10:hls_list_size=15:hls_flags=+discont_start:hls_flags=+round_durations:hls_flags=+delete_segments:hls_segment_filename='./20160718155305-01-%d.ts':start_number=1468828385]./01.m3u8"

  -i "e:/QQDownload/angry.birds.ts" -map 0:v -c copy -hls_wrap 0 -hls_time 10 -hls_list_size 15 -hls_flags +discont_start -hls_flags +round_durations -hls_flags +delete_segments -hls_segment_filename './20160718155305-01-%d.ts' -start_number 1468828385 ./01.m3u8
  
  