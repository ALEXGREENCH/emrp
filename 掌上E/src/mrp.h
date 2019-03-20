#ifndef _E_MRP_H_
#define _E_MRP_H_

#include "mrc_base.h" 
#include "mrc_exb.h"


enum{
	MRP_SUCCESS,			//����ɹ�
	MRP_SEARCHFAILED,		//�޷������ļ�
	MRP_OPENFAILED,			//�޷����ļ�
	MRP_LISTLENFAILED,		//�б���Ϊ0(�ļ�����û���ļ���)
	MRP_FILE
};

typedef struct 
{
	char *appname;			//��ʾ��(�24��������)
	char *filename;			//�ڲ��ļ���(�12��������)
	uint32 appid;			//APPID		
	uint32 version;			//�汾
	char *vendor;			//������(�40��������)
	char *description;		//����(�64��������)

}TOMRPINFO;








typedef struct MRPHEAD{
    char    Magic[4];           //4  0   �ļ�����"MRPG"
    uint32  FileStart;          //4  4   ����8���� MRP���ݿ�ʼλ��,�ļ��б���ֹ��λ��
    uint32  FileLen;            //4  8   mrp�ļ����ֽ���
    uint32  ListStart;          //4  12  MRP�ļ��б�ʼλ��
    char    filename[12];       //12 16 �ڲ��ļ���
    char    appname[24];        //24 28 ��ʾ��
    char    unknown1[16];       //16 52 δ֪"1234567890"
    uint32  appid;              //4  68 appid(С��)
    uint32  version;            //4  72 �汾(С��)
    char    unknown2[12];       //12 76 δ֪
    char    vendor[40];         //40 88 ����
    char    Description[64];    //64 128 ����
    uint32  appid2;             //4  192 appid(���)
    uint32  version2;           //4  196 �汾(���)
    char    Reserved[40];       //40 200 δ֪(��ȫΪ0)
}T_MRP_HEAD;









//������Ȼص�
typedef void (*Ptr_TOMRP_progbar)(uint8 value, uint8 error);

/*
���MRP����
���룺
	InDir			//���Ŀ¼(δβ����"/")
	OutMrp			//������MRP�ļ�(�ɺ�·��)
	RAM				//�����ʹ�õ��ڴ��С(Ӧע��ʣ���ڴ�Ĵ�С������!)
	info			//���MRP����Ϣ
	TOMRP_progbar	//������Ȼص�
���أ�
	MRP_SUCCESS,			//����ɹ�
	MRP_SEARCHFAILED,		//�޷������ļ�
	MRP_OPENFAILED,			//�޷����ļ�
	MRP_LISTLENFAILED,		//�б���Ϊ0(�ļ�����û���ļ���)
*/
int32 ToMrp(const char *InDir, const char *OutMrp, int32 RAM, TOMRPINFO *info, Ptr_TOMRP_progbar TOMRP_progbar);

/*
��ѹ(��)MRP����
���룺
	MRPName		MRP�ļ�·��
	ToDir		�ļ����Ŀ¼(δβ����"/",���Ŀ¼�������򴴽�)
	RAM			ʹ�õ��ڴ��С(Ӧע��ʣ���ڴ�Ĵ�С������!)
���أ�
	�ɹ���
	MR_FAILED	ʧ��
*/
int32 UnMrp(char* MRPName, char* ToDir, int32 RAM);

#endif