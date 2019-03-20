#include "mrc_base.h" 
#include "mrc_win.h"
#include "mrc_exb.h"
#include "mrp.h"


char *mrpfile;



void Demo1WinWinEvent(int32 data, int32 eventId)
{
    switch (eventId)
    {
    case WIN_EVENT_SHOW:
    case WIN_EVENT_REFRESH:	
        break;
    case WIN_EVENT_PAUSE:
        break;
    case WIN_EVENT_EXIT:
        break;
    case WIN_EVENT_UPDATE:
        break;
    }
}
void progbar(uint8 value, uint8 error)
{
	char *temp;

	switch(value)
	{
	case 1:
		ShowLineText(0,"�������ģ��...",248,0,0);
		break;
	case 2:
		ShowLineText(1,"��ʼ�����ļ�...",248,0,0);
		break;
	case 3:
		ShowLineText(1,"��ʼд�ļ�ͷ...",248,0,0);
		break;
	case 4:
		ShowLineText(1,"�����ļ��б�...",248,0,0);
		break;
	case 5:
		ShowLineText(1,"�����ļ�����...",248,0,0);
		break;
	case 6:
		ShowLineText(1,"�����ļ���Ϣ...",248,0,0);
		break;
	case 7:
		if(error)
		{
			temp = (char*)malloc(50);
			mrc_sprintf(temp,"������%d������",error);
			ShowLineText(1,temp,248,0,0);
			mrc_free((void*)temp);
		}
		break;
	}
}
void dabao(void)
{
	int32 ret=0;
	char *aa="�ҵ�MRP����";
	TOMRPINFO MRPinfo;

	MRPinfo.appid = 1000;//APPID
	MRPinfo.version = 1001;//�汾ID
	MRPinfo.appname = aa;
	MRPinfo.description = aa;
	MRPinfo.filename = "MyMrp.mrp";
	MRPinfo.vendor = "Ĭˮƿ";

	ret = ToMrp("./temp","./MyMrp.mrp",204800, &MRPinfo, progbar);
	switch(ret)
	{
	case MRP_SUCCESS:
		ShowLineText(1,"��������ɹ���",255,255,255);
		return;
	case MRP_SEARCHFAILED:
		ShowLineText(1,"�޷������ļ���",255,255,255);
		break;
	case MRP_OPENFAILED:
		ShowLineText(1,"�޷����ļ���",255,255,255);
		break;
	case MRP_LISTLENFAILED:
		ShowLineText(1,"û���ҵ��ļ���",255,255,255);
		break;
	default:
		break;
	}
	ShowLineText(1,"�������ʧ�ܣ�",255,255,255);
}

void jb(void)
{		
	if(MR_FAILED != UnMrp(mrpfile,"temp",204800))
	{
// �����ɣ�
    }
}
void jy(void)
{			
	if(MR_FAILED != UnMrp(mrpfile,"temp",204800))
	{
		//��ѹ��ɣ�
	}
	else
	{
		//��ѹʧ�ܣ�
	}
}



void Demo1KeyWinEvent(int32 data, int32 type, int32 p1, int32 p2)
{
	if(MR_KEY_PRESS == type)
	{
		switch(p1)
		{
		case MR_KEY_1://��ѹ
			jy();
			return;
		case MR_KEY_2://��ȡ
			jb();
			return;
		case MR_KEY_3:
            dabao();
			return;
		default:
			return;
		}
	}
}

int32 mrc_init(void)
{
    mrpfile="1.mrp";
	mrc_winInit();
	mrc_winNew(0, Demo1WinWinEvent, Demo1KeyWinEvent);
	return MR_SUCCESS;
}

int32 mrc_appEvent(int32 code, int32 param0, int32 param1)
{
	mrc_winEvent(code, param0, param1);
	return MR_SUCCESS;
}


int32 mrc_appPause(void)
{
	return 0;
}


int32 mrc_appResume(void)
{
	mrc_winResume();
	return 0;
}


int32 mrc_exitApp(void)
{
	return 0;
}