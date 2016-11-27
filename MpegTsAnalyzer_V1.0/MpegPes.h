#ifndef	_MPEG_PES_H_
#define	_MPEG_PES_H_

#define MPEG_PES_PACKET_START_PREFIX		"\x00\x00\x01"

/*
offset 0: 00 00 01 BA, ��������ʼ��
	      00 00 01 BB, system_header_start_code: ������ϵͳ�ײ���ʼ��
	      00 00 01 BC, program_stream_map
	      00 00 01 BE, padding_stream, �����
	      00 00 01 E0, video stream, ��Ƶ��ID=E0(1110 xxxx)
	      00 00 01 C0, audio   stream: ��Ƶ��:ID=C0(110x   xxxx)
	      00 00 01 B3, sequence_header_code: ��Ƶ����ͷ�� 
	      00 00 01 B5, extension_start_code: ͼ�������չ
	      00 00 01 B8, group_start_code: ͼ��ͷ   TIMECODE(00:00.20-00) 
	      00 00 01 00, picture_start_code: ͼ��ͷ(����ͼ��)--֡����(1-I,2-P,3-B)1
	      00 00 01 01, slice_start_code: ���:ID=01     
	      00 00 01 02, slice_start_code: ���:ID=02     
	      00 00 01 03, slice_start_code: ���:ID=03     
	      00 00 01 04, slice_start_code: ���:ID=04     
	      00 00 01 05, slice_start_code: ���:ID=05     
	      00 00 01 06, slice_start_code: ���:ID=06     
*/

/*
In Program Streams, the stream_id for DTS is ��private_stream_1�� = 1011 1101 = 0xBD
*/
//PES packet header
typedef struct tagMPEG_PES_HEADER
{
	unsigned char prefixPesStartCode[3];	//��ͷ��ʼ��ǰ׺, "\x00\x00\x01"
	unsigned char idStream;	//������ʶ��, LS bits give stream number
	UINT uiPesPacketLength;	//network byte order, 27 6A->0x276A
	/*
	If stream ID is Private Stream 2 or Padding Stream, skip to data bytes.
	*/
	//��������������Ϣ(3~259Bytes)
	unsigned short int pes_scrambling_control : 2;	//PES���ſ���
	unsigned short int pes_priority : 1;	//PES����
	unsigned short int data_position_indicator : 1;	//���ݶ�λָʾ��
	unsigned short int copyright : 1;	//��Ȩ
	unsigned short int original_or_copy : 1;	//ԭ��򿽱�
	unsigned short int PTS_or_DTS_flag : 2;	//PTS/DTS��־
	unsigned short int ESCR_flag : 1;	//ESCR��־
	unsigned short int base_stream_rate_flag : 1;	//���������ʱ�־
	unsigned short int DSM_trick_mode_flag : 1;	//DSM�ؼ���ʽ��־
	unsigned short int additional_info_copy : 1;	//���ӵ���Ϣ����
	unsigned short int PES_CRC_flag : 1;	//PES CRC��־
	unsigned short int PES_extension_flag : 1;	//PES��չ��־
	unsigned char ucPesPacketHeaderLen;	//PES��ͷ��
	UINT64 uiPts;	//presentation timestamp
	UINT64 uiDts;
}MPEG_PES_HEADER, *P_MPEG_PES_HEADER;

typedef struct tagMPEG_PES_PACKET_INFO{
	BYTE idPesStream;
	PBYTE pPayloadAddr;
	INT iPayloadSize;
}MPEG_PES_PACKET_INFO, *P_MPEG_PES_PACKET_INFO;

//MPEG ES packet
typedef struct tagMPEG_ES_HEADER
{
	unsigned char eFrameType[4];	//"\x00\x00\0x01\x00", I,B,P frame type
}MPEG_ES_HEADER, *P_MPEG_ES_HEADER;

#endif	//_MPEG_PES_H_

