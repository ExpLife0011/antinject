#ifndef _AVS_INTERFACE_H_
#define _AVS_INTERFACE_H_

#include <time.h>

#define  AVS_API

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

//���ܣ���ʼ���ӿڣ����ز�����
//������
//		strLibPath ������·��
//���أ���ʼ���ɹ�0,���򷵻ش�����
AVS_API int init_stream_av_engine(char *strLibPath);


//���ܣ��������棬�ͷ�������Դ
//��������
//���أ���
AVS_API void destroy_stream_av_engine();


typedef struct tagStreamAvEngineWorkType
{
	int nUnRar;				//���÷�0ֵ֧�ֽ�ѹ��,
	int nDecodeEmail;		//���÷�0ֵ֧���ʼ�����
	int	nUnrarFloor;		//���ý�ѹ���������ֵ��2����bUnRarΪ��0ֵ��ʱ���ֶ���Ч
	//time_t tUnrarTime;		//���������ɽ�ѹʱ�䣬��λ���룬��bUnRarΪ��0ֵ��ʱ���ֶ���Ч
	int	nUnrarFileSize;		//����ѹ������С���ֵ(��λ��B)
	//int	nMaxMemorySize;		//��������������ʹ���ڴ棨��Ҫ�ǿ������滺�����ڴ�ʹ�ã�����λ���ֽ�
	char strTempPath[260];		//������ʱĿ¼,�����ڲ����ܻ��õ�(�����ѹ���ļ���ʱ��)(���Բ�����,����Ĭ���ǵ�ǰĿ¼)
}StreamAvEngineWorkType, *PStreamAvEngineWorkType;

//���ܣ��������湤����ʽ��Ĭ������ǲ�֧�ֽ�ѹ�����ʼ�����ɨ�裩
//������
//		pStreamAvEngineWorkType ����Ĺ�����ʽ�ṹ��ָ��
//���أ���(�����ѹ����,����ñ����������������)
AVS_API void config_stream_av_engine_work_type(PStreamAvEngineWorkType pStreamAvEngineWorkType);


//���ܣ����������⣬�����ɹ�����������Ҳ��ʹ���¿�ɨ�裬����ʧ���򲻶���������Ϳ��ļ�����κ�Ӱ�졣
//������
//		strLibPath ������·��
//���أ��ɹ�����0,���򷵻ش�����
//˵������������ڲ����ܻ����������
AVS_API int engine_update_virus_lib(char *strLibPath);


//���ܣ���֤���������Ч��
//������
//		strUpdateLibPath ������Ĳ�����·��
//���أ���Ч����0,���򷵻ش�����
//˵������������������ô��ʱ���ж��¾�
AVS_API int check_avs_library_valid(char *strUpdateLibPath);


//���ܣ���ѯ������Ϣ
//������
//		nErrorCode ������
//���أ�����������ж�Ӧ������Ϣ�����ش�����Ϣ�ַ���ָ�룬����NULL
AVS_API char *query_engine_error_info(int nErrorCode);


#define STREAM_CHECK_HANDLE 0	//��ȡ���������־
#define FILE_CHECK_HANDLE	1	//�����ļ��������־

#define NOT_CHECK_EMAIL		0	//Ҫ���Ĳ����ʼ�
#define CHECK_EMAIL			1	//����ʼ�

#define UNKNOW_STREAM_LEN	0	//��֪�����ĳ���,����������ǰ��֪�����ж೤
#define KNOW_STREAM_LEN		1	//֪�����ĳ���,��������ǰ֪������/�����������������ټ�ⲡ��(���ô˱�־)

//���ܣ���ȡһ���������ļ������
//������
//		nHandleType ��Ҫ��ȡ�ľ������
//		nCheckEmailType �Ƿ����ʼ�
//		nKnowStreamLen ��ʾ��ǰҪ����������ļ�,�����Ƿ��о��Եİ���ȷ�����ĳ���,���������ȷ�����ж����ֽ�,�����������־,�������Ч��
//���أ��ɹ����ؾ��ֵ��һ����NULL����ʧ�ܷ���NULL
AVS_API void *av_engine_create_handle(int nHandleType, int nCheckEmailType, int nKnowStreamLen);


//���ܣ��ر��ļ������������
//������
//		nHandle ���ֵ
//���أ��ɹ�0������-1
AVS_API int av_engine_close_handle(void *nHandle);


//���ܣ������ļ������������
//������
//		nHandle ���ֵ
//���أ����ش�����
AVS_API void * av_engine_reuse_handle(void *nHandle);


#define FILE_SIGNLE_PACKET_BUF	0	//��ʾ�����һ�����������ݰ�
#define FILE_ALL_PACKEt_BUF		1	//��ʾ�����һ�������������ļ�ƴ�ϻ�����

