#include "DxLib.h"
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

class Ship{
	public: 
		char* sName;
		int point;
		int hitpoint;
		int player;

	public:
		Ship(char* sN, int _point, int _hitpoint, int _player){
			sName = new char[4];
			//strcpy(sName, sN);
			point = _point;
			hitpoint = _hitpoint;
			player = _player;
			cout << sName << "を作成しました。\n";
		}

		void move(int _point){
			point = _point;
		}
};

class Game{
	public:
		int turn;
		
};

void Haichi(int GHandle, int* pT);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	int Cr;
	boolean Button1, Button2;

	// ウインドウモードに変更
	ChangeWindowMode(TRUE);
	// 画面モードの設定
	SetGraphMode(1280, 768, 32);
	SetDrawScreen(DX_SCREEN_BACK);
	//SetWindowSizeExtendRate(2.0);

	int MouseX, MouseY;
	int MouseInput;

	if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
	{
		return -1;    // エラーが起きたら直ちに終了
	}
	
	// 白色の値を取得
	Cr = GetColor(255, 255, 255);

	DrawBox(600, 500, 800, 550, Cr, TRUE);    // 四角形を描画
	DrawBox(900, 500, 1100, 550, Cr, TRUE);    // 四角形を描画
	DrawString(600, 525, "初期配置を決める", BLACKNESS);
	DrawString(1000, 525, "初期配置を決めない", BLACKNESS);


	MouseInput = GetMouseInput();
	while ((MouseInput & MOUSE_INPUT_LEFT) == 0)
	{
		while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen())
		{
			DrawBox(600, 500, 800, 550, Cr, TRUE);    // 四角形を描画
			DrawBox(900, 500, 1100, 550, Cr, TRUE);    // 四角形を描画

			// マウスの位置を取得
			GetMousePoint(&MouseX, &MouseY);
			if (MouseInput & MOUSE_INPUT_LEFT) //マウスの左ボタンが押されていたら
				DrawString(0, 0, "左ボタンが押されています", GetColor(255, 255, 255));
			// メッセージ処理
			if (ProcessMessage() == -1)
			{
				break;    // エラーが起きたらループから抜ける
			}
			if (600 <= MouseX && MouseX <= 800 && 500 <= MouseY && MouseY <= 550){
				// マウスの入力を得る
				MouseInput = GetMouseInput();
				Button1 = TRUE;
				break;
			}
			else if (900 <= MouseX && MouseX <= 1100 && 500 <= MouseY && MouseY <= 550){
				MouseInput = GetMouseInput();
				Button2 = TRUE;
				break;
			}
			else MouseInput = 0;
			
		}
	}

	// 画面を初期化
	ClearDrawScreen();

	int GHandle0, GHandle;     // 画像格納用ハンドル
	GHandle0 = LoadGraphScreen(0,0, "昼空.png", TRUE);
	GHandle = LoadGraphScreen(100, 200, "マス空.png",TRUE);
	GHandle = LoadGraphScreen(700, 200, "マス空.png", TRUE);
	
	DrawString(100, 50, "艇の初期配置をクリックで指定してください。\n", BLACKNESS);
	DrawString(100, 65, "戦闘艇、守護艇、飛行艇、偵察艇、高速艇の順でクリックしてください。\n", BLACKNESS);
	DrawString(100, 50, "真ん中の方に配置したい場合は高速でスライドして真ん中にカーソルをあててください。\n", BLACKNESS);

	/*int GHandle1;
	GHandle1 = LoadGraph("戦闘艇.png");
	*/
	/*
	SetDrawScreen(DX_SCREEN_FRONT);

	// マウスを表示状態にする
	SetMouseDispFlag(TRUE);
	//マウスの入力を待つ
	MouseInput = GetMouseInput();
	while ((MouseInput & MOUSE_INPUT_LEFT) == 0)
	{
		while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen())
		{
			GHandle0 = LoadGraphScreen(0, 0, "昼空.png", TRUE);
			//DrawExtendGraph(0, 0, 0 + 1522 * 0.6, 0 + 950 * 0.6, GHandle, TRUE);
			GHandle = LoadGraphScreen(100, 200, "マス空.png", TRUE);
			GHandle = LoadGraphScreen(700, 200, "マス空.png", TRUE);
			//DrawExtendGraph(100, 200, 0 + 130 * 2, 0 + 130 * 2, GHandle, TRUE);
			//DrawExtendGraph(400, 200, 0 + 130 * 2, 0 + 130 * 2, GHandle, TRUE);
			if (Flag0 == TRUE)
			{
				DrawGraph(pointX, pointY, GHandle1, FALSE);
			}

			//DrawBox(100, 50, 700, 200, Cr, TRUE);    // 四角形を描画
			DrawString(100, 50, "艇の初期配置をクリックで指定してください。\n", BLACKNESS);
			DrawString(100, 65, "戦闘艇、守護艇、飛行艇、偵察艇、高速艇の順でクリックしてください。\n", BLACKNESS);

			// マウスの位置を取得
			GetMousePoint(&MouseX, &MouseY);
			if (MouseInput & MOUSE_INPUT_LEFT) //マウスの左ボタンが押されていたら
				DrawString(0, 0, "左ボタンが押されています", GetColor(255, 255, 255));
			// メッセージ処理
			if (ProcessMessage() == -1)
			{
				break;
			}
			if (175 <= MouseX && MouseX <= 600 && 230 <= MouseY && MouseY <= 655)
			{
				if (175 <= MouseX && MouseX <= 260)
				{
					if (230 <= MouseY && MouseY <= 315)
					{
						// マウスの入力を得る
						if (MouseInput = GetMouseInput())
						{
							DrawGraph(175, 230, GHandle1, FALSE);
							pointX = 175;
							pointY = 230;
							Flag0 = TRUE;
							break;
						}
					}
				}
			}
		}
	}
	*/
	
	int GHandle1, GHandle2, GHandle3, GHandle4, GHandle5;
	GHandle1 = LoadGraph("戦闘艇.png");
	GHandle2 = LoadGraph("守護艇.png");
	GHandle3 = LoadGraph("飛行艇.png");
	GHandle4 = LoadGraph("偵察艇.png");
	GHandle5 = LoadGraph("高速艇.png");

	int point0[2], point1[2], point2[2], point3[2], point4[2];

	Haichi(GHandle1, &point0[0]);
	GHandle1 = LoadGraphScreen(point0[0], point0[1], "戦闘艇.png", TRUE);
	ScreenCopy();

	Haichi(GHandle2, &point1[0]);
	GHandle2 = LoadGraphScreen(point1[0], point1[1], "守護艇.png", TRUE);
	ScreenCopy();

	Haichi(GHandle3, &point2[0]);
	GHandle3 = LoadGraphScreen(point2[0], point2[1], "飛行艇.png", TRUE);
	ScreenCopy();

	Haichi(GHandle4, &point3[0]);
	GHandle4 = LoadGraphScreen(point3[0], point3[1], "偵察艇.png", TRUE);
	ScreenCopy();

	Haichi(GHandle5, &point4[0]);
	GHandle5 = LoadGraphScreen(point4[0], point4[1], "高速艇.png", TRUE);
	ScreenCopy();
	
	GHandle1 = LoadGraphScreen(point0[0], point0[1], "戦闘艇.png", TRUE);
	GHandle2 = LoadGraphScreen(point1[0], point1[1], "守護艇.png", TRUE);
	GHandle3 = LoadGraphScreen(point2[0], point2[1], "飛行艇.png", TRUE);
	GHandle4 = LoadGraphScreen(point3[0], point3[1], "偵察艇.png", TRUE);
	GHandle5 = LoadGraphScreen(point4[0], point4[1], "高速艇.png", TRUE);
	
	//int GHandle1;
	//GHandle1 = LoadGraphScreen(515, 570, "戦闘艇.png", TRUE);
	//GHandle1 = LoadGraphScreen(430, 485, "守護艇.png", TRUE);
	//GHandle1 = LoadGraphScreen(345, 400, "飛行艇.png", TRUE);
	//GHandle1 = LoadGraphScreen(260, 315, "偵察艇.png", TRUE);
	//GHandle1 = LoadGraphScreen(175, 230, "高速艇.png", TRUE);
	
	WaitKey();

	//ClearDrawScreen();

	GHandle = LoadGraph("夜空(高).png");
	DrawExtendGraph(0, 0, 0 + 3933 * 0.35, 0 + 2541 * 0.35 ,GHandle, TRUE);
	GHandle = LoadGraphScreen(100, 200, "マス空.png", TRUE);
	GHandle = LoadGraphScreen(700, 200, "マス空.png", TRUE);


	WaitKey();

	DxLib_End();                // ＤＸライブラリ使用の終了処理

	return 0;                // ソフトの終了
}

