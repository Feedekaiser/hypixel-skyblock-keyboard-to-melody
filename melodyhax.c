#include <Windows.h>

int main(void)
{
	struct a
	{
		int keycode;
		int pressed;
		int x;
		int y;
	} 
	aa[] = {
		{ 'A', 0, 2069, 1319 },
		{ 'S', 0, 2231, 1319 },
		{ 'D', 0, 2395, 1319 },
		{ 'F', 0, 2555, 1319 },
		{ 'J', 0, 2714, 1319 },
		{ 'K', 0, 2881, 1319 },
		{ 'L', 0, 3040, 1319 }
	};

	// map to whatever weird system microsoft is using
	for (int i = 0; i < 7; ++i)
		aa[i].x = aa[i].x * 65535 / 5120, aa[i].y = aa[i].y * 65535 / 2880;

	for (;;)
		for (int i = 0; i < 7; ++i)
			if (GetAsyncKeyState(aa[i].keycode) & 0x8000)
			{
				if (!aa[i].pressed)
				{
					mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE, aa[i].x, aa[i].y, 0, 0);
					mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
					mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
					aa[i].pressed = 1;
				}
			}
			else aa[i].pressed = 0;
}