//�ļ���ʽ��⴫����������ṹ��
typedef struct tagFileStreamAvEngineIn
{
	int		nAllPacketBuf;		//���ó�FILE_SIGNLE_PACKET_BUF����FILE_ALL_PACKEt_BUF
}FileStreamAvEngineIn, *PFileStreamAvEngineIn;

#define STREAM_END		1	//��������־
#define STREAM_NOT_END	0	//��δ������־

//����ṹ����ȫ�ɵ��������
typedef struct tagStreamAvEngineIn
{
	char *pData;		//����ָ��(���ֶ��Ͻ�����ΪNULL)
	int nDataLen;		//���ݳ���(������μ��ֻΪ�˸�֪����������,����ʵ�����ݴ���,����ֶ�������ó�0)
	int	nEnd;			//��ʾ���Ƿ����,STREAM_END��ʾ����,�������ó�STREAM_NOT_END
	
	FileStreamAvEngineIn	fin;	//�ļ���ʽ��ⲡ��ʱ��,�Լ����еĽṹ
}StreamAvEngineIn, *PStreamAvEngineIn;

#define AV_ENGINE_FIND_NOTHING			(0)
#define AV_ENGINE_END_THIS_STREAM_CHECK	(1)
#define AV_ENGINE_FIND_VIRUS			(2)

//��⵽�Ĳ�����Ϣ
typedef struct tagCheckedVirusInfo
{
	//���������ֶ������ڲ�����,�����ϲ���ΪNULL,���������ʹ��ǰ�ж����Ƿ�ΪNULL
	char *	strVirusName;	//���ز�����
	char *	strVirusType;	//���ز�������
}CheckedVirusInfo, *PCheckedVirusInfo;

//��⵽����,���ؾ�����Ϣ����
typedef struct tagStreamAvEngineOut
{
	//ֻ�е�����AV_ENGINE_FIND_VIRUSʱ����Ч
	CheckedVirusInfo	virusInfo;	//��⵽�Ĳ�����Ϣ

	int		nNeedAllPacket;	//�Ƿ���Ҫ�������а�,��0��ʾ��Ҫ���а�����,����file_av_engine_check_virus����ʱ���õ�,һ���Ƕ�һЩrar����,��Ҫȫ�ļ�������Ч��ѹ��,���ֵÿ�ε���file_av_engine_check_virus��������
}StreamAvEngineOut, *PStreamAvEngineOut;

//���ܣ�����ʽ��ⲡ����������֧�ֶ���߳�ͬʱ���ã�
//������
//		pStreamAvEngineIn ��⴫��Ľṹ��ָ��
//		nHandle �����
//		pStreamAvEngineOut ��⵽�������ز�����ϸ��Ϣ(�������Ҫ�����Ϣ���Դ���NULL)
//���أ�END_THIS_STREAM_CHECK��ʾ�Ե�ǰ������Ҫ����ˣ���δ��⵽��������⵽��������AV_ENGINE_FIND_VIRUS��δ��⵽��������AV_ENGINE_FIND_NOTHING
//˵��������AV_ENGINE_END_THIS_STREAM_CHECK/AV_ENGINE_FIND_VIRUSʱ,�Ͳ�Ӧ���ٵ��ñ�������Ȿ����
AVS_API int stream_av_engine_check_virus(PStreamAvEngineIn pStreamAvEngineIn, void *nHandle, PStreamAvEngineOut pStreamAvEngineOut);


//���ܣ��ļ���ʽ��ⲡ����������֧�ֶ���߳�ͬʱ���ã�
//������
//		pStreamAvEngineFileFormatIn ��⴫��Ľṹ��ָ��
//		nFileHandle �ļ������Ϣ���
//		pStreamAvEngineOut ��⵽�������ز�����ϸ��Ϣ(�������Ҫ�����Ϣ���Դ���NULL)
//���أ�END_THIS_STREAM_CHECK��ʾ�Ե�ǰ������Ҫ����ˣ���δ��⵽��������⵽��������AV_ENGINE_FIND_VIRUS��δ��⵽��������AV_ENGINE_FIND_NOTHING
//˵��������AV_ENGINE_END_THIS_STREAM_CHECK/AV_ENGINE_FIND_VIRUSʱ,�Ͳ�Ӧ���ٵ��ñ�������Ȿ�ļ���
AVS_API int file_av_engine_check_virus(PStreamAvEngineIn pStreamAvEngineIn, void *nHandle, PStreamAvEngineOut pStreamAvEngineOut);


#ifdef __cplusplus
};
#endif //__cplusplus

#endif //_AVS_INTERFACE_H_
