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
	SetWindowText(my, "身高计算器");
	while (true)
	{
		BeginBatchDraw();

		putimage(0, 0, &bk);
		setfillcolor(RGB(211, 210, 186));
		fillroundrect(333, 300, 433, 360, 10, 10);
		::setbkmode(TRANSPARENT);
		settextcolor(BLACK);
		::outtextxy(333 + (100 - textwidth("开始计算")) / 2,
					300+(60-textheight("开始计算"))/2,
					"开始计算");

		FlushBatchDraw();
		::peekmessage(&msg, EM_MOUSE );
		if (msg.x < 433 && msg.x>333 && msg.y < 360 && msg.y>300)
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				bool flag = 1;
				char h[10];
				InputBox(h, 10, "请输入您的身高：(cm)");
				for(int i=0;h[i]!='\0'; i++)
					if (h[i] < '0' || h[i] > 9 + '0')
						flag = 0;
				int hei=0;
				for (int i = 0; h[i] != '\0'; i++)
				{
					hei *= 10;
					hei += h[i] - '0';
				}
				string ans = "恭喜您，您的身高为：";
				ans += h;
				ans += "cm !";
				/*if (hei > 180 && hei < 220)
					ans += "\n(真几把高)";
				else if (hei < 140)
					ans += "\n(小矮子哈哈哈)";
				else if (hei > 220)
					ans += "\n(能不能输个正常点的身高?)";*/
				if(!flag)
					MessageBox(my, "恭喜您，您没有输入有效的身高！", "提示", MB_OK | MB_ICONASTERISK);
				if(h[0]!='\0'&&flag)
					MessageBox(my, ans.c_str(), "提示", MB_OK | MB_ICONASTERISK);
				else if(flag)
					MessageBox(my, "恭喜您，您没有输入您的身高！", "提示", MB_OK | MB_ICONASTERISK);
			}
		}
	}
	EndBatchDraw();


	return 0;
}