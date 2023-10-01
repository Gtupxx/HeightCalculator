#include<iostream>
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<string>
#include"resource.h"

using namespace std;

#ifndef _DEBUG
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
#endif // _DEBUG

int main()
{
	IMAGE bk;
	ExMessage msg;
	loadimage(&bk,"PNG", MAKEINTRESOURCE(IDB_PNG1));
	HWND my = initgraph(515, 410);
	SetWindowText(my, "��߼�����");
	while (true)
	{
		BeginBatchDraw();

		putimage(0, 0, &bk);
		setfillcolor(RGB(211, 210, 186));
		fillroundrect(333, 300, 433, 360, 10, 10);
		::setbkmode(TRANSPARENT);
		settextcolor(BLACK);
		::outtextxy(333 + (100 - textwidth("��ʼ����")) / 2,
					300+(60-textheight("��ʼ����"))/2,
					"��ʼ����");

		FlushBatchDraw();
		::peekmessage(&msg, EM_MOUSE );
		if (msg.x < 433 && msg.x>333 && msg.y < 360 && msg.y>300)
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				bool flag = 1;
				char h[10];
				InputBox(h, 10, "������������ߣ�(cm)");
				for(int i=0;h[i]!='\0'; i++)
					if (h[i] < '0' || h[i] > 9 + '0')
						flag = 0;
				int hei=0;
				for (int i = 0; h[i] != '\0'; i++)
				{
					hei *= 10;
					hei += h[i] - '0';
				}
				string ans = "��ϲ�����������Ϊ��";
				ans += h;
				ans += "cm !";
				/*if (hei > 180 && hei < 220)
					ans += "\n(�漸�Ѹ�)";
				else if (hei < 140)
					ans += "\n(С���ӹ�����)";
				else if (hei > 220)
					ans += "\n(�ܲ����������������?)";*/
				if(!flag)
					MessageBox(my, "��ϲ������û��������Ч����ߣ�", "��ʾ", MB_OK | MB_ICONASTERISK);
				if(h[0]!='\0'&&flag)
					MessageBox(my, ans.c_str(), "��ʾ", MB_OK | MB_ICONASTERISK);
				else if(flag)
					MessageBox(my, "��ϲ������û������������ߣ�", "��ʾ", MB_OK | MB_ICONASTERISK);
			}
		}
	}
	EndBatchDraw();


	return 0;
}