void Haichi(int GHandle, int* pT){

	int MouseX, MouseY;
	int MouseInput;
	int GrHandle;

	boolean Flag0 = FALSE;
	int pointX = 0;
	int pointY = 0;

	GetMousePoint(&MouseX, &MouseY);
	//マウスの入力を待つ
	MouseInput = GetMouseInput();
	while ((MouseInput & MOUSE_INPUT_LEFT) == 0)
	{
		//while (!ScreenCopy() && !ProcessMessage())
		//{
			//昼ステージ描画
			GrHandle = LoadGraphScreen(0, 0, "昼空.png", TRUE);
			GrHandle = LoadGraphScreen(100, 200, "マス空.png", TRUE);
			GrHandle = LoadGraphScreen(700, 200, "マス空.png", TRUE);
	
			//if (Flag0 == TRUE)
			//{
			//	DrawGraph(pointX, pointY, GHandle, TRUE);
			//}

			DrawString(100, 50, "艇の初期配置をクリックで指定してください。\n", BLACKNESS);
			DrawString(100, 70, "戦闘艇、守護艇、飛行艇、偵察艇、高速艇の順でクリックしてください。\n", BLACKNESS);

			// マウスの位置を取得
			GetMousePoint(&MouseX, &MouseY);

			// メッセージ処理
			if (ProcessMessage() == -1)
			{
				break;
			}
			// マウスの入力を得る
			MouseInput = GetMouseInput();
			if (175 <= MouseX && MouseX <= 600 && 230 <= MouseY && MouseY <= 655){
				//SetDrawScreen(DX_SCREEN_BACK);

				if (175 <= MouseX && MouseX <= 260){
					pointX = 175;
					if (230 <= MouseY && MouseY <= 315){
						DrawGraph(175, 230, GHandle, TRUE);
						pointY = 230;
						//Flag0 = TRUE;
						break;
					}
					else if (315 < MouseY && MouseY <= 400){
						DrawGraph(175, 315, GHandle, TRUE);
						pointY = 315;
						break;
					}
					else if (400 < MouseY && MouseY <= 485){
						DrawGraph(175, 400, GHandle, TRUE);
						pointY = 400;
						break;
					}
					else if (485 < MouseY && MouseY <= 570){
						DrawGraph(175, 485, GHandle, TRUE);
						pointY = 485;
						break;
					}
					else{
						DrawGraph(175, 570, GHandle, TRUE);
						pointY = 570;
						break;
					}
				}
				else if (260 < MouseX && MouseX <= 345)
				{
					pointX = 260;
					if (230 <= MouseY && MouseY <= 315)
					{
						DrawGraph(260, 230, GHandle, TRUE);
						pointY = 230;
						break;
					}
					else if (315 < MouseY && MouseY <= 400){
						DrawGraph(260, 315, GHandle, TRUE);
						pointY = 315;
						break;
					}
					else if (400 < MouseY && MouseY <= 485){
						DrawGraph(260, 400, GHandle, TRUE);
						pointY = 400;
						break;
					}
					else if (485 < MouseY && MouseY <= 570){
						DrawGraph(260, 485, GHandle, TRUE);
						pointY = 485;
						break;
					}
					else{
						DrawGraph(260, 570, GHandle, TRUE);
						pointY = 570;
						break;
					}
				}
				else if (345 < MouseX && MouseX <= 430)
				{
					pointX = 345;
					if (230 <= MouseY && MouseY <= 315)
					{
						DrawGraph(345, 230, GHandle, TRUE);
						pointY = 230;
						break;
					}
					else if (315 < MouseY && MouseY <= 400){
						DrawGraph(345, 315, GHandle, TRUE);
						pointY = 315;
						break;
					}
					else if (400 < MouseY && MouseY <= 485){
						DrawGraph(345, 400, GHandle, TRUE);
						pointY = 400;
						break;
					}
					else if (485 < MouseY && MouseY <= 570){
						DrawGraph(345, 485, GHandle, TRUE);
						pointY = 485;
						break;
					}
					else{
						DrawGraph(345, 570, GHandle, TRUE);
						pointY = 570;
						break;
					}
				}
				else if (430 < MouseX && MouseX <= 515)
				{
					pointX = 430;
					if (230 <= MouseY && MouseY <= 315)
					{
						DrawGraph(430, 230, GHandle, TRUE);
						pointY = 230;
						break;
					}
					else if (315 < MouseY && MouseY <= 400){
						DrawGraph(430, 315, GHandle, TRUE);
						pointY = 315;
						break;
					}
					else if (400 < MouseY && MouseY <= 485){
						DrawGraph(430, 400, GHandle, TRUE);
						pointY = 400;
						break;
					}
					else if (485 < MouseY && MouseY <= 570){
						DrawGraph(430, 485, GHandle, TRUE);
						pointY = 485;
						break;
					}
					else{
						DrawGraph(430, 570, GHandle, TRUE);
						pointY = 570;
						break;
					}
				}
				else if (515 < MouseX && MouseX <= 600)
				{
					pointX = 515;
					if (230 <= MouseY && MouseY <= 315)
					{
						DrawGraph(515, 230, GHandle, TRUE);
						pointY = 230;
						break;
					}
					else if (315 < MouseY && MouseY <= 400){
						DrawGraph(515, 315, GHandle, TRUE);
						pointY = 315;
						break;
					}
					else if (400 < MouseY && MouseY <= 485){
						DrawGraph(515, 400, GHandle, TRUE);
						pointY = 400;
						break;
					}
					else if (485 < MouseY && MouseY <= 570){
						DrawGraph(515, 485, GHandle, TRUE);
						pointY = 485;
						break;
					}
					else{
						DrawGraph(515, 570, GHandle, TRUE);
						pointY = 570;
						break;
					}
				}
			}
	//	}
	}
	pT[0] = pointX;
	pT[1] = pointY;
}