#include "Init.h"
#include "Command.h"
#include "WSClient.h"
#include "Util.h"


bool isHook = false;
/**
 * ��ʼ�� Hook
 * @param
 * @return void
*/
void InitWeChat() {
	neb::CJsonObject result;

	if (isHook) {
		Send(Cmd_Init, result, "", 1, L"�ѳ�ʼ����");
		return;
	}
	//��鵱ǰ΢�Ű汾
	try
	{
		if (IsWxVersionValid()) {


			isHook = true;

			Send(Cmd_Init, result, "", 0, L"��ʼ���ɹ���");
		}
		else
		{
			isHook = false;
			Send(Cmd_Init, result, "", 2, L"��ǰ΢�Ű汾��ƥ�䣬������WeChat2.7.1.88��");
		}
	}
	catch (...)
	{
		isHook = false;
		Send(Cmd_Init, result, "", 3, L"��ʼ���쳣��");

	}
